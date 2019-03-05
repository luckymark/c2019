/*
随机 Prim 算法步骤：
令迷宫每个格子四周都有墙
随机选一个格子加入未被访问的格子列表中
当列表非空时
	从中随机选取一个格子并将其从表中移除
	依次检测该格子四周的格子有无被访问过
		若有格子被访问过
			则打通与该格子之间的墙（若周围有多个被访问过的格子就随机打通一面）
		若有格子未被访问过
			则将未被访问的格子加入列表中
*/

#include <cstdio>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class Pot {
public:
	int r;		// row
	int c;		// column
	
	Pot(int row, int col) { r = row; c = col; }
	void operator=(const Pot &p) { r = p.r; c = p.c; }
};

class Cell {
public:
	bool visited = false;	// 指示是否被访问过
	bool up = false;		// 指示能否从该格向上走
	bool down = false;
	bool left = false;
	bool right = false;

	Cell() { visited = up = down = left = right = false; }
	void print(int flat) {
		if (1 == flat) {
			printf("%c%c", 0xa8, 0x80);
			if (up)
				printf("  ");
			else
				printf("%c%c", 0xa8, 0x80);
			printf("%c%c", 0xa8, 0x80);
		}
		else if (2 == flat) {
			if (left)
				printf("  ");
			else
				printf("%c%c", 0xa8, 0x80);
			printf("  ");
			if (right)
				printf("  ");
			else
				printf("%c%c", 0xa8, 0x80);
		}
		else if (3 == flat) {
			printf("%c%c", 0xa8, 0x80);
			if (down)
				printf("  ");
			else
				printf("%c%c", 0xa8, 0x80);
			printf("%c%c", 0xa8, 0x80);
		}
	}
};

Cell **ppcells = 0;		// 所有格子
int ROW, COL;		// 迷宫的行列数
Pot man(0, 0);		// 玩家

void createMaze() {	
	ppcells = new Cell *[ROW];
	for (int i = 0; i < ROW; ++i)
		ppcells[i] = new Cell[COL];
	Pot p(0, 0);		// 临时变量点
	vector<Pot> stack(1, p);	// 未访问过的格子位置
	srand((unsigned int)time(0));

	int index;						// 数组索引
	vector<char> direction;			// 格子的允许方向
	while (!stack.empty()) {
		index = rand() % stack.size();
		p = stack.at(index);
		stack.erase(stack.begin() + index);
		ppcells[p.r][p.c].visited = true;		// 标记该格为已访问过
		
		if (p.c > 0)
			if (ppcells[p.r][p.c - 1].visited)
				direction.push_back('L');
			else
				stack.push_back(Pot(p.r, p.c - 1));
		if (p.r > 0)
			if (ppcells[p.r - 1][p.c].visited)
				direction.push_back('U');
			else
				stack.push_back(Pot(p.r - 1, p.c));
		if (p.c < COL - 1)
			if (ppcells[p.r][p.c + 1].visited)
				direction.push_back('R');
			else
				stack.push_back(Pot(p.r, p.c + 1));
		if (p.r < ROW - 1)
			if (ppcells[p.r + 1][p.c].visited)
				direction.push_back('L');
			else
				stack.push_back(Pot(p.r + 1, p.c));

		if(!direction.empty())
			switch (direction[rand() % direction.size()]) {
			case 'L':
				ppcells[p.r][p.c--].left = true;
				ppcells[p.r][p.c].right = true;
				break;
			case 'U':
				ppcells[p.r--][p.c].up = true;
				ppcells[p.r][p.c].down = true;
				break;
			case 'R':
				ppcells[p.r][p.c++].right = true;
				ppcells[p.r][p.c].left = true;
				break;
			case 'D':
				ppcells[p.r++][p.c].down = true;
				ppcells[p.r][p.c].up = true;
			}
		direction.clear();
	}
	int i;
	for (i = 0; i < ROW; ++i) {				// 确保迷宫四周边框没有其他出口
		ppcells[i][0].left = false;
		ppcells[i][COL - 1].right = false;
	}
	for (i = 0; i < COL; ++i) {
		ppcells[0][i].up = false;
		ppcells[ROW - 1][i].down = false;
	}
	ppcells[0][0].left = true;					// 左上角为入口
	ppcells[ROW - 1][COL - 1].right = true;		// 右下角为出口
}

void printMaze() {
	int flat;		// 每个格子映射成 3*3 的格子，分三层输出
	int i, j;		// 循环变量
	for(i = 0; i < man.r; ++i)					// 输出玩家所映射的三行之前的迷宫
		for (flat = 1; flat < 4; ++flat) {
			for (j = 0; j < COL; ++j)
				ppcells[i][j].print(flat);
			printf("\n");
		}
	for (j = 0; j < COL; ++j)					// 输出玩家所映射的三行迷宫
		ppcells[i][j].print(1);
	for (j = 0; j < man.c; ++j)
		ppcells[i][j].print(2);
	if (ppcells[i][j].left)
		printf("  ");
	else
		printf("%c%c", 0xa8, 0x80);
	printf("%c%c", 0xa7, 0xb0);		// 输出个圈当玩家
	if (ppcells[i][j].right)
		printf("  ");
	else
		printf("%c%c", 0xa8, 0x80);
	while (++j < COL)							
		ppcells[i][j].print(2);
	for (j = 0; j < COL; ++j)
		ppcells[i][j].print(3);
	while (++i < ROW)							// 输出玩家所映射的三行之后的迷宫
		for (flat = 1; flat < 4; ++flat) {
			for (j = 0; j < COL; ++j)
				ppcells[i][j].print(flat);
			printf("\n");
		}
}

void moveMan(int key) {
	switch (key) {
	case 72:	// 上
		if (man.r > 0 && ppcells[man.r][man.c].up && ppcells[man.r - 1][man.c].down)
			--man.r;
		break;
	case 80:	// 下
		if (man.r < ROW - 1 && ppcells[man.r][man.c].down && ppcells[man.r + 1][man.c].up)
			++man.r;
		break;
	case 75:	// 左
		if (man.c > 0 && ppcells[man.r][man.c].left && ppcells[man.r][man.c - 1].right)
			--man.c;
		break;
	case 77:	// 右
		if (man.c < COL - 1 && ppcells[man.r][man.c].right && ppcells[man.r][man.c + 1].left)
			++man.c;
	}
}

int main() {
	// 考虑控制台窗口长宽会影响迷宫输出显示，因此固定迷宫和窗口的长宽
	ROW = COL = 20;
	system("mode con lines=120 cols=120");
	createMaze();		// 生成迷宫
	printMaze();		// 输出迷宫
	while (true) {
		if (_getch() == 0xe0)	// 前一个键值为 0xe0 时才有可能是按下方向键
			moveMan(_getch());
		system("cls");
		printMaze();
		if ((ROW - 1 == man.r)&&(COL - 1 == man.c)) {
			printf("\n\n######################  You win!  ######################\n\n");
			break;
		}
	}
	system("pause");
	return 0;
}
