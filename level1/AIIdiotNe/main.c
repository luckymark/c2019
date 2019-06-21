#include "FIR.h"
/**
 * prepare for evaluate the situation
 */
char PatternTable[PATTERNNUM][7]={
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
};

Node *root;
Node *root1;
Node *Q[MAXLTH];
Node *Q1[MAXLTH];

bool gamer=true;
bool Victory=false;

char chessboard[WIDTH][WIDTH];

SqStack stack;
int main(void)
{
    printf("NewTon's AI IdiotNe Enigma");
    Drawboard();
    GameAndFun();
    system("pause");
    return 0;

}