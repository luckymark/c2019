#include "pch.h";
#include "Evaluate.h";

//������һ����ά������д���
char board[WIDTH][WIDTH];
int clickPointCount;
//���������֣�Player ->0; Computer->1��
int scoreAll[2];

//[Public]��ʼ��
void evaluateInit() {
	AC_Init(paternTable, PATERNLENGTH);
	reloadGame();
}

//[Public]��ȡ���̵�����
char getChessboard(int x, int y) {
	return board[x][y];
}

//[Public]�������̵�����
void setChessboard(int x, int y, char type) {
	board[x][y] = type;
	if (type == EMPTY) {
		clickPointCount--;
	}
	else {
		clickPointCount++;
	}

}



//��ȡλ�÷���
int getPositionScores(int x, int y) {
	int scores = 0;
	for (int type = 0; type < 4; type++)
	{
		int length = 0;
		char str1[WIDTH + 1], str2[WIDTH + 1];
		getPositionStr(type, x, y, str1, str2);
		int* result = AC_ACSearch(str1, &length);
		for (int s = 0; s < length; s++)
		{
			scores += paternScores[result[s]];//��������ȡ��
		}
		free(result);
		result = AC_ACSearch(str2, &length);
		for (int s = 0; s < length; s++)
		{
			scores += paternScores[result[s]];//��������ȡ��
		}
		free(result);
	}
	return scores;
}
/*
	��ָ��λ�õ������ַ�����
	type:���ͣ�col,row,diag1,diag2��
	str1:Player���ַ���
	str2:Computer���ַ�����2->1;1->2��
*/
void getPositionStr(int type, int x, int y, char* str1, char* str2) {
	switch (type)
	{
	case ROW: {
		int index = 0;
		for (int i = (x - 5 < 0 ? 0 : x - 5); i < (x + 6 > WIDTH ? WIDTH : x + 6); i++, index++)
		{

			if (x == i) {
				str1[index] = PLAYER;
				str2[index] = PLAYER;
			}
			else {
				char ch = board[i][y];
				str1[index] = ch;
				str2[index] = (ch == EMPTY ? EMPTY : (ch == PLAYER ? COMPUTER : PLAYER));
			}
		}
		str1[index] = '\0';
		str2[index] = '\0';
		break;
	}
	case COL: {
		int index = 0;
		for (int i = (y - 5 < 0 ? 0 : y - 5); i < (y + 6 > WIDTH ? WIDTH : y + 6); i++, index++)
		{

			if (y == i) {
				str1[index] = PLAYER;
				str2[index] = PLAYER;
			}
			else {
				char ch = board[x][i];
				str1[index] = ch;
				str2[index] = (ch == EMPTY ? EMPTY : (ch == PLAYER ? COMPUTER : PLAYER));
			}


		}
		str1[index] = '\0';
		str2[index] = '\0';
		break;
	}
	case DIAG1: {
		int index = 0;
		int min = (x > y ? y : x);
		min = min > 5 ? 5 : min;
		for (int i = x - min, c = y - min; i < (x + 6 > WIDTH ? WIDTH : x + 6) && c < (y + 6 > WIDTH ? WIDTH : y + 6); i++, c++, index++)
		{

			if (x == i) {
				str1[index] = PLAYER;
				str2[index] = PLAYER;
			}
			else {
				char ch = board[i][c];
				str1[index] = ch;
				str2[index] = (ch == EMPTY ? EMPTY : (ch == PLAYER ? COMPUTER : PLAYER));
			}
		}
		str1[index] = '\0';
		str2[index] = '\0';
		break;
	}
	case DIAG2: {
		int index = 0;
		int min = (y > (WIDTH - 1 - x) ? (WIDTH - 1 - x) : y);
		min = min > 5 ? 5 : min;
		for (int i = x + min, c = y - min; i >= (x - 5 < 0 ? 0 : x - 5) && c < (y + 6 > WIDTH ? WIDTH : y + 6); i--, c++, index++)
		{

			if (x == i) {
				str1[index] = PLAYER;
				str2[index] = PLAYER;
			}
			else {
				char ch = board[i][c];
				str1[index] = ch;
				str2[index] = (ch == EMPTY ? EMPTY : (ch == PLAYER ? COMPUTER : PLAYER));
			}
		}
		str1[index] = '\0';
		str2[index] = '\0';
		break;
	}
	default:
		throw "Type ERROR";
	}
}

//�ͷ��ַ�������
void freeAll(char** str, int length) {
	for (int i = 0; i < length; i++)
	{
		free(str[i]);
	}
	free(str);
}

/*
	�����������ַ�����
	type:���ͣ�col,row,diag1,diag2��
	str1:Player���ַ���
	str2:Computer���ַ�����2->1;1->2��
*/
void getEvaluateStr(int type, char** str1, char** str2, int* length) {
	switch (type)
	{
	case ROW: {
		for (int i = 0; i < WIDTH; i++)
		{
			char* s1 = (char*)malloc(sizeof(char) * WIDTH + 1),
				*s2 = (char*)malloc(sizeof(char) * WIDTH + 1);
			for (int c = 0; c < WIDTH; c++)
			{
				char ch = board[c][i];
				char c1 = ch,
					c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
				s1[c] = c1;
				s2[c] = c2;
			}
			s1[WIDTH] = '\0';
			s2[WIDTH] = '\0';
			str1[i] = s1;
			str2[i] = s2;
		}
		*length = WIDTH;
		return;
	}
	case COL: {
		for (int i = 0; i < WIDTH; i++)
		{
			char* s1 = (char*)malloc(sizeof(char) * WIDTH + 1),
				*s2 = (char*)malloc(sizeof(char) * WIDTH + 1);
			for (int c = 0; c < WIDTH; c++)
			{
				char ch = board[i][c];
				char c1 = ch,
					c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
				s1[c] = c1;
				s2[c] = c2;
			}
			s1[WIDTH] = '\0';
			s2[WIDTH] = '\0';
			str1[i] = s1;
			str2[i] = s2;
		}
		*length = WIDTH;
		return;
	}
	case DIAG1: {
		for (int l = 0; l < WIDTH; l++) {
			char* s1 = (char*)malloc(sizeof(char) * WIDTH - l + 1),
				*s2 = (char*)malloc(sizeof(char) * WIDTH - l + 1);
			for (int i = l, c = 0; i < WIDTH && c < WIDTH; i++, c++)
			{
				char ch = board[i][c];
				char c1 = ch ,
					c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
				s1[c] = c1;
				s2[c] = c2;
			}
			s1[WIDTH - l] = '\0';
			s2[WIDTH - l] = '\0';
			str1[l] = s1;
			str2[l] = s2;
		}
		for (int l = 1; l < WIDTH; l++) {
			char* s1 = (char*)malloc(sizeof(char) * WIDTH - l + 1),
				*s2 = (char*)malloc(sizeof(char) * WIDTH - l + 1);
			for (int i = 0, c = l; i < WIDTH && c < WIDTH; i++, c++)
			{
				char ch = board[i][c];
				char c1 = ch,
					c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
				s1[i] = c1;
				s2[i] = c2;
			}
			s1[WIDTH - l] = '\0';
			s2[WIDTH - l] = '\0';
			str1[WIDTH + l - 1] = s1;
			str2[WIDTH + l - 1] = s2;
		}
		*length = WIDTH * 2 - 1;
		return;
	}
	case DIAG2: {
		for (int l = 0; l < WIDTH; l++) {
			char* s1 = (char*)malloc(sizeof(char) * WIDTH - l + 1),
				*s2 = (char*)malloc(sizeof(char) * WIDTH - l + 1);
			for (int i = WIDTH - l - 1, c = 0; i > -1 && c < WIDTH; i--, c++)
			{
				char ch = board[i][c];
				char c1 = ch,
					c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
				s1[c] = c1;
				s2[c] = c2;
			}
			s1[WIDTH - l] = '\0';
			s2[WIDTH - l] = '\0';
			str1[l] = s1;
			str2[l] = s2;
		}
		for (int l = 1; l < WIDTH; l++) {
			char* s1 = (char*)malloc(sizeof(char) * WIDTH - l + 1),
				*s2 = (char*)malloc(sizeof(char) * WIDTH - l + 1);
			for (int i = WIDTH - 1, c = l, m = 0; i > -1 && c < WIDTH; i--, c++, m++)
			{
				char ch = board[i][c];
				char c1 = ch,
					c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
				s1[m] = c1;
				s2[m] = c2;
			}
			s1[WIDTH - l] = '\0';
			s2[WIDTH - l] = '\0';
			str1[WIDTH + l - 1] = s1;
			str2[WIDTH + l - 1] = s2;
		}
		*length = WIDTH * 2 - 1;
		return;
	}
	default:
		break;
	}
}

/*
	��ȡȫ����������
	type:���ͣ�col,row,diag1,diag2��
	scores1:Player�ķ���
	scores2:Computer�ķ���
*/
void getEvaluateScores(int type, int* scores1, int* scores2) {
	char** str1, ** str2;
	switch (type)
	{
	case COL:
	case ROW: {
		str1 = (char**)malloc(sizeof(char*) * WIDTH);
		str2 = (char**)malloc(sizeof(char*) * WIDTH);
		break;
	}
	case DIAG2:
	case DIAG1: {
		str1 = (char**)malloc(sizeof(char*) * WIDTH * 2 - 1);
		str2 = (char**)malloc(sizeof(char*) * WIDTH * 2 - 1);
		break;
	}
	default:
		break;
	}

	int count;
	getEvaluateStr(type, str1, str2, &count);
	for (int i = 0; i < count; i++)
	{
		int length = 0;
		int* result = AC_ACSearch(str1[i], &length);

		for (int c = 0; c < length; c++)
		{
			int t = result[c];
			int s = paternScores[t];
			*scores1 += s;
		}
		free(result);
		//temp = str2[i];
		int* result2 = AC_ACSearch(str2[i], &length);
		for (int c = 0; c < length; c++)
		{
			int t = result2[c];
			int s = paternScores[t];
			*scores2 += s;
		}
		free(result2);
	}
	freeAll(str1, count);
	freeAll(str2, count);
}

/*
	��ȡ�ֲ����µ�ָ��λ�������ַ����� 
	type:���ͣ�col,row,diag1,diag2��
	str1:Player���ַ���
	str2:Computer���ַ�����2->1;1->2��
*/
void getUpdateStr(int x, int y, int type, char* str, char* str2) {

	int strLength = 0;
	switch (type)
	{
	case COL:
		for (int i = 0; i < WIDTH; i++) {
			char ch = board[x][i];
			char c1 = ch,
				c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
			str[i] = c1;
			str2[i] = c2;
			strLength++;
		}
		str[strLength] = '\0';
		str2[strLength] = '\0';
		return;
	case ROW:
		for (int i = 0; i < WIDTH; i++) {
			char ch = board[i][y];
			char c1 = ch,
				c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
			str[i] = c1;
			str2[i] = c2;
			strLength++;
		}
		str[strLength] = '\0';
		str2[strLength] = '\0';
		return;
	case DIAG1: {

		for (int i = x - (x > y ? y : x), c = y - (x > y ? y : x), t = 0; i < WIDTH && c < WIDTH; i++, c++, t++) {
			char ch = board[i][c];
			char c1 = ch ,
				c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
			str[t] = c1;
			str2[t] = c2;
			strLength++;
		}
		str[strLength] = '\0';
		str2[strLength] = '\0';
		return;
	}
	case DIAG2: {
		int dt = WIDTH - 1 - x;
		for (int i = x + (y > dt ? dt : y), c = y - (y > dt ? dt : y), t = 0; i >= 0 && c < WIDTH; i--, c++, t++) {
			char ch = board[i][c];
			char c1 = ch ,
				c2 = ch == EMPTY ? EMPTY : (ch == COMPUTER ? PLAYER : COMPUTER);
			str[t] = c1;
			str2[t] = c2;
			strLength++;
		}
		str[strLength] = '\0';
		str2[strLength] = '\0';
		return;
	}
	default:
		throw "type ERROR";
		return;
	}
}

/*
	��ȡ�ֲ����·���
	str1:Player���ַ���
	str2:Computer���ַ�����2->1;1->2��
	scores1:Player�ķ���
	scores2:Computer�ķ���
*/
void getUpdateScores(char* str1, char* str2, int* scores1, int* scores2) {
	int length = 0;
	int* result = AC_ACSearch(str1, &length);
	for (int i = 0; i < length; i++)
	{
		*scores1 += paternScores[result[i]];
	}
	result = AC_ACSearch(str2, &length);
	for (int i = 0; i < length; i++)
	{
		*scores2 += paternScores[result[i]];
	}
}

/*
	[Public]ȫ������������ڣ�ȫ��ƥ�䣩
	role:��ɫ��Player/Computer��
*/
int evaluateAll(int role) {
	int all = 0;
	for (int i = 0; i < 4; i++)
	{
		int scores1 = 0,scores2 = 0;
		getEvaluateScores(i, &scores1, &scores2);
		all += (role == PLAYER ? scores1 : scores2);
		all -= (role == PLAYER ? scores2 : scores1);
	}
	return all;
}

/*
	[Public]ȫ�������������(�ֲ�����)(��ʱ����)
	role:��ɫ��Player/Computer��
*/
int evaluate(int role) {
	int s = scoreAll[1];
	return (role == COMPUTER ? scoreAll[1] : scoreAll[0]);
}

/*
	[Public]�ֲ����·���(��BUG��������)
	scores1:Player�ķ���
	scores2:Computer�ķ���
	isBack��	0:��ȡ�����(����scores1,scores2)
			1:ɾ��(scores1,scores2)
			2:��ӣ�scores1,scores2��
*/
void updateScores(int x,int y,int *scores1,int *scores2, int isBack) {
	if (isBack == 1) {
		scoreAll[0] -= *scores1;
		scoreAll[1] -= *scores2;
		return;
	}
	else if (isBack == 2) {
		scoreAll[0] += *scores1;
		scoreAll[1] += *scores2;
	}
	int lineScore[4];//Player
	int line1Score[4];//Computer
	memset(lineScore, 0, sizeof(lineScore));
	memset(line1Score, 0, sizeof(line1Score));


	//�������
	for (int i = 0; i < 4; i++) {
		int s1 = 0, s2 = 0;
		char str1[WIDTH + 1], str2[WIDTH + 1];
		getUpdateStr(x, y, i, str1, str2);
		getUpdateScores(str2, str1, &s1, &s2);
		lineScore[i] += s1;
		line1Score[i] += s2;
	}
	for (int i = 0; i < 4; i++) {
		*scores1 += lineScore[i];
		*scores2 += line1Score[i];
	}

	scoreAll[0] += *scores1;
	scoreAll[1] += *scores2;
}

/*
	[Public]������Ϸ
*/
void reloadGame() {
	for (int i = 0; i < WIDTH; i++) {
		for (int c = 0; c < WIDTH; c++) {
			board[i][c] = EMPTY;
		}
	}

	clickPointCount = 0;
	scoreAll[0] = 0;
	scoreAll[1] = 0;
	reloadWinner();
}

