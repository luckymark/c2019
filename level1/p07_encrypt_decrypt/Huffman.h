#pragma once
#define MAXBIT 256
const long long MAXVALUE = 9223372036854775806;
typedef struct HNode {
	long long weight;
	int parent;
	int lchild;
	int rchild;
} HNode;
typedef struct HCode {
	int bit[MAXBIT];
	int start;
} HCode;
void HuffmanCoding(HNode *HT, HCode *HC, unsigned long long *w, const int n);