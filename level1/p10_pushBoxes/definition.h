#define PLAYER '@'
#define WALL '#'
#define ROAD ' '
#define TRAIL '.'
#define EXIT 'E'
#define BOX '+'
#define TARGET 'o'

#define bufLim 3000

const int W = 81, H = 31;

char G[W+1][H];

int DX[4] = {-1, 0, 1, 0};
int DY[4] = {0, 1, 0, -1};


struct Object
{
	int x, y;
	char symbol;
	bool filled;
	Object set(int posX, int posY, char ch)
	{
		x = posX, y = posY;
		symbol = ch;
		filled = 0;
	}
	bool canMove(int dir)
	{
		return G[x + DX[dir]][y + DY[dir]] != WALL;
	}
	void move(int dir)
	{
		x += DX[dir], y += DY[dir];
	}
	void draw(char ch)
	{
		G[x][y] = ch;
	}
};

bool cmpPos(Object a, Object b)
{
	return a.x == b.x && a.y == b.y;
}

Object player;


vector<Object> box;

int boxFilled = 0, boxTotal = 0;

int getBoxID(int x, int y)
{
	for (int s = 0; s < box.size(); s++)
		if (x == box[s].x && y == box[s].y)
			return s;
	return -1;
}
