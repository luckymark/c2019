#define PLAYER '@'
#define WALL '#'
#define ROAD ' '
#define TRAIL '.'
#define EXIT 'E'

const int W = 81, H = 31;

char G[W+1][H];

int DX[4] = {-1, 0, 1, 0};
int DY[4] = {0, 1, 0, -1};


struct Object
{
	int x, y;
	char symbol;
	Object set(int posX, int posY, char ch)
	{
		x = posX, y = posY;
		symbol = ch;
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

int vis[W][H];
