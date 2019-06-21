

//#ifndef AIIDIOTNE_FIR_H
//#define AIIDIOTNE_FIR_H
//
//#endif //AIIDIOTNE_FIR_H
//#pragma once
#include "hlibrary.h"
#include "material.h"
typedef enum {UP=72, DOWN=80, LEFT=75, RIGHT=77, MOVE='\n'} Operation;
/**
 * prepare for evaluate the situation
 */
/*char PatternTable[PATTERNNUM][7]={
        "11111",
        "011110",
        "011100",
        "001110",
        "011010",
        "010110",
        "11110",
        "01111",
        "11011",
        "10111",
        "11101",
        "001100",
        "001010",
        "010100",
        "000100",
        "001000"
};
char PatternTable1[PATTERNNUM][7]={
        "22222",
        "022220",
        "022200",
        "002220",
        "022020",
        "020220",
        "22220",
        "02222",
        "22022",
        "20222",
        "22202",
        "002200",
        "002020",
        "020200",
        "000200",
        "002000",
};

int ValueTable[PATTERNNUM]={
        INF,
        GOOD,
        720,
        720,
        720,
        720,
        720,
        720,
        720,
        720,
        720,
        120,
        120,
        120,
        20,
        20,
};*/

/**
 * prepare for ac algorithm
 */



void SetChessColor(void);
void GoToxy(int x, int y);
void Drawboard(void);
void GameAndFun(void);
void InitPosition(Pos* curpos);
bool Inboard(int x, int y);
void Judger(int x, int y);
void JudgeRow(int x, int y);
void JudgeColumn(int x, int y);
void JudgeDiag(int x, int y);
void JudgeDiag1(int x, int y);
int AffineX(int x);
int AffineY(int y);
void InitTrie(void);
void InitNode(Node *root);
void EnTrie(char *s, int order);
void EnTrie1(char *s, int order);
void BuildTrie(void);
void BuildFailPointer(void);
int LocalEvaluate(Pos *CurPos);
int ExtractRow(Pos *CurPos, char *Situation);
int ExtractColumn(Pos *CurPos, char *Situation);
int ExtractDiag(Pos *CurPos, char *Situation);
int ExtractDiag1(Pos *CurPos, char *Situation);
int LocalEvaluateRow(Pos *CurPos);
int LocalEvaluateColumn(Pos *CurPos);
int LocalEvaluateDiag(Pos *CurPos);
int LocalEvaluateDiag1(Pos *CurPos);
int LocalRunAC(char *s);
int LocalRunAC1(char *s);
int AllRunAC(char *s);
int AllRunAC1(char *s);
bool JudgeHead(int curxy);
bool JudgeTail(int curxy);
int Max(int a, int b);
void PrePareAI(void);
int LocalACEvaluate(char* Situation, int CurSituation);
int LocalAIEvaluate(Pos *CurPos);
int LocalAIGo(Pos *CurPos);
void InitScoreCard(ScoreCard *scorecard);
int AlphaBetaPruning(int depth, int alpha, int beta, Pos *curpos1, int historydelta);
void MakeNextMove(ScoreCard *scorecard, int depth);
void UnMakeMove(ScoreCard *scorecard);
int EvaluateAll(void);
void HeurSearch(ScoreCard *scoreboard);
void InitScoreBoard(ScoreCard *scoreboard);
void AIGo(Pos *curpos1);
bool InitStack(SqStack *S);
void Push(SqStack *S, Pos *move);
bool Pop(SqStack *S, Pos *move);
int DeltaEvaluateAll(SqStack *S);
int DeltaLocalEvaluate(Pos *CurPos);
int DeltaLocalEvaluateRow(Pos *CurPos);
int DeltaLocalEvaluateColumn(Pos *CurPos);
int DeltaLocalEvaluateDiag(Pos *CurPos);
int DeltaLocalEvaluateDiag1(Pos *CurPos);
int DeltaLocalACEvaluate(char *Situation, int CurSituation);