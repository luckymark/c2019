#include "GomokuAI.h"
#include<iostream>
#include<Windows.h>
#include<set>


choiceTreeNode * DFSChoiceTreeNode(int curDepth, choiceTreeNode * lastTreeNode);
choiceTreeNode * createChoiceTreeNode(pointStruct curPoint);
choiceTreeNode * addChoiceTreeNode(pointStruct curPoint, choiceTreeNode * lastTreeNode);
void moveChoiceTreeRootNode(choiceTreeNode * newRoot);
void deleteChoiceTreeNode(choiceTreeNode * node);
void moveChoiceTreeRootNode(pointStruct newPoint);

//choiceTreeNode * getGoodChoice(choiceTreeNode * lastNode);
void getGoodChoiceForAI(choiceTreeNode *lastTreeNode, pointStruct startPoint, choiceTreeNode * (&goodChoice), int & goodChoiceScore, int curDepth);
void getGoodChoiceForPlayer(choiceTreeNode * lastTreeNode, pointStruct startPoint, choiceTreeNode * (&goodChoice), int & goodChoiceScore, int curDepth);

void pieceNInDirectedLine(const pointStruct p, const pointStruct dir, int (&len)[MAX_CALCULATE_SCORE_LENGTH], const int lenAdd)
//in directed line
{
	int curlen = MAX_CALCULATE_SCORE_LENGTH / 2;
	pointStruct cur = p + dir;
	while (cur.valid())
	{
		if (cur.getValue()%4 == p.getValue()%4)
		//mod 4 is that whitePiece(value:1) and whiteTempPiece(in choice-tree, value:5) should be same
		{
			if (len[curlen] == -1)
				len[curlen] = 1;
			else
				len[curlen]++;
			if (len[curlen/2] == 5)
				break;
		}
		else if (cur.getValue() == SPACE_VALUE)
		{
			if (len[curlen] == -1)
				len[curlen] = 0;
			if (curlen == 0 || curlen == MAX_CALCULATE_SCORE_LENGTH - 1)
				return;
			curlen += lenAdd;
		}
		else break;
		cur = cur + dir;
	}
}

void pieceNInLine(pointStruct p, pointStruct dir, int (&len)[MAX_CALCULATE_SCORE_LENGTH])
//in two direction
{
	// len[0], len[2] have exactly a space to len[1]
	//i. e. xoooo ooo ox, len == {-1, 4, 3, 1, -1};

	/*usage:
		int len[maxLength];
		pieceNInLine(p, dir, len);
		...
	*/

	//initalize len[] = { -1,-1,1,-1,-1 };
#ifdef OUTPUT_CALCULATE_TIME
	extern int tot;
	tot++;
#endif // OUTPUT_CALCULATE_TIME
	for (int i = 0; i < MAX_CALCULATE_SCORE_LENGTH; i++)
		len[i] = -1;
	len[MAX_CALCULATE_SCORE_LENGTH / 2] = 1;

	pieceNInDirectedLine(p, dir, len, 1);
	pieceNInDirectedLine(p, -dir, len, -1);
	if (len[MAX_CALCULATE_SCORE_LENGTH / 2] < len[MAX_CALCULATE_SCORE_LENGTH / 2 - 1])
	{
		pieceNInLine(p-dir, dir, len);
	}
	if (len[MAX_CALCULATE_SCORE_LENGTH / 2] < len[MAX_CALCULATE_SCORE_LENGTH / 2 + 1])
	{
		pieceNInLine(p+dir, dir, len);
	}
#ifdef DEBUG_PIECE_IN_LINE
	cout << "piece in line at (" << p.row << "," << p.column << ")"
		<< " at dir (" << dir.row << "," << dir.column << "): ";
	for (int i = 0; i < MAX_CALCULATE_SCORE_LENGTH; i++)
	{
		cout << len[i] << " ";
	}
	cout << endl;
	system("pause>nul");
#endif 
}

int continousPieceNInLine(pointStruct p, pointStruct dir)
{
	int len[MAX_CALCULATE_SCORE_LENGTH] = { 0 };
	pieceNInLine(p, dir, len);
	return len[MAX_CALCULATE_SCORE_LENGTH/2];
}

//refer to score_table.png
#define WINNER_SCORE 50000
#define APPROX_WINNER_SCORE 40000 //can be seen as winner
const int scoreTableLength = 15;
const int scoreTable[scoreTableLength][MAX_CALCULATE_SCORE_LENGTH+1] = {
{-1,-1,5,-1,-1,50000},//1
{-1,0,4,0,-1,4320},//2
{0,0,3,0,-1,720},//3
{-1,0,3,0,0,720},//4
{-1,0,2,1,0,720},//5
{-1,1,2,0,0,720},//6
{-1,-1,4,0,-1,720},//7
{-1,0,4,-1,-1,720},//8
{-1,2,2,-1,-1,720},//9
{-1,1,3,-1,-1,720},//10
{-1,-1,3,1,-1,720},//11
{0,0,2,0,0,120},//12
{0,0,1,1,0,120},//13
{0,1,1,0,0,120},//14
{0,0,1,0,0,20},//15,16
};

int calculateScore(pointStruct p)
{
	int score = 0;
	for (int direIndex = 0; direIndex < 4; direIndex++)
	{
		int len[MAX_CALCULATE_SCORE_LENGTH];
		pieceNInLine(p, dire[direIndex],len);
		for (int curScoreTableRow = 0; curScoreTableRow < scoreTableLength; curScoreTableRow++)
		{
			bool satisfy = true;
			for (int i = 0; i < MAX_CALCULATE_SCORE_LENGTH; i++)
			{
				if (len[i] < scoreTable[curScoreTableRow][i])
				{
					satisfy = false;
					break;
				}
			}
			if (satisfy)
			{
				score += scoreTable[curScoreTableRow][MAX_CALCULATE_SCORE_LENGTH];
				break;
			}
		}
	}
#ifdef DEBUG_CALCULATE_SCORE
	cout << "score at (" << p.row << "," << p.column << "): "<< score << "\n";
#endif 
	return score;
}

int choiceTreeNode::score()
{
	bool putNewPiece = point.putPiece(playerPiece + 4);
	int score =  calculateScore(point);
	if (putNewPiece)
		point.removePiece();
	return score;
}

//pointStruct AIPutPiece(pointStruct lastPoint) //version1: at random
//{
//#ifdef DEBUG_PIECE_IN_LINE
//	cout << "Now it's AI's turn\n";
//#endif
//	for (int rad = 1; rad <= 3; rad++) //search for neighbor spaces
//	{
//		set<int> used_direction;
//		while(used_direction.size()!=8)
//		{
//			int direIndex = rand() % 8;
//			if (used_direction.find(direIndex)!= used_direction.end())
//				continue;
//			used_direction.insert(direIndex);
//			pointStruct temp = rad * dire[direIndex] + lastPoint;
//			if (temp.canPutHere())
//			{
//				temp.putPiece(AI_VALUE);
//				pieceN++;
//#ifdef DEBUG_CALCULATE_SCORE
//				calculateScore(temp);
//#endif // DEBUG_
//				return temp;
//			}
//		}
//	}
//	putPieceAnyway(lastPoint, AI_VALUE);
//#ifdef DEBUG_CALCULATE_SCORE
//	calculateScore(lastPoint);
//#endif // DEBUG_
//	pieceN++;
//	return lastPoint;
//}

//pointStruct AIPutPiece(pointStruct lastPoint) //version2: with a 1-depth choiceTree, search in a 5*5 range
//{
//	choiceTreeNode * lastTreeNode = createChoiceTreeNode(lastPoint);
//	for (int direIndex = 0; direIndex < 8; direIndex++)
//	{
//		pointStruct curPoint = lastPoint;
//		for (int i = 1; i <= 2; i++) //search in a 5*5 range
//		{
//			curPoint = curPoint + dire[direIndex];
//			addChoiceTreeNode(curPoint, lastTreeNode);
//		}
//	}
//	if (lastTreeNode->nextTreeNode.empty())
//		putPieceAnyway(lastPoint, AI_VALUE);
//	choiceTreeNode * maxScore = getGoodChoice(lastTreeNode);
//	maxScore->point.putPiece(AI_VALUE);
//	return maxScore->point;	
//}

choiceTreeNode * choiceTreeLastNode = NULL, * choiceTreeRootNode = NULL;

pointStruct AIPutPiece(pointStruct lastPoint) //version3: with a n-depth choiceTree, search in a 5*5 range
{
#ifdef OUTPUT_CALCULATE_TIME
	extern int tot;
	tot = 0;
	extern int startTime;
	startTime= clock();
#endif // OUTPUT_CALCULATE_TIME

	extern int pieceN;
	if (pieceN == 0)
	{
		pointStruct firstPoint = { BOARD_SIZE / 2, BOARD_SIZE / 2 };
		firstPoint.putPiece(AI_VALUE);
		return firstPoint;
	}

	if (choiceTreeLastNode == NULL)
		choiceTreeRootNode = choiceTreeLastNode = createChoiceTreeNode(lastPoint);
	else
		moveChoiceTreeRootNode(lastPoint);
	choiceTreeNode * goodChoice = DFSChoiceTreeNode(0, choiceTreeLastNode);
	pointStruct decisionPoint;
	if (goodChoice != NULL && goodChoice->score() != 0) // if the score is 0, it's better to put in another point
	{
		while (goodChoice->fatherTreeNode != choiceTreeLastNode)
			goodChoice = goodChoice->fatherTreeNode;
		goodChoice->point.putPiece(AI_VALUE);
		decisionPoint = goodChoice->point;
	}
	else
	{
		decisionPoint = putPieceAnyway(lastPoint, AI_VALUE);
		addChoiceTreeNode(decisionPoint, choiceTreeLastNode);
	}
	moveChoiceTreeRootNode(decisionPoint);


#ifdef OUTPUT_CALCULATE_TIME
	extern int endTime;
	endTime = clock();
#endif // OUTPUT_CALCULATE_TIME

	return decisionPoint;
}

pointStruct putPieceAnyway(pointStruct & startPoint, int value) //directed modify 'point' to next step
{
	pointStruct curPoint = startPoint;
	while (!curPoint.canPutHere())
	{
		curPoint.column++;
		if (curPoint.column >= BOARD_SIZE)
		{
			curPoint.column = 0;
			curPoint.row++;
			if (curPoint.row >= BOARD_SIZE)
			{
				curPoint.row = 0;
			}
		}
		if (curPoint == startPoint)
		{
			cout << "Wrong in Function putPieceAnyway()\n";
			system("pause");
		}
	}
	curPoint.putPiece(value);
	return curPoint;
}

pointStruct putPieceAnyway(pointStruct & startPoint, pointStruct dir, int value) //given direction
{
	pointStruct curPoint = startPoint;
	while (!curPoint.canPutHere())
	{
		if (!curPoint.valid())
		{
			return putPieceAnyway(startPoint, value);
		}
		curPoint = curPoint + dir;
	}
	curPoint.putPiece(value);
	return curPoint;
}

choiceTreeNode * DFSChoiceTreeNode(int curDepth, choiceTreeNode * lastTreeNode)
{
	if (lastTreeNode == NULL)
		return NULL;
	if (curDepth > MAX_TREE_DEPTH)
		return lastTreeNode;
	if (curDepth > 0)
		lastTreeNode->point.putPiece(lastTreeNode->playerPiece + 4);//must check validity before use

	int curPlayerPieceValue = AI_VALUE + PLAYER_VALUE - lastTreeNode->playerPiece; //switch

	choiceTreeNode * goodAIChoice = NULL;
	int goodChoiceScore = 0;
	if (curPlayerPieceValue == AI_VALUE)
	{
		//search a good choice in a PRIDICT_PIECE_RANGE * PRIDICT_PIECE_RANGE range around last 2 pieces
		getGoodChoiceForAI(lastTreeNode, lastTreeNode->point, goodAIChoice, goodChoiceScore, curDepth);
		choiceTreeNode * recursionStartTreeNode = lastTreeNode;
		for (int i = 1; i <= START_POINT_RECURSION_DEPTH; i++)
		{
			if (recursionStartTreeNode->fatherTreeNode == NULL)
				break;
			recursionStartTreeNode = recursionStartTreeNode->fatherTreeNode;
			getGoodChoiceForAI(lastTreeNode, recursionStartTreeNode->point, goodAIChoice, goodChoiceScore, curDepth);

		}
	}
	else //(curPlayerPieceValue == PLAYER_VALUE)
	{
		choiceTreeNode * bestPlayerChoice = NULL;
		getGoodChoiceForPlayer(lastTreeNode, lastTreeNode->point, bestPlayerChoice, goodChoiceScore, curDepth);
		choiceTreeNode * recursionStartTreeNode = lastTreeNode;
		for (int i = 1; i <= START_POINT_RECURSION_DEPTH; i++)
		{
			if (recursionStartTreeNode->fatherTreeNode == NULL)
				break;
			recursionStartTreeNode = recursionStartTreeNode->fatherTreeNode;
			getGoodChoiceForPlayer(lastTreeNode, recursionStartTreeNode->point, bestPlayerChoice, goodChoiceScore, curDepth);

		}
		goodAIChoice = DFSChoiceTreeNode(curDepth + 1, bestPlayerChoice);
	}

	lastTreeNode->point.removePiece();
	return goodAIChoice;
}

choiceTreeNode * createChoiceTreeNode(pointStruct curPoint) //base on an existed point
{
	auto * curNode = new choiceTreeNode;
	curNode->fatherTreeNode = NULL;
	curNode->point = curPoint;
	curNode->playerPiece = curPoint.getValue();
	return curNode;
}

choiceTreeNode * addChoiceTreeNode(pointStruct curPoint, choiceTreeNode * lastTreeNode)
{
	if (!curPoint.canPutHere())
		return NULL;
	for (auto curNode : lastTreeNode->nextTreeNode)
	{
		if (curNode->point == curPoint)
			return curNode;
	}
	choiceTreeNode * curNode = new choiceTreeNode;
	lastTreeNode->nextTreeNode.insert(curNode);

	curNode->playerPiece = AI_VALUE + PLAYER_VALUE - lastTreeNode->playerPiece; //switch
	curNode->point = curPoint;
	curNode->fatherTreeNode = lastTreeNode;
	return curNode;
}

void moveChoiceTreeRootNode(choiceTreeNode * newRoot)
{
	for (auto curNode : choiceTreeLastNode->nextTreeNode)
	{
		if (curNode == newRoot)
		{
			for (auto delNode : choiceTreeLastNode->nextTreeNode)
			{
				if (delNode != curNode)
				{
					deleteChoiceTreeNode(delNode);
				}
			}
			choiceTreeLastNode = curNode;
			return;
		}
	}
}

void moveChoiceTreeRootNode(pointStruct newPoint)
{
	for (auto curNode : choiceTreeLastNode->nextTreeNode)
	{
		if (curNode->point == newPoint)
		{
			for (auto delNode : choiceTreeLastNode->nextTreeNode)
			{
				if (delNode != curNode)
				{
					deleteChoiceTreeNode(delNode);
				}
			}
			choiceTreeLastNode = curNode;
			return;
		}
	}
}

void deleteChoiceTreeNode(choiceTreeNode * node)
{
	for (choiceTreeNode * iter : node->nextTreeNode)
	{
		deleteChoiceTreeNode(iter);
	}
	delete node;
}

//choiceTreeNode * getGoodChoice(choiceTreeNode * lastNode)
//{
//	if (lastNode->nextTreeNode.empty())
//		return NULL;
//	choiceTreeNode * maxNode = *lastNode->nextTreeNode.begin();
//	for (choiceTreeNode * iter : lastNode->nextTreeNode)
//	{
//		if (iter->score > maxNode->score)
//			maxNode = iter;
//	}
//	return maxNode;
//}

//AI will recurse every choice and decide which is the best, 
//while player choose the best choice first, and then recurse from it. 
void getGoodChoiceForAI(choiceTreeNode *lastTreeNode, pointStruct startPoint,choiceTreeNode * (&goodChoice), int & goodChoiceScore, int curDepth)
{
#ifdef SEARCH_FOR_WHOLE_BOARD
	pointStruct curPoint;
	for (curPoint.column = 0; curPoint.column < BOARD_SIZE; curPoint.column++)
	{
		for (curPoint.row = 0; curPoint.row < BOARD_SIZE; curPoint.row++)
		{
#else //search in a PRIDICT_PIECE_RANGE * PRIDICT_PIECE_RANGE range
	for (int i = 1; i <= PRIDICT_PIECE_RANGE / 2; i++) 
	{
		for (int direIndex = 0; direIndex < 8; direIndex++)
		{
			pointStruct curPoint = startPoint + i * dire[direIndex];
#endif
			choiceTreeNode * curTreeNode = addChoiceTreeNode(curPoint, lastTreeNode);
			if (curTreeNode == NULL)
				continue;

			choiceTreeNode * curChoice = DFSChoiceTreeNode(curDepth + 1, curTreeNode);
			if (curChoice == NULL)
				continue;
			int curChoiceScore;
			if ((curChoiceScore = curChoice->score()) >= 50000)
			{
				goodChoice = curChoice;
				goodChoiceScore = curChoiceScore;
#ifdef  DEBUG_SCORE_CALCULATE2
				goodChoice->point.putPiece(AI_TEMP_VALUE);
				printBoard();
				cout << pieceIcon[goodChoice->playerPiece] << " : " << goodChoice->score() << endl;
				cout << pieceIcon[goodChoice->fatherTreeNode->playerPiece] << " : " << goodChoice->fatherTreeNode->score() << endl;
				goodChoice->point.removePiece();
				Sleep(100);
#endif
				return;
			}
			curChoiceScore = curTreeNode->score() - curTreeNode->fatherTreeNode->score();
			if (goodChoice == NULL || curChoiceScore > goodChoiceScore)
			{
				goodChoiceScore = curTreeNode->score() - curTreeNode->fatherTreeNode->score();
				goodChoice = curChoice;
#ifdef  DEBUG_SCORE_CALCULATE2
				if (curDepth > 2 && curDepth <= 4)
				{
//					if (goodChoiceScore > 4000)
					{
						goodChoice->point.putPiece(AI_TEMP_VALUE);
						printBoard();
						cout << pieceIcon[goodChoice->playerPiece] << " : " << goodChoice->score() << endl;
						cout << pieceIcon[goodChoice->fatherTreeNode->playerPiece] << " : " << goodChoice->fatherTreeNode->score() << endl;
						cout << "minus = " << goodChoice->score() - goodChoice->fatherTreeNode->score() << "\n";
						goodChoice->point.removePiece();
					}
				}
#endif
			}
		}
	}
}

void getGoodChoiceForPlayer(choiceTreeNode * lastTreeNode, pointStruct startPoint, choiceTreeNode * (&goodChoice), int & goodChoiceScore, int curDepth)
{
	if (goodChoice == NULL && goodChoiceScore <= -WINNER_SCORE)
		return;

#ifdef SEARCH_FOR_WHOLE_BOARD
	pointStruct curPoint;
	for (curPoint.column = 0; curPoint.column < BOARD_SIZE; curPoint.column++)
	{
		for (curPoint.row = 0; curPoint.row < BOARD_SIZE; curPoint.row++)
		{
#else //search in a PRIDICT_PIECE_RANGE * PRIDICT_PIECE_RANGE range
	for (int i = 1; i <= PRIDICT_PIECE_RANGE / 2; i++)
	{
		for (int direIndex = 0; direIndex < 8; direIndex++)
		{
			pointStruct curPoint = startPoint + i * dire[direIndex];
#endif
			choiceTreeNode * curTreeNode = addChoiceTreeNode(curPoint, lastTreeNode);
			if (curTreeNode == NULL)
				continue;
			int curChoiceScore;
			if (goodChoice == NULL ||
				(curChoiceScore = curTreeNode->fatherTreeNode->score() - curTreeNode->score()) < goodChoiceScore)
			{
				if (goodChoice == NULL)
				{
					goodChoiceScore = curTreeNode->fatherTreeNode->score() - curTreeNode->score();
				}
				else
				{
					goodChoiceScore = curChoiceScore;
				}
				if (goodChoiceScore <= -APPROX_WINNER_SCORE)
				{
					goodChoice = NULL;
					goodChoiceScore = -WINNER_SCORE;
					return;
				}

				goodChoice = curTreeNode;
#ifdef  DEBUG_SCORE_CALCULATE2
				if (curDepth <= 2)
				{
					goodChoice->point.putPiece(PLAYER_TEMP_VALUE);
					printBoard();
					cout << pieceIcon[goodChoice->playerPiece] << " : " << goodChoice->score() << endl;
					cout << pieceIcon[goodChoice->fatherTreeNode->playerPiece] << " : " << goodChoice->fatherTreeNode->score() << endl;
					goodChoice->point.removePiece();
				}
#endif
			}
		}
	}
	if (goodChoice == NULL && goodChoiceScore > -APPROX_WINNER_SCORE)// there's no way to put, not "absolutely lose"
	{
		pointStruct curPoint = putPieceAnyway(startPoint, PLAYER_TEMP_VALUE);
		curPoint.removePiece();
		goodChoice = addChoiceTreeNode(curPoint, lastTreeNode);
	}
}