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
 * draw the chessboard and init the state matrix chessboard[WIDTH][WIDTH]
 * @param chessboard: the matrix chessboard[WIDTH][WIDTH]
 */
void Drawboard(void)
{
    int i, j;

    SetConsoleTitle("Tom.Eureka.Newton's Gomoku AI Enigma");

    system("color f5");//you can adjust the color by this
    for (i=0; i<WIDTH; i++)
    {
        for (j=0; j<WIDTH; j++)
        {
            GoToxy(AffineX(i), AffineY(j));
            putchar('*');
            chessboard[i][j]= VACANT;
        }
    }
    printf("\nEnjoy yourself!\n");
    printf("Use up, down, left, right key to move.\n");
    printf("Use Enter to make chessmove.\n");
    printf("Use q to quit. Use n to start a new game.\n");
    printf("Human Player is the second one to play.\n");
    printf("Good Luck!");
}
void GameAndFun(void)
{
    char oprat;//record the operation of player

    Pos curpos, curpos1, nextpos;//record the curent position of gameplayer
    InitPosition(&curpos);
    InitPosition(&curpos1);

    PrePareAI();
    // setbuf(stdin, NULL);
    curpos1.x= curpos.x=  WIDTH/2-1;
    curpos1.y= curpos.y=  WIDTH/2;
    chessboard[curpos1.x][curpos1.y]= CCHESS;
    GoToxy(AffineX(curpos1.x), AffineY(curpos1.y));
    SetChessColor();
    putchar('X');
    gamer= false;
    GoToxy(AffineX(curpos.x), AffineY(curpos.y));
    while (!Victory)
    {
        if (gamer){
            AIGo(&curpos1);
            gamer=false;
            Judger(curpos1.x, curpos1.y);
            GoToxy(AffineX(curpos.x), AffineY(curpos.y));
            if (Victory){
                GoToxy(AffineX(WIDTH-1)+7, AffineY(0));
                printf("Ha-Ha, it's a smart AI and we have a cool game, isn't?\n");
            }
        }
        else
        {
            oprat=getch();
            if ('q'==oprat || 'Q'==oprat)//quit the game
            {
                GoToxy(AffineX(WIDTH-1)+7, AffineY(0));
                printf("We love Tubo!\n");
                break;
            }
            else if ('n'==oprat || 'N'==oprat)
            {
                curpos.x=curpos.y=0;
                GoToxy(AffineX(curpos.x), AffineY(curpos.y));
                Drawboard();
                GoToxy(AffineX(curpos.x), AffineY(curpos.y));
            }
            else if (UP==oprat)
            {
                nextpos.x=curpos.x-1;
                nextpos.y=curpos.y;
                if ( Inboard(nextpos.x, nextpos.y))
                {
                    GoToxy(AffineX(nextpos.x), AffineY(nextpos.y));
                    curpos.x-=1;
                }
            }
            else if (DOWN==oprat)
            {
                nextpos.x=curpos.x+1;
                nextpos.y=curpos.y;
                if (Inboard(nextpos.x, nextpos.y))
                {
                    GoToxy(AffineX(nextpos.x), AffineY(nextpos.y));
                    curpos.x+=1;
                }
            }
            else if ( LEFT==oprat)
            {
                nextpos.x=curpos.x;
                nextpos.y=curpos.y-1;
                if (Inboard(nextpos.x, nextpos.y))
                {
                    GoToxy(AffineX(nextpos.x), AffineY(nextpos.y));
                    curpos.y-=1;
                }
            }
            else if (RIGHT==oprat)
            {
                nextpos.x=nextpos.x;
                nextpos.y=curpos.y+1;
                if (Inboard(nextpos.x, nextpos.y))
                {
                    GoToxy(AffineX(nextpos.x), AffineY(nextpos.y));
                    curpos.y+=1;
                }
            }
            else if ('\r'==oprat && VACANT==chessboard[curpos.x][curpos.y])//this is about chess move
                //attention that in windows getch() read 'enter' and return '\r'
            {
                chessboard[curpos.x][curpos.y]= PCHESS;
                SetChessColor();
                putchar('O');
                gamer=true;
                Sleep(SLEEPTIME);
                GoToxy(AffineX(curpos1.x), AffineY(curpos1.y));
                Judger(curpos.x, curpos.y);
                if (Victory)
                {
                    GoToxy(AffineX(WIDTH-1)+7, AffineY(0));
                    printf("Human Player win! You are really cool, just like me!\n");
                }
            }
            // fflush(stdin);
            // scanf("%*[^\n]%*c");
        }
    }
}

void InitPosition(Pos* curpos)
{
    curpos->x=0;
    curpos->y=0;
}
bool Inboard(int x, int y)
{
    return x>-1 && x<WIDTH && y>-1 && y<WIDTH;
}
/**
 * judge whether the current state is the game over state
 * we can prove all we need is judge the change made by current chess move
 * @param x          :the coordinate of the current point
 * @param y          :the coordinate of the current point
 * @param chessboard :the state matrix chessboard[WIDTH][WIDTH]
 */
void Judger(int x, int y)
{
    JudgeRow(x, y);
    if (Victory)
        return;
    JudgeColumn(x, y);
    if (Victory)
        return;
    JudgeDiag(x, y);
    if (Victory)
        return;
    JudgeDiag1(x, y);
}
/**
 * son function of Judger, and parameter is same as Judger
 * @param x          [description]
 * @param y          [description]
 * @param chessboard [description]
 */
void JudgeRow(int x, int y)
{

    char curgamer=chessboard[x][y];
    int j=1, flag=1;

    while (j<BORDER )
    {
        if (Inboard(x, y+j) && curgamer==chessboard[x][y+j])
        {
            flag++;
            j++;
        }
        else
            break;
    }

    j=1;
    while (j<BORDER && flag<BORDER)
    {
        if (Inboard(x, y-j) && curgamer==chessboard[x][y-j])
        {
            flag++;
            j++;
        }
        else
            break;
    }

    if (flag>BORDER-1)
        Victory=true;
}
/**
 * same as JudgeRow
 * @param x          [description]
 * @param y          [description]
 * @param chessboard [description]
 */
void JudgeColumn(int x, int y)
{
    char curgamer=chessboard[x][y];
    int i=1, flag=1;

    while (i<BORDER )
    {
        if (Inboard(x+i, y) && curgamer==chessboard[x+i][y])
        {
            flag++;
            i++;
        }
        else
            break;
    }

    i=1;
    while (i<BORDER && flag<BORDER)
    {
        if (Inboard(x-i, y) && curgamer==chessboard[x-i][y])
        {
            flag++;
            i++;
        }
        else
            break;
    }

    if (flag>BORDER-1)
        Victory=true;
}
/**
 * same as JudgeRow
 * @param x          [description]
 * @param y          [description]
 * @param chessboard [description]
 */
void JudgeDiag(int x, int y)
{
    char curgamer=chessboard[x][y];
    int  i=1, flag=1;

    while (i<BORDER)
    {
        if (Inboard(x+i, y+i) && curgamer==chessboard[x+i][y+i])
        {
            flag++;
            i++;
        }
        else
            break;
    }

    i=1;
    while (i<BORDER && flag<BORDER)
    {
        if (Inboard(x-i, y-i) && curgamer==chessboard[x-i][y-i])
        {
            flag++;
            i++;
        }
        else
            break;
    }

    if (flag>BORDER-1)
        Victory=true;
}
void JudgeDiag1(int x, int y)
{
    char curgamer=chessboard[x][y];
    int i=1, flag=1;

    while (i<BORDER)
    {
        if (Inboard(x-i, y+i) && curgamer==chessboard[x-i][y+i])
        {
            flag++;
            i++;
        }
        else
            break;
    }

    i=1;
    while (i<BORDER && flag < BORDER)
    {
        if (Inboard(x+i, y-i) && curgamer==chessboard[x+i][y-i])
        {
            flag++;
            i++;
        }
        else
            break;
    }
    if (flag>BORDER-1)
        Victory=true;
}
