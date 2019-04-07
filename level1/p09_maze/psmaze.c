#include "maze.h" 
void maze(){
	char mapp[50][50]={"HHHHHHHHHH",
					   "o  HH     ",
					   "H HH HH HH",
					   "H  HH H HH",
					   "H  H H  HH",
					   "H H HH HHH",
					   "H        H",
					   "HHHHHHHHHH"};
//	char *pmap=&mapp;
	map(mapp);
	int a=1;int b=0; char ch;
	int* pa=&a; int *pb=&b;
	while(a!=1||b!=9){
		ch=getch();
		ch=getch();
		 switch(ch) { 
				case 72://up
					move(1,pa,pb,mapp);
					break;
				case 80://down
					move(2,pa,pb,mapp);
					break;
				case 75://left
					move(3,pa,pb,mapp);
					break;
				case 77://right
					move(4,pa,pb,mapp);
					break;
				default:
					break;
				
		}
		system("cls");
		map(mapp);
		
	}
	system("cls");
	printf("work out");
	
}
	


