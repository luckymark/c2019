#include"head.h"
objects map[MAPLE_X+1][MAPLE_Y+1];
position players;
int main()
{
	cout<<"*号代表墙，+号代表玩家，$号很显然是你的目标 wasd分别是上左下右 按下ENTER开始"<<endl;
	system("pause");
	scan();
	char pt;
	while(1)
	{
		print(); 
		maze_move();
		if(map[P.x][P.y].zt==3)break;
	}
	cout<<endl<<"你赢了";
	return 0;
}


