#include "maze.h"
void mapping(){    //打印新生成的迷宫 
	char map[9][20]={{"# ##################"},
					 {"#   #     ##   #    "},
					 {"### ##  ###  # # ###"},
					 {"### #    ##  #   ###"},
					 {"### # ## ## # ###  #"},
					 {"# # ## ##   ###   ##"},
					 {"# #  ## ###  ####  #"},
					 {"####          ##   #"},
					 {"####################"}};
	int x=0,y=1;
	int *px=&x;
	int *py=&y; 

	void cursor(){        //光标 键盘方向键 
		char c=getch();
		switch(c){
			case 72:move_1(map,px,py);
					break;
			case 80:move_2(map,px,py);
					break;	
			case 75:move_3(map,px,py);
					break;
			case 77:move_4(map,px,py);
					break;	 			
			default: break;
			}
		}
	
	
	map[x][y]='o';
	while(map[1][19]!='o'){
		int i,j;
		for(i=0;i<9;i++){
			for(j=0;j<20;j++){
				printf("%c",map[i][j]);
			}
			printf("\n");
		}
		cursor();
		system("cls");
	}
		
}
