#include "pch.h"
#include "Huffman.h"
void HuffmanCoding(HNode *HT, HCode *HC, unsigned long long *w, const int n)
{
	//初始化
	int m = 2 * n - 1;
	HNode *p = HT;
	int i = 0;
	//听取俸爷建议，重构此处代码
	for (; i < n+m; i++, p++)
	{
		if (i >= n)
		{
			p->weight = 0;
		}
		else
		{
			p->weight = *w;
			w++;
		}
		p->lchild = -1;
		p->rchild = -1;
		p->parent = -1;
	}
	//构造HUFFMAN TREE
	for (i = n; i < m; i++)
	{
		long long min1 = MAXVALUE, min2 = MAXVALUE;
		int min1id = 0, min2id = 0; //min1是最小的，min2次小
		for (int j = 0; j < i; j++)
		{
			if (HT[j].parent == -1 && HT[j].weight < min1)
			{
				min2 = min1;
				min2id = min1id;
				min1 = HT[j].weight;
				min1id = j;
			}
			else if (HT[j].parent == -1 && HT[j].weight < min2)
			{
				min2 = HT[j].weight;
				min2id = j;
			}
		}
		HT[min1id].parent = i;
		HT[min2id].parent = i;
		HT[i].lchild = min1id;
		HT[i].rchild = min2id;
		HT[i].weight = min1 + min2;
	}
	//做字符编码
	for (int j = 0; j < n; j++)
	{
		int start = n - 1;
		for (int tempid = j, tempparent = HT[j].parent; tempparent != -1; tempid = tempparent, tempparent = HT[tempparent].parent)
		{
			if (HT[tempparent].lchild == tempid)
			{
				HC[j].bit[start--] = 0;
			}
			else
				HC[j].bit[start--] = 1;
		}
		HC[j].start = start + 1; //记录根节点位置
	}
}