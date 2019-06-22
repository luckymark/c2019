#pragma once
#include "pch.h"
#include "Gomoku.h"
#include <string>
#include <vector>
#include <map>
using namespace std;
//trieÊ÷½Úµã
struct ACNode {
	ACNode(int p, char c)
		:parent(p),
		ch(c),
		fail(-1)
	{
	}

	char ch;
	map<char, int> sons;
	int fail;
	vector<int> output;
	int parent;
};
int maxState;
vector<string> paterns;
vector<ACNode> nodes;
#pragma once
