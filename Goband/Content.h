#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
 

int Board[15][15] = {0};//棋盘 
int PersonalStone;   //1 黑棋 2 白棋 
int CursorX, CursorY; //光标位置 
int Count;//步数 
void DrawBoard();  //画棋盘 
char* Get(int x,int y); //辅助画棋盘 
int Put();  //玩家下棋 
int RunGame(); //五子棋运行 
void Initialize();  //初始化 
void Back();  //悔棋，每次仅能悔棋一步 


int PosValue[15][15]  = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
	{0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
	{0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
	{0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
	{0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
	{0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
	{0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
	{0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
	{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};//棋子位置自身价值 
int HistoryHeuristic[15][15];//记录棋子位置自身价值 
int TypeRecord[15][15][4]; //棋盘一点所能构成的棋型 
int LineRecord[20]; //记录10种棋型 
int TypeCount[3][10];//存储棋子10种五子棋棋型对应的数量 
void ResetHistoryTable();//重置棋子自身价值 
int Result(int i,int j,int Count);//判断结果 
int Eveluate(int CurrentStone);//评分 
int AnalysisHorizon(int i,int j);//分析水平棋型 
int AnalysisVertical(int i,int j);//分析竖直棋型 
int AnalysisLeft(int i,int j);//分析左斜棋型 
int AnalysisRight(int i,int j);//分析右斜棋型 
int AnalysisLine(int Line[],int Num,int Pos);//分析给定行上某点及其周边的棋型


struct move{
	int r;	//棋子的行 
	int c;	//棋子的列 
	int v;  //棋子的价值 
}MoveList[10][225]; 
int CreatePossibleMove( int depth,int Count); // 配合 α-β剪枝 
int MoveCount;//搜索时步数记录 
void Sort(int depth, int movecount); //价值排序 

void ComputerDownStone(); //电脑下棋 
int AlphaBeta(int depth, int CurrentStone, int alpha, int beta);//α-β剪枝 
int SearchDepth; //搜索深度 
int row; //电脑行 
int column; //电脑列 
int ComputerStone; //电脑棋子颜色 

int RunGame()
{
	Initialize();
	int Input;
	int First; 
	int result;
	printf("输入数字选择电脑难度：2.初级 4.高级");
	scanf("%d",&SearchDepth); 
	printf("输入数字选择先手：1.玩家先手 2.电脑先手 ");
	scanf("%d",&First);
	if(First == 1){
		PersonalStone = 1;
		ComputerStone = 2;
		while(1){
			DrawBoard();
			Input = getch();
			switch(Input){
				case 27:
					exit(0);
					break;
					case 224:
					{	
						Input = getch();
						switch(Input)
						{
							case 72: CursorX--;break;
							case 80: CursorX++;break;
							case 75: CursorY--;break; 
							case 77: CursorY++;break;
						}
						if(CursorX<0){CursorX=14;}
						if(CursorX>BoardSize){CursorX=0;}
						if(CursorY>BoardSize){CursorY=0;}
						if(CursorY<0){CursorY=14;}
						break;
					}
				case 32:
				{
					if(Put()){
						DrawBoard();
						result = Result(CursorX,CursorY,Count);
						if(result == 1){
							MessageBox(0,TEXT("黑棋获得胜利"),TEXT("结果"),NULL);
							exit(0);
						}
						else if(result == 2){
							MessageBox(0,TEXT("比赛平局"),TEXT("结果"),NULL);
						}
						ComputerDownStone();
						result = Result(row,column,Count);
						if(result == 1){
							MessageBox(0,TEXT("白棋获得胜利"),TEXT("结果"),NULL);
							exit(0);
						}
						else if(result == 2){
							MessageBox(0,TEXT("比赛平局"),TEXT("结果"),NULL);
						}
					}
					break;
				}
				case 98:
				{
					Back();
					break;
				}
				
			}	

		}
	}
	else{
		PersonalStone = 2;
		ComputerStone = 1;
		DrawBoard();
		ComputerDownStone();
		while(1){
			DrawBoard();
			Input = getch();
			switch(Input){
				case 27:
					exit(0);
					break;
					case 224:
					{	
						Input = getch();
						switch(Input)
						{
							case 72: CursorX--;break;
							case 80: CursorX++;break;
							case 75: CursorY--;break; 
							case 77: CursorY++;break;
						}
						if(CursorX<0){CursorX=14;}
						if(CursorX>BoardSize){CursorX=0;}
						if(CursorY>BoardSize){CursorY=0;}
						if(CursorY<0){CursorY=14;}
						break;
					}
				case 32:
				{
					if(Put());{
						DrawBoard();
						result = Result(CursorX,CursorY,Count);
						if(result == 1){
							MessageBox(0,TEXT("白棋获得胜利"),TEXT("结果"),NULL);
							exit(0);
						}
						else if(result == 2){
							MessageBox(0,TEXT("比赛平局"),TEXT("结果"),NULL);
						}
						ComputerDownStone();
						result = Result(row,column,Count);
						if(result == 1){
							MessageBox(0,TEXT("黑棋获得胜利"),TEXT("结果"),NULL);
							exit(0); 
						}
						else if(result == 2){
							MessageBox(0,TEXT("比赛平局"),TEXT("结果"),NULL);
						}
						
					}
					break;
				}
				
				case 98:
				{
					Back();
					break;
				}
				
			}	
			
		}
	}
} 

void Initialize()
{
	CursorX = BoardSize / 2;
	CursorY = BoardSize / 2;
	Count = 0;
}

void DrawBoard()
{
	system("cls");
	for(int i = 0;i < BoardSize;i++){
		for(int j = 0;j < BoardSize;j++){
			printf(Get(i,j)); 
		}
		printf("\n");
		printf("\n");
	}	
	printf("上下左右移动光标，空格下棋，'b'悔棋");		
}

char* Get(int x,int y)
{
	if(Board[x][y] == 2)
		return " ● "; 
	else if(Board[x][y] == 1)
		return " ○ "; 
	else if(x == CursorX && y == CursorY)
		return " ╬  ";
	else if(x == 0&&y == 0)
		return " ┌  ";
	else if(x == BoardSize-1&&y == 0)
		return " └  ";
	else if(x == BoardSize-1&&y == BoardSize-1)
		return " ┘  ";
	else if(x == 0&&y == BoardSize-1)
		return " ┐  ";	
	else if(x == 0)
		return " ┬  ";
	else if(x == BoardSize-1)
		return " ┴  ";
	else if(y == 0)
		return " ├  ";
	else if(y == BoardSize-1)
		return " ┤  ";
	else 
		return " ┼  ";
}

int Put() 
{
	if(Board[CursorX][CursorY] == 0)
	{
		Board[CursorX][CursorY] = PersonalStone;
		return 1;
	}
	else
		return 0;
}

void Back()
{
	Board[CursorX][CursorY] = 0;
	Board[row][column] = 0; 
	Count = Count - 2;
	DrawBoard;
} 
 
 
 
 
void ResetHistoryTable()
{
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++) {
    	HistoryHeuristic[i][j]= PosValue[i][j];
		}
    }
}

int Result(int i,int j,int Count)
{
    if (AnalysisHorizon( i, j) == 7 || AnalysisVertical( i, j) == 7 || AnalysisLeft(i, j) == 7 || AnalysisRight(i, j) == 7)
        return 1;
    if (Count == 225) return 2;
    
    return 3;
	
}

int Eveluate(int CurrentStone)
{
            for (int i = 0; i < 15; i++){
            	for (int j = 0; j < 15; j++){
            		for (int k = 0; k < 4; k++){
            			TypeRecord[i][j][k] = 0;
            			
					}
				}
			}
            for (int i = 0; i < 3; i++){
            	for (int j = 0; j < 10; j++){
				 	TypeCount[i][j] = 0;
				}
			} 
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    if (Board[i][j] != 0)
                    {
                        if (TypeRecord[i][j][0] == 0) AnalysisHorizon(i, j);
                        if (TypeRecord[i][j][1] == 0) AnalysisVertical(i, j);
                        if (TypeRecord[i][j][2] == 0) AnalysisLeft(i, j);
                        if (TypeRecord[i][j][3] == 0) AnalysisRight(i, j);
                    }
                }
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (Board[i][j] != 0 && TypeRecord[i][j][k] > 0) TypeCount[Board[i][j]][TypeRecord[i][j][k]]++;
                    }
                }
            }
            if (TypeCount[CurrentStone][7] > 0)
            {
                return 9999;//五连
            }
            if (TypeCount[3 - CurrentStone][7] > 0)
            {
                return -9999;//五连
            }
            for (int i = 1; i <= 2; i++) if (TypeCount[i][3] > 1) TypeCount[i][6]++;

            if (TypeCount[CurrentStone][6] > 0)
            {
                return 9990;//活四
            }

            if (TypeCount[CurrentStone][3] > 0)
            {
                return 9980;//冲四
            }

            if (TypeCount[3 - CurrentStone][6] > 0)
            {
                return -9970;//活四
            }


            if (TypeCount[3 - CurrentStone][3] > 0 && TypeCount[3 - CurrentStone][5] > 0) 
            {
                return -9960; //冲四活三
            }

            if (TypeCount[CurrentStone][5]>0 && TypeCount[3 - CurrentStone][3] == 0)           
            {
                return 9950;//冲四活三
            }

            if (TypeCount[3 - CurrentStone][5] > 1 &&
                TypeCount[CurrentStone][3] == 0 &&
                TypeCount[CurrentStone][5] == 0 &&
                TypeCount[CurrentStone][2] == 0)
            {
                return -9940;
            }

            int CValue = 0, PValue = 0;
            if (TypeCount[CurrentStone][5] > 1) 
                CValue += 2000;
            else
            {
                if (TypeCount[CurrentStone][5] > 0)
                    CValue += 200;
            }

            if (TypeCount[3 - CurrentStone][5] > 1)
                PValue += 500;
            else
            {
                if (TypeCount[3 - CurrentStone][5] > 0)
                    PValue += 100;
            }


            if (TypeCount[CurrentStone][2] > 0)
                CValue += TypeCount[CurrentStone][2] * 10;

            if (TypeCount[3 - CurrentStone][2] > 0)
                PValue += TypeCount[3 - CurrentStone][2] * 10;

            if (TypeCount[CurrentStone][4] > 0)
                CValue += TypeCount[CurrentStone][4] * 4;

            if (TypeCount[3 - CurrentStone][2] > 0)
                PValue += TypeCount[3 - CurrentStone][4] * 4;

            if (TypeCount[CurrentStone][2] > 0)
                CValue += TypeCount[CurrentStone][2];

            if (TypeCount[3 - CurrentStone][2] > 0)
                PValue += TypeCount[3 - CurrentStone][2];

            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    if (Board[i][j] != 0)
                    {
                        if (Board[i][j] == CurrentStone) CValue += PosValue[i][j];
                        else PValue += PosValue[i][j];
                    }
                }
            }
            return CValue-PValue;
}

int AnalysisHorizon(int i,int j)
{
	int Line[15];
	for (int s = 0; s < 15; s++){
		 Line[s] = Board[i][s];
	}
    AnalysisLine(Line, 15, j);
    for (int s = 0; s < 15; s++){
    	if (LineRecord[s] != 0){
    	 TypeRecord[i][s][0] = LineRecord[s];
		}
	}
    return TypeRecord[i][j][0];
}

int AnalysisVertical(int i,int j)
{
	int Line[15];
	for (int s = 0; s < 15; s++){
		 Line[s] = Board[s][j];
	}
    AnalysisLine(Line, 15, i);
    for (int s = 0; s < 15; s++){
    	if (LineRecord[s] != 0){
    		TypeRecord[s][j][1] = LineRecord[s];
		}
	}
    return TypeRecord[i][j][1];
}

int AnalysisLeft(int i,int j)
{
	int Line[15];
    int x, y;
    if (i < j){
        y = 0;
        x = j - i;
    }
    else{
        x = 0;
        y = i - j;
    }
    int k;
    for (k = 0; k < 15; k++){
        if (x + k > 14 || y + k > 14){
        	break;
		}

        Line[k] = Board[y + k][x + k];
    }
    AnalysisLine(Line, k, j - x);
    for (int s = 0; s < k; s++){
        if (LineRecord[s] != 0){
        	 TypeRecord[y + s][x + s][2] = LineRecord[s];
		}

    }
    return TypeRecord[i][j][2];
}

int AnalysisRight(int i,int j)
{
	int Line[15];
    int x, y, realnum;
	if (14 - i < j){
        y = 14;
        x = j - 14 + i;
        realnum = 14 - i;
    }
    else{
        x = 0;
        y = i + j;
        realnum = j;
    }
    int k;
    for (k = 0; k < 15; k++){
        if (x + k > 14 || y - k < 0){
        	break;
		}

    	Line[k] = Board[y - k][x + k];
    }
    AnalysisLine(Line, k, j - x);
    for (int s = 0; s < k; s++){
        if (LineRecord[s] != 0){
        	TypeRecord[y - s][x + s][3] = LineRecord[s];	
		}

    }
    return TypeRecord[i][j][3];
}

int AnalysisLine(int Line[],int Num,int Pos)
{
	for (int i = 0; i < Num; i++){
		LineRecord[i] = 0;
	}
    if (Num < 5){
        for (int i = 0; i < Num; i++) LineRecord[i] = -1;
        return -1;
    }
    int LeftEdge, RightEdge;
    int LeftRange, RightRange;
    LeftEdge = RightEdge = Pos;
    while (LeftEdge >0){
        if (Line[LeftEdge - 1] != Line[Pos]){
		 break; 
        }        
		LeftEdge--;
	}
    while (RightEdge < Num-1){
        if (Line[RightEdge + 1] != Line[Pos]){
        	 break;
		} 
        RightEdge++;
    }
    LeftRange = LeftEdge;
    RightRange = RightEdge;
    while (LeftRange >0){
        if (Line[LeftRange - 1] == 3-Line[Pos]){
        	 break; 
		}  
        LeftRange--;
    }
    while (RightRange < Num - 1){
        if (Line[RightRange + 1] == 3 - Line[Pos]){
        	break;
		}
        RightRange++;
    }
    if (RightRange - LeftRange < 4){
        for (int k = LeftRange; k <= RightRange; k++){
			LineRecord[k] = -1;
		}
        return -1;
    }
    for (int k = LeftEdge; k <= RightEdge; k++){
    	 LineRecord[k] = -1;
	}
    if (RightEdge - LeftEdge > 3){
        LineRecord[Pos] = 7; //五连 
        return 7; 
    }
    if (RightEdge - LeftEdge == 3){
        if (LeftEdge==LeftRange || RightEdge==RightRange){
		 LineRecord[Pos] = 3;//四连 
		 } 
        else LineRecord[Pos] = 6;
        return LineRecord[Pos];
        }
    if (RightEdge - LeftEdge == 2){ //三连 
        bool LeftThree = false;
        if (LeftEdge != LeftRange){
            if (LeftEdge > 1 && Line[LeftEdge - 2] == Line[LeftEdge]){
                    LineRecord[LeftEdge] = 3;
                	LineRecord[LeftEdge - 2] = -1;
            }
            else LeftThree = true;
        }
        if (RightEdge != RightRange){
            if (RightEdge < Num - 2 && Line[RightEdge + 2] == Line[RightEdge]){
            	LineRecord[RightEdge] = 3;
                LineRecord[RightEdge + 2] = -1;
        	}
            else{
                if (LeftThree) LineRecord[Pos] = 5;
                else LineRecord[Pos] = 2;
                }
        }
        else{
            if (LineRecord[LeftEdge] == 3) return LineRecord[LeftEdge];
            if(LeftThree) LineRecord[Pos] = 2;
        }
        return LineRecord[Pos];
    }
    if (RightEdge - LeftEdge == 1){//二连 
        bool Lefttwo = false;
        if (LeftEdge > 2){
        	if (Line[LeftEdge - 1] == 0){
            	if (LeftEdge - 1 > 1 && Line[LeftEdge - 2] == Line[LeftEdge]){
                    if (Line[LeftEdge - 3] == Line[LeftEdge]){
                            LineRecord[LeftEdge - 3] = -1;
                            LineRecord[LeftEdge - 2] = -1;
                            LineRecord[LeftEdge] = 3;
                    }
                    else{
						if (Line[LeftEdge - 3] == 0){
                            LineRecord[LeftEdge - 2] = -1;
                        	LineRecord[LeftEdge] = 2;
                    	}
                	}
                    }
                    else Lefttwo = true;
                    }
                }
        if (RightEdge < Num-1){
            if (Line[RightEdge + 1] == 0){
                if (RightEdge + 1 < Num - 2 && Line[RightEdge + 2] == Line[RightEdge]){
                    if (Line[RightEdge + 3] == Line[RightEdge]){
                        LineRecord[RightEdge + 3] = -1;
                        LineRecord[RightEdge + 2] = -1;
                        LineRecord[RightEdge] = 3;
                    }
                    else{
                        if (Line[RightEdge + 3] == 0){
                            LineRecord[RightEdge + 2] = -1;
                            if (Lefttwo == true) LineRecord[RightEdge] = 5;
                            else LineRecord[RightEdge] = 2;
                        }
                    }

                    }
                else{
                	if (LineRecord[LeftEdge] == 3) return LineRecord[LeftEdge];
                    if (LineRecord[LeftEdge] == 2){
                        LineRecord[LeftEdge] = 5;
                        return LineRecord[LeftEdge];
                    }

                    if (Lefttwo == true) LineRecord[Pos] = 4;
                    else  LineRecord[Pos] = 1;
                    }
            }
            else{
        		if (LineRecord[LeftEdge] == 3) return LineRecord[LeftEdge];
            	if (Lefttwo == true) LineRecord[Pos] = 1;
                }

        }
        return LineRecord[Pos];
    }
    return -1;
}

int CreatePossibleMove( int depth,int Count)
{
	MoveCount = 0;
    for (int i = 0; i <15; i++){// 对每一可能的走法
        for (int j = 0; j <15; j++){
        	// 生成新节点
        	if (Board[i][j] == 0){
            	MoveList[depth][MoveCount].r= i;
            	MoveList[depth][MoveCount].c = j;
            	MoveList[depth][MoveCount].v = HistoryHeuristic[i][j];
            	MoveCount++;
        	}
        }
    }
    return MoveCount;
}



void Sort(int depth, int movecount)
{
	struct move temp;
	for (int i = 0; i <= movecount - 2; i++){
        for (int j = movecount - 2; j >= i; j--){
            if (MoveList[depth][j].v<MoveList[depth][j+1].v){
                    temp = MoveList[depth][j];
                    MoveList[depth][j] = MoveList[depth][j + 1];
                    MoveList[depth][j + 1] = temp;
            }
        }
    }
}


void ComputerDownStone()
{
	ResetHistoryTable();
	AlphaBeta(0, ComputerStone, -10000, 10000);
	Board[row][column] = ComputerStone; 
	DrawBoard();
}

int AlphaBeta(int depth, int CurrentStone, int alpha, int beta)
{
	int score;
	if (depth == SearchDepth){
			return Eveluate(CurrentStone);//叶子节点返回估值 
	}
	int movecount = CreatePossibleMove(depth, Count);
	Sort(depth,movecount);
	for (int i = 0; i < movecount; i++){//尝试下子
    	Board[MoveList[depth][i].r][MoveList[depth][i].c] = CurrentStone;
        Count++;
        //是否得出结果
        int re = Result(MoveList[depth][i].r,MoveList[depth][i].c, Count);
        if (re == 1) score = 9999; //胜负已分，返回估值
        else if (re == 2) score = 0; //平局
        else score = -AlphaBeta(depth + 1, 3 - CurrentStone, -beta, -alpha);//递归搜索子节点
        //撤销下子
        Board[MoveList[depth][i].r][ MoveList[depth][i].c] = 0;
        Count--;
		if (score > alpha){
            if (depth == 0){
                row = MoveList[depth][i].r;
                column = MoveList[depth][i].c;
            }
            alpha = score;	//取极大值
        	if (alpha >= beta){
        		//相应棋子位置加分
        		HistoryHeuristic[MoveList[depth][i].r][MoveList[depth][i].c] += 2 << depth;
        		return beta;//剪枝
        	}
        }
    }
            return alpha;//返回最大值
}
