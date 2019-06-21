#include "Content.h"

void DrawBoard();
char* Get(int x,int y);
int Put();
int RunGame();
void Initialize();
void Back(); 
void ResetHistoryTable();
int Result(int i,int j,int Count);
int Eveluate(int CurrentStone);
int AnalysisHorizon(int i,int j);
int AnalysisVertical(int i,int j);
int AnalysisLeft(int i,int j);
int AnalysisRight(int i,int j);
int AnalysisLine(int Line[],int Num,int Pos);
int CreatePossibleMove( int depth,int Count);
void Sort(int depth, int movecount);
void ComputerDownStone();
int AlphaBeta(int depth, int CurrentStone, int alpha, int beta);
