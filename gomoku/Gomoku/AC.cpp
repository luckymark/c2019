/*
	Aho-Corasick AC�Զ���
	�����ⲿ��ģʽƥ���
*/
#pragma once
#include "pch.h"
#include "AC.h"

void LoadPatern(char* (_paterns[]), int length);
void BuildGotoTable();
void BuildFailTable();
void AddState(int parent, char ch);
//AC�Զ�����ʼ��
void AC_Init(char* (_paterns[]), int length) {
	maxState = 0;
	AddState(-1, 'a');
	nodes[0].fail = -1;
	LoadPatern(_paterns, length);
	BuildGotoTable();
	BuildFailTable();
}
void LoadPatern(char* (_paterns[]), int length) {
	paterns = vector<string>();
	for (int i = 0; i < length; i++) {
		paterns.push_back(_paterns[i]);
	}
}
void BuildGotoTable() {
	unsigned int i, j;
	for (i = 0; i < paterns.size(); i++) {
		//�Ӹ��ڵ㿪ʼ
		int currentIndex = 0;
		for (j = 0; j < paterns[i].size(); j++) {
			if (nodes[currentIndex].sons.find(paterns[i][j]) == nodes[currentIndex].sons.end()) {
				nodes[currentIndex].sons[paterns[i][j]] = ++maxState;

				//�����½ڵ�
				AddState(currentIndex, paterns[i][j]);
				currentIndex = maxState;
			}
			else {
				currentIndex = nodes[currentIndex].sons[paterns[i][j]];
			}
		}

		nodes[currentIndex].output.push_back(i);
	}
}
void BuildFailTable() {

	//�м�ڵ��ռ���
	vector<int> midNodesIndex;

	//����һ��Ľڵ�����failΪ0�����ѵڶ���ڵ���뵽midState��
	ACNode root = nodes[0];

	map<char, int>::iterator iter1, iter2;
	for (iter1 = root.sons.begin(); iter1 != root.sons.end(); iter1++) {
		nodes[iter1->second].fail = 0;
		ACNode& currentNode = nodes[iter1->second];

		//�ռ�������ڵ�
		for (iter2 = currentNode.sons.begin(); iter2 != currentNode.sons.end(); iter2++) {
			midNodesIndex.push_back(iter2->second);
		}
	}

	//������ȱ���
	while (midNodesIndex.size()) {
		vector<int> newMidNodesIndex;

		unsigned int i;
		for (i = 0; i < midNodesIndex.size(); i++) {
			ACNode& currentNode = nodes[midNodesIndex[i]];

			//����ѭ��ΪѰ�ҵ�ǰ�ڵ��failֵ
			int currentFail = nodes[currentNode.parent].fail;
			while (true) {
				ACNode& currentFailNode = nodes[currentFail];

				if (currentFailNode.sons.find(currentNode.ch) != currentFailNode.sons.end()) {
					//�ɹ��ҵ��ýڵ��failֵ
					currentNode.fail = currentFailNode.sons.find(currentNode.ch)->second;

					//��׺����
					if (nodes[currentNode.fail].output.size()) {
						currentNode.output.insert(currentNode.output.end(), nodes[currentNode.fail].output.begin(), nodes[currentNode.fail].output.end());
					}

					break;
				}
				else {
					currentFail = currentFailNode.fail;
				}

				//����Ǹ��ڵ�
				if (currentFail == -1) {
					currentNode.fail = 0;
					break;
				}
			}

			//�ռ���һ��ڵ�
			for (iter1 = currentNode.sons.begin(); iter1 != currentNode.sons.end(); iter1++) {
				//�ռ���һ��ڵ�
				newMidNodesIndex.push_back(iter1->second);
			}
		}
		midNodesIndex = newMidNodesIndex;
	}
}
//ƥ�����,lengthΪ���ص����鳤��,��������Ϊƥ�䵽���ַ��������λ��,һ���ǵ�free
int* AC_ACSearch(char str[], int* length) {
	vector<int> result;
	string text = string(str);
	//��ʼ��Ϊ���ڵ�
	int currentIndex = 0;

	int i;
	map<char, int>::iterator tmpIter;
	for (i = 0; i < text.size();) {
		//˳��trie������
		if ((tmpIter = nodes[currentIndex].sons.find(text[i])) != nodes[currentIndex].sons.end()) {
			currentIndex = tmpIter->second;
			i++;
		}
		else {
			//ʧ������
			while (nodes[currentIndex].fail != -1 && nodes[currentIndex].sons.find(text[i]) == nodes[currentIndex].sons.end()) {
				currentIndex = nodes[currentIndex].fail;
			}

			//���û�гɹ��ҵ����ʵ�fail
			if (nodes[currentIndex].sons.find(text[i]) == nodes[currentIndex].sons.end()) {
				i++;
			}
		}

		if (nodes[currentIndex].output.size()) {
			result.insert(result.end(), nodes[currentIndex].output.begin(), nodes[currentIndex].output.end());
		}

	}
	//free(res);
	int t = result.size();
	int* res = (int *)malloc(sizeof(int)*t);
	*length = result.size();
	for (i = 0; i < result.size(); i++) {
		res[i] = (int)result[i];
	}
	return res;
}
void AddState(int parent, char ch) {
	nodes.push_back(ACNode(parent, ch));
}