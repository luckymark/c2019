#pragma once
#include "GomokuUI.h"
#include<set>

#define MAX_CALCULATE_SCORE_LENGTH 5
#define MAX_TREE_DEPTH 4
#define PRIDICT_PIECE_RANGE 9 //must be an odd number
#define START_POINT_RECURSION_DEPTH 2 // in DFSChoiceTreeNode
//and it may be a good idea set START_POINT_RECURSION_DEPTH to equal to MAX_TREE_DEPTH
//but it's still silly and much slower

#define DEBUG_SCORE_CALCULATE

//#define SEARCH_FOR_WHOLE_BOARD

#define OUTPUT_CALCULATE_TIME

using namespace std;

struct choiceTreeNode {
	int playerPiece;
	pointStruct point;
	int score();
	set<choiceTreeNode*> nextTreeNode;
	choiceTreeNode * fatherTreeNode;
};

void pieceNInDirectedLine(const pointStruct p, const pointStruct dir, 
	int(&len)[MAX_CALCULATE_SCORE_LENGTH], const int lenAdd);
void pieceNInLine(pointStruct p, pointStruct dir, int(&len)[MAX_CALCULATE_SCORE_LENGTH]);
int continousPieceNInLine(pointStruct p, pointStruct dir);
int calculateScore(pointStruct p);

pointStruct AIPutPiece(pointStruct lastPiece);
pointStruct putPieceAnyway(pointStruct & point, int value); //to solve the problem that the current point has a piece
pointStruct putPieceAnyway(pointStruct & point, pointStruct dir, int value); //when the direction is decided