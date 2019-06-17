#include "GomokuUI.h"
#include "GomokuAI.h"
#define PLAYER_N 1

#ifdef OUTPUT_CALCULATE_TIME
int startTime;
int tot;
int endTime;
#endif // OUTPUT_CALCULATE_TIME

const string pieceIcon[] = { " ", "O","X","+","?", "o","x"};
//use when output
//'+' means the pointer, '?' means sth is wrong with it.
int board[BOARD_SIZE][BOARD_SIZE];
int pieceN;

pointStruct operator * (const int multiple, const pointStruct & b)
{
	return pointStruct(multiple * b.column, multiple * b.row);
}

void initializeProgram()
{
	srand((unsigned)time(NULL));
}

void initializeBoard()
{
	memset(board, 0, sizeof(board));
	pieceN = 0;
}

int welcome() //if player goes first returns 1, else returns 2 (AI first);
{
	char playFirst;
	system("cls");
	cout << "Welcome to Gomoku Games!" << endl
		<< "If you want to play first, input 1, otherwise input 0: ";
	cin >> playFirst;
	while (playFirst != '0' &&playFirst != '1')
	{
		cout << "Wrong input.\n";
		cin >> playFirst;
	}
	cout << "You are going to play " << (playFirst== '1' ? "First" : "Second") << ". Take it easy." << endl;
	system("pause");
	return (playFirst == '1' ? 1 : 2);
}

int runGame() //"The Judger"
{	
	initializeBoard();
	pointStruct curPoint = { BOARD_SIZE/2 ,BOARD_SIZE/2 }; //pointer are at center at first
	int winStatus;
	int curPlayer = welcome();
	do
	{
		curPoint = someonePutPiece(curPlayer, curPoint);
		pieceN++;
		curPlayer = (curPlayer == 1) ? 2 : 1;
	} while ((winStatus = gameOver(curPoint))==0);

	printBoard();
	if (winStatus == 1)
	{
		cout << "You win!!!! Good Job!\n\n";
	}
	else if (winStatus == 2)
	{
		cout << "You lose... Keep it up!\n\n";
	}
	else if (winStatus == 3)
	{
		cout << "It's a draw.\n\n";
	}
	system("pause");
	return winStatus;
}


void printBoard()
{
	pointStruct p;
	system("cls");
#ifdef PRINT_COLOMN_AND_ROW_NUMBER
	cout << " ";
	for (int i = 0; i < BOARD_SIZE; i++)
		cout << i % 10;
	cout << endl;
#endif

	for (p.column = 0; p.column < BOARD_SIZE; p.column++)
	{
#ifdef PRINT_COLOMN_AND_ROW_NUMBER
		cout << p.column % 10;
#endif
		for (p.row = 0; p.row < BOARD_SIZE; p.row++)
		{
			cout << p.getChar();
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < BOARD_SIZE; i++)
		cout << "-";
	cout << endl;

#ifdef OUTPUT_CALCULATE_TIME
	if (pieceN > 1)
		cout << "\nCalculate " << tot << " times in " << double(endTime-startTime) / CLOCKS_PER_SEC << "s.\n\n";
#endif // OUTPUT_CALCULATE_TIME

}

pointStruct someonePutPiece(int someone, pointStruct point)
{
	if (someone == PLAYER_VALUE || PLAYER_N == 2)
		return playerPutPiece(someone, point);
	else
		return AIPutPiece(point);
}

pointStruct playerPutPiece(int player, pointStruct curPoint) // move pointer to choose where to put c
{
	curPoint = putPieceAnyway(curPoint,POINTER_VALUE);
	int choice = 1;
	while (choice != 5)
	{
		pointStruct dir;
		printBoard();
		cout << R"str("O" is your piece, and "X" is AI's piece.)str" << endl
			<< "Please use asdw to move, and press p to put.";
		choice = system("choice /c asdwp");//a3 s6 d4 w1
		if (choice == 1) dir = { 0,-1 };
		else if (choice == 2) dir = { 1,0 };
		else if (choice == 3) dir = { 0,1 };
		else if (choice == 4) dir = { -1, 0 };
		else
		{
			break;
		}
		curPoint.removePiece();
		curPoint = curPoint + dir;
		curPoint = putPieceAnyway(curPoint, dir, POINTER_VALUE);
	}
#ifdef DEBUG
	if (curPoint.putPiece(player) == false)
	{
		cout << "Detected Wrong.\n";
		system("pause");
	}
#else
	curPoint.putPiece(player);
#endif
	return curPoint;
}

int gameOver(pointStruct p) // 0: game not end; 1, 2: player win; 3: a draw.
{
#ifdef DEBUG_PIECE_IN_LINE
	cout << "Now it's time to judge whether the game is over;\n";
#endif
	if (pieceN == BOARD_SIZE * BOARD_SIZE)
	{
		return 3;
	}
	for (int d = 0; d < 4; d++) //check if there is 5 same piece in one line
	{
		if (continousPieceNInLine(p, dire[d]) >= 5)
		{
			if (p.getChar() == pieceIcon[1])
				return 1;
			else if (p.getChar() == pieceIcon[2])
				return 2;
			else
			{
				printBoard();
				cout << "Error!\n";
				system("pause");
			}
		}
	}
	return 0;
}