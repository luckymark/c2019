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

void PrePareAI(void)
{
    InitTrie();
    BuildTrie();
    BuildFailPointer();
    // InitStack(&stack);
}

/**
 * do the first important decision that the current situation is must win or might lose
 * @param  CurPos [description]
 * @return        [description]
 */
int LocalAIGo(Pos *CurPos)
{
    int c=0;
    ScoreCard scorecard;
    InitScoreCard(&scorecard);
    for (CurPos->x=0; CurPos->x < WIDTH; CurPos->x++){
        for (CurPos->y=0; CurPos->y < WIDTH; CurPos->y++){
            if (VACANT == chessboard[CurPos->x][CurPos->y] ){
                c= LocalAIEvaluate(CurPos);
                if (scorecard.score >=0 ){
                    if (scorecard.score < c){
                        scorecard.index= *CurPos;
                        scorecard.score= c;
                    }
                    else if (c+scorecard.score <0){
                        scorecard.index= *CurPos;
                        scorecard.score=c;
                    }
                    else
                        continue;
                }
                else {
                    if (scorecard.score > c){
                        scorecard.index= *CurPos;
                        scorecard.score= c;
                    }
                    else if (scorecard.score+c >=0){
                        scorecard.index= *CurPos;
                        scorecard.score= c;
                    }
                    else
                        continue;
                }
            }
            else
                continue;
        }
    }
    *CurPos= scorecard.index;

    return scorecard.score;

    // return CurPos;
}
void InitScoreCard(ScoreCard *scorecard)
{
    scorecard->index.x=scorecard->index.y=0;
    scorecard->score=0;
}
/**
 * use alpha-beta pruning to speed up the search
 * @param  depth        [description]
 * @param  alpha        [the maximum lowerbound]
 * @param  beta         [the minimum upperbound]
 * @param  curpos1      [description]
 * @param  historyscore [store the score accumulate the delta in history]
 * @return              [description]
 */
int AlphaBetaPruning(int depth, int alpha, int beta, Pos *curpos1, int historydelta)
{
    // printf("AlphaBetaPruning is ok\n");
    int curdelta= historydelta;
    if ( 0== depth ){
        if (DEPTH%2){
            return -curdelta;
        }
        else{
            return curdelta;
        }
    }
    int i=0;
    int count= SEARCHWIDTH, value=0;
    int store;
    ScoreCard scoreboard[SEARCHWIDTH];
    InitScoreBoard(scoreboard);

    HeurSearch(scoreboard);

    if (DEPTH== depth){
        while ( count-- > 0 && NULLPLACE != scoreboard[i].index.x){
            MakeNextMove(scoreboard+i, depth);
            store= DeltaLocalEvaluate(&(scoreboard[i].index));
            curdelta+= store;
            value= -AlphaBetaPruning(depth-1, -beta, -alpha, curpos1, curdelta);
            UnMakeMove(scoreboard+i);
            curdelta-= store;
            if (value > alpha){
                alpha= value;
                *curpos1= scoreboard[i].index;
            }
            i++;
        }
    }
    else{
        while ( count-- > 0 && NULLPLACE != scoreboard[i].index.x){
            MakeNextMove(scoreboard+i, depth);
            store= DeltaLocalEvaluate(&(scoreboard[i].index));

            if (INF<= store ){
                UnMakeMove(scoreboard+i);
                /*if (depth%2){
                    i++;
                    continue;
                }
                else
                    return beta;*/
                return beta;
            }
            else if (-INF>= store){
                UnMakeMove(scoreboard+i);
                /*if (depth%2)
                    return beta;
                else{
                    i++;
                    continue;
                }*/
                return beta;
            }
            else{
                curdelta+= store;
                value= -AlphaBetaPruning(depth-1, -beta, -alpha, curpos1, curdelta);
                UnMakeMove(scoreboard+i);
                curdelta-= store;
                if (value >= beta){
                    return beta;
                }
                if (value > alpha){
                    alpha= value;
                }

                i++;
            }
        }
    }
    // printf("AlphaBetaPruning is ok\n");
    return alpha;
}
void MakeNextMove(ScoreCard *scorecard, int depth)
{
    chessboard[scorecard->index.x][scorecard->index.y]= depth%2== DEPTH%2 ? CCHESS : PCHESS;
}
void UnMakeMove(ScoreCard *scorecard)
{
    chessboard[scorecard->index.x][scorecard->index.y]=VACANT;
}


/**
 * used to optimize the alpha-beta pruning
 * @param scoreboard [description]
 */
void HeurSearch(ScoreCard *scoreboard)
{
    int minscore=0;	//represent the minimum score of the top ten value
    int lth=0, i;	//use lth to record the length of the current scoreboard
    Pos CurPos;
    ScoreCard scorecard;

    for (CurPos.x=0; CurPos.x < WIDTH; CurPos.x++){
        for (CurPos.y=0; CurPos.y < WIDTH; CurPos.y++){
            if (VACANT == chessboard[CurPos.x][CurPos.y] && minscore < (scorecard.score=LocalEvaluate(&CurPos))){
                /*if (INF== scorecard.score){
                    scoreboard[0].index= CurPos;
                    scoreboard[0].score= scorecard.score;
                    scoreboard[1].index.x= scoreboard[1].index.y= NULLPLACE;
                    return;
                }*/      // improper pruning, may lose some solution
                i= lth;
                scoreboard[i].index= CurPos;
                scoreboard[i].score= scorecard.score;
                do{
                    if (scoreboard[i].score > scoreboard[i-1].score){
                        scorecard= scoreboard[i];
                        scoreboard[i]= scoreboard[i-1];
                        scoreboard[i-1]= scorecard;
                    }
                    else
                        break;
                }while ( i--> 0);

                minscore= scoreboard[lth].score;
                if ( lth < SEARCHWIDTH-1)
                    lth++;
            }
            else
                continue;
        }
    }
}
void InitScoreBoard(ScoreCard *scoreboard)
{
    int i;
    for ( i=0; i< SEARCHWIDTH; i++){
        scoreboard[i].index.x= NULLPLACE;
        scoreboard[i].index.y= NULLPLACE;
        scoreboard[i].score= 0;
    }
}
/**
 * AI
 * @param curpos1 [description]
 */
void AIGo(Pos *curpos1)
{
    int score;
    score= LocalAIGo(curpos1);
    if (0==score){
        score=AlphaBetaPruning(DEPTH, -INF, INF, curpos1, 0);
        GoToxy(0, 27);
        printf("%9d\tMy chess move: %2d %2d", score, curpos1->x, curpos1->y);
    }
    else{
        GoToxy(0, 27);
        printf("oooo");
    }

    chessboard[curpos1->x][curpos1->y]= CCHESS;
    GoToxy(AffineX(curpos1->x), AffineY(curpos1->y));
    SetChessColor();
    putchar('X');
    GoToxy(AffineX(curpos1->x), AffineY(curpos1->y));
}