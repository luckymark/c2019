
//
//#ifndef AIIDIOTNE_HLIBRARY_H
//#define AIIDIOTNE_HLIBRARY_H
//
//#endif //AIIDIOTNE_HLIBRARY_H
/**
 * include all the headerfile that is going to be used
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include <stdbool.h>
#include <conio.h>

#define WIDTH 15
#define BORDER 5
#define SLEEPTIME 1
#define PCHESS '2'  //person's chess
#define CCHESS '1'  //computer's chess
#define VACANT '0'  //vacant
#define MAXLTH 96 // the max length of possible length of the queue
//when we need to construct the Trie
#define CHESSTYPE 3
#define PATTERNNUM 16
#define DEPTH 8		//set the depth of the alpha-beta pruning search
#define SEARCHWIDTH  13	//set the width of the the alpha-beta pruning search
#define INF 999999999		//set the infinity which is going to be used in alpha-beta pruning
#define GOOD 6666			//Don't change, I don't know why this make sense, too. hhhhhhhhhhhhh
#define NICE 1440           //twice of the 720
#define NULLPLACE -1		//the initialization value for scoreboard
#define STACK_INIT_SIZE DEPTH+1	//equal to DEPTH+1
#define STACKINCREMENT 5	//prepare to prevent stack overflow
#define PCHESSCOLOR 4
#define CCHESSCOLOR 1