#define ESC 27
#define LEFT 75
#define UP 80
#define RIGHT 77
#define DOWN 72


int transKeyval(int keyVal)
{
	switch (keyVal)
	{
		case 75:
			return 0;
		case 72:
			return 3;
		case 77:
			return 2;
		case 80:
			return 1;
	}
}
