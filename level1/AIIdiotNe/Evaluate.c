//
// Created by Newton on 2019/6/19.
//

#include "FIR.h"

extern char PatternTable[PATTERNNUM][7];
extern char PatternTable1[PATTERNNUM][7];
extern int ValueTable[PATTERNNUM];

extern Node *root;
extern Node *root1;
extern Node *Q[MAXLTH];
extern Node *Q1[MAXLTH];

extern bool gamer;
extern bool Victory;

extern char chessboard[WIDTH][WIDTH];

/**
 * return true, if its head touch the border
 * @param  curxy [description]
 * @return       [description]
 */
bool JudgeHead(int curxy)
{
    return curxy < 0;
}
/**
 * return true if the tail touch the border
 * @param  curxy [description]
 * @return       [description]
 */
bool JudgeTail(int curxy)
{
    return curxy > WIDTH-1;
}
int LocalEvaluate(Pos *CurPos)
{
    return LocalEvaluateRow(CurPos)+LocalEvaluateColumn(CurPos)+LocalEvaluateDiag(CurPos)+LocalEvaluateDiag1(CurPos);
}
int ExtractRow(Pos *CurPos, char *Situation)
{
    //extract the situation string
    int curposX=CurPos->x, curposY=CurPos->y, i=0;
    int lb=curposY-BORDER+1, rb=curposY+BORDER-1;
    int CurSituation=0;//represent the index of the current point in Situation array
    if ( JudgeHead(lb))
        lb=0;
    else if ( JudgeTail(rb))
        rb=WIDTH-1;
    CurSituation= curposY-lb; // to locate the index of the current point in Situation array

    while (lb <= rb){
        Situation[i++]=chessboard[curposX][lb++];
    }

    Situation[i] ='\0';

    // printf("EvaluateRow is ok!");  // used to test

    return CurSituation;
}
int ExtractColumn(Pos *CurPos, char *Situation)
{
    int curposX=CurPos->x, curposY=CurPos->y, i=0;
    int LB=curposX-BORDER+1, UB=curposX+BORDER-1;
    int CurSituation=0;

    if (JudgeHead(LB))
        LB=0;
    else if (JudgeTail(UB))
        UB=WIDTH-1;
    CurSituation=curposX-LB;

    while (LB <= UB){
        Situation[i++]=chessboard[LB++][curposY];
    }

    Situation[i] ='\0';

    return CurSituation;
}
int ExtractDiag(Pos *CurPos, char *Situation)
{
    int curposX=CurPos->x, curposY=CurPos->y, i=0;
    int LB=curposX-BORDER+1, UB=curposX+BORDER-1, lb=curposY-BORDER+1, rb=curposY+BORDER-1;//upper bound, lowerbound, leftbound, rightbound
    int CurSituation=0;
    int dxf, dxb, dyf, dyb;	//delta x,y of the front, the back


    if ( JudgeHead(LB))
        LB=0;
    else if( JudgeTail(UB))
        UB=WIDTH-1;
    dxf= curposX-LB;
    dxb= UB-curposX;

    if (JudgeHead(lb))
        lb=0;
    else if (JudgeTail(rb))
        rb=WIDTH-1;
    dyf= curposY-lb;
    dyb= rb-curposY;

    if (dxf < dyf){
        dyf=dxf;
        lb= curposY-dyf;
    }
    else if (dyf < dxf){
        dxf=dyf;
        LB= curposX-dxf;
    }

    if (dxb < dyb){
        dyb=dxb;
        rb= curposY+dyb;
    }
    else if (dyb < dxb){
        dxb=dyb;
        UB= curposX+dxb;
    }
    CurSituation=dxf;

    while ( lb <= rb ){
        Situation[i++]=chessboard[LB++][lb++];
    }
    Situation[i] ='\0';

    return CurSituation;
}
int ExtractDiag1(Pos *CurPos, char *Situation)
{
    int curposX=CurPos->x, curposY=CurPos->y, i=0;
    int LB=curposX-BORDER+1, UB=curposX+BORDER-1, lb=curposY-BORDER+1, rb=curposY+BORDER-1;
    int CurSituation=0;
    int dxf, dxb, dyf, dyb;	//delta x,y of the front, the back

    if ( JudgeHead(LB))
        LB=0;
    else if( JudgeTail(UB))
        UB=WIDTH-1;
    dxf= curposX-LB;
    dxb= UB-curposX;

    if (JudgeHead(lb))
        lb=0;
    else if (JudgeTail(rb))
        rb=WIDTH-1;
    dyf= curposY-lb;
    dyb= rb-curposY;

    /*dyf, dxb
    dyb, dxf*/
    if ( dxb< dyf){
        dyf= dxb;
        lb= curposY-dyf;
    }
    else if (dyf< dxb){
        dxb= dyf;
        UB= curposX+dxb;
    }

    if (dxf < dyb){
        dyb= dxf;
        rb= curposY+dyb;
    }
    else if (dyb < dxf){
        dxf= dyb;
        LB= curposX-dxf;
    }
    CurSituation= dxb;

    while ( lb <= rb ){
        Situation[i++]=chessboard[UB--][lb++];
    }
    Situation[i] ='\0';

    return CurSituation;
}

/**
 * Evaluate the situation of the current row
 * @param  CurPos [description]
 * @return        [description]
 */
int LocalEvaluateRow(Pos *CurPos)
{
    char Situation[2*BORDER];

    //extract the situation string
    int CurSituation=ExtractRow(CurPos, Situation);//represent the index of the current point in Situation array

    return LocalACEvaluate(Situation, CurSituation);
}
/**
 * Evaluate the situation of the current column
 * @param  CurPos [description]
 * @return        [description]
 */
int LocalEvaluateColumn(Pos *CurPos)
{
    char Situation[2*BORDER];
    //extract the situtation string
    int CurSituation=ExtractColumn(CurPos, Situation);

    return LocalACEvaluate(Situation, CurSituation);
}
/**
 * Evaluate the situation of the diag
 * @param  CurPos [description]
 * @return        [description]
 */
int LocalEvaluateDiag(Pos *CurPos)
{
    char Situation[2*BORDER];
    int CurSituation=ExtractDiag(CurPos, Situation);

    return LocalACEvaluate(Situation, CurSituation);
}
/**
 * Evaluate the situation of the diag1
 * @param  CurPos [description]
 * @return        [description]
 */
int LocalEvaluateDiag1(Pos *CurPos)
{
    char Situation[2*BORDER];
    int CurSituation=ExtractDiag1(CurPos, Situation);

    return LocalACEvaluate(Situation, CurSituation);
}
int LocalACEvaluate(char* Situation, int CurSituation)
{
    int score=0;

    Situation[CurSituation]=CCHESS;
    score= LocalRunAC(Situation);
    Situation[CurSituation]=PCHESS;
    // score= Max(score, LocalRunAC1(Situation));
    // printf("%d, AC1 is good", score);  //used to test
    score+= LocalRunAC1(Situation);
    return score;
}
/**
 * paticularly used for LocalAIEvaluate
 * @param  CurPos [description]
 * @return        [description]
 */
int LocalAIEvaluate(Pos *CurPos)
{
    char RowSituation[2*BORDER], ColumnSituation[2*BORDER], DiagSituation[2*BORDER], Diag1Situation[2*BORDER];

    int CurSituation, pscore, cscore, store; //pscore: the score of the human chess, cscore: the score of the computer

    CurSituation= ExtractRow(CurPos, RowSituation);
    RowSituation[CurSituation]= CCHESS;
    cscore= LocalRunAC(RowSituation);
    if (INF== cscore){
        return INF;
    }
    RowSituation[CurSituation]= PCHESS;

    CurSituation= ExtractColumn(CurPos, ColumnSituation);
    ColumnSituation[CurSituation]= CCHESS;
    store= LocalRunAC(ColumnSituation);
    if (INF== store){
        return INF;
    }
    cscore+= store;
    ColumnSituation[CurSituation]= PCHESS;

    CurSituation= ExtractDiag(CurPos, DiagSituation);
    DiagSituation[CurSituation]= CCHESS;
    store= LocalRunAC(DiagSituation);
    if (INF== store){
        return INF;
    }
    cscore+= store;
    DiagSituation[CurSituation]= PCHESS;

    CurSituation= ExtractDiag1(CurPos, Diag1Situation);
    Diag1Situation[CurSituation]= CCHESS;
    store= LocalRunAC(Diag1Situation);
    if (INF== store){
        return INF;
    }
    cscore+= store;
    Diag1Situation[CurSituation]= PCHESS;



    pscore= LocalRunAC1(RowSituation);
    if (INF== pscore){
        return -INF;
    }

    store= LocalRunAC1(ColumnSituation);
    if (INF== store){
        return -INF;
    }
    pscore+= store;

    store= LocalRunAC1(DiagSituation);
    if (INF== store){
        return -INF;
    }
    pscore+= store;

    store= LocalRunAC1(Diag1Situation);
    if (INF== store){
        return -INF;
    }
    pscore+= store;

    if (cscore >= NICE){
        return cscore+pscore;
    }

    if (pscore >= NICE){
        return -pscore-cscore;
    }

    return 0;

}
/**
 * used for evaluate the total score of the situation
 * @return  [description]
 */
int EvaluateAll(void)
{
    int score=0, store=0;
    int i, j, lb, rb, LB, UB;
    char Situation[2*WIDTH+1];

    lb=0;
    UB=WIDTH;
    do{
        i=0;
        LB=0;
        while (LB < UB){
            Situation[i++]= chessboard[LB++][lb];
        }
        Situation[i]= '\0';
        if (INF == (store=AllRunAC(Situation)))
            return INF;
        score+= store;
        if (INF == (store= AllRunAC1(Situation)))
            return -INF;
        score-= store;
    }while (++lb < WIDTH);

    LB=0;
    rb=WIDTH;
    do{
        i=0;
        lb=0;
        while (lb < rb){
            Situation[i++]= chessboard[LB][lb++];
        }
        Situation[i]='\0';
        if (INF == (store=AllRunAC(Situation)))
            return INF;
        score+=store;
        if (INF == (store=AllRunAC1(Situation)))
            return -INF;
        score-=store;
    }while ( ++LB <WIDTH);

    lb= 0;
    UB= WIDTH;
    do{
        i= 0;
        LB= 0;
        j=lb;

        while (LB < UB){
            Situation[i++]= chessboard[LB++][j++];
        }
        Situation[i]='\0';
        if (INF == (store=AllRunAC(Situation)))
            return INF;
        score+=store;
        if (INF == (store=AllRunAC1(Situation)))
            return -INF;
        score-=store;
        UB--;

    }while (++lb < WIDTH-BORDER+1 );

    LB= 0;
    rb= WIDTH;
    while ( ++LB < WIDTH-BORDER+1){
        rb--;
        i=0;
        lb=0;
        j=LB;
        while ( lb < rb){
            Situation[i++]=chessboard[j++][lb++];
        }
        Situation[i]='\0';
        if (INF == (store=AllRunAC(Situation)))
            return INF;
        score+=store;
        if (INF== (store= AllRunAC1(Situation)))
            return INF;
        score-=store;

    }

    rb=WIDTH;
    UB=WIDTH;
    while (UB-- > BORDER-1){
        i= 0;
        lb= 0;
        j= UB;
        while ( lb < rb){
            Situation[i++]= chessboard[j--][lb++];
        }
        Situation[i]='\0';
        if (INF == (store=AllRunAC(Situation)))
            return INF;
        score+=store;
        if (INF == (store=AllRunAC1(Situation)))
            return -INF;
        score-=store;
        rb--;

    }

    lb=0;
    LB=0;
    while ( ++lb < WIDTH-BORDER+1){
        LB++;
        i= 0;
        UB= WIDTH;
        j= lb;
        while (UB > LB){
            Situation[i++]= chessboard[--UB][j++];
        }
        Situation[i]='\0';
        if (INF == (store= AllRunAC(Situation)))
            return INF;
        score+=store;
        if (INF == (store=AllRunAC1(Situation)))
            return -INF;
        score-=store;
    }
    // printf("EvaluateAll is ok\n");
    return score;
}
int DeltaEvaluateAll(SqStack *S)
{
    Pos move;
    int delta=0;
    if ( Pop(S, &move)){
        delta= DeltaLocalEvaluate(&move);
    }

    return delta;
}
/**
 * use DeltaLocalEvalute to replace EvaluateAll to optimize the process of evaluating
 * @param  CurPos [description]
 * @return        [description]
 */
int DeltaLocalEvaluate(Pos *CurPos)
{
    return DeltaLocalEvaluateRow(CurPos)+DeltaLocalEvaluateColumn(CurPos)+DeltaLocalEvaluateDiag(CurPos)+DeltaLocalEvaluateDiag1(CurPos);
}
int DeltaLocalEvaluateRow(Pos *CurPos)
{
    char Situation[2*BORDER];
    //extract the situation string
    int CurSituation=ExtractRow(CurPos, Situation);//represent the index of the current point in Situation array

    return DeltaLocalACEvaluate(Situation, CurSituation);
}

int DeltaLocalEvaluateColumn(Pos *CurPos)
{
    char Situation[2*BORDER];
    //extract the situtation string
    int CurSituation=ExtractColumn(CurPos, Situation);

    return DeltaLocalACEvaluate(Situation, CurSituation);
}


int DeltaLocalEvaluateDiag(Pos *CurPos)
{
    char Situation[2*BORDER];
    int CurSituation=ExtractDiag(CurPos, Situation);

    return DeltaLocalACEvaluate(Situation, CurSituation);
}

int DeltaLocalEvaluateDiag1(Pos *CurPos)
{
    char Situation[2*BORDER];
    int CurSituation=ExtractDiag1(CurPos, Situation);

    return DeltaLocalACEvaluate(Situation, CurSituation);
}
int DeltaLocalACEvaluate(char *Situation, int CurSituation)
{
    int score=0;
    int cscore, pscore;	//reprent the pure score of pc and human
    if (INF== (cscore=AllRunAC(Situation)))
        return INF;
    if (INF== (pscore=AllRunAC1(Situation)))
        return -INF;

    score= cscore-pscore;
    Situation[CurSituation]= VACANT;

    score-= AllRunAC(Situation)- AllRunAC1(Situation);

    return score;

}
