#include "push.h"//��һ����ָ��ָ���ά�������ʲô���أ�nά�أ� 
int score=0;
int line=0; int row=0;
int stars=0;
int maze(int n){
	int mark=1;
	score=0;
	line=0; row=0;
	stars=0;
/*	char mapp[50][50]={"##########",
					   "##     ###",
                       "##o###   #",
                       "# s o  o #",
                       "# **# o ##",
                       "##**#   ##",
                       "##########",};*/
//	char *pmap=&mapp;
	char mapp[50][50];
	int i1, j1;
	for(i1=0;i1<50;i1++){
		for(j1=0;j1<50;j1++){
			mapp[50][50]=' ';
		}
	}
	get_map(n,mapp);//�����ͼ 
	map(mapp); //��ӡ��ʼ��ͼ 
	int s_x;int s_y; char ch;//�õ��˵ĳ�ʼ���� 
	
	for(i1=0;i1<row;i1++){
		for(j1=0;j1<line;j1++){
			if(mapp[i1][j1]=='s'){
				s_x=i1;
				s_y=j1;
			}
		}
	}
	stars=get_stars(mapp);//�õ��м���Ŀ��λ�� 
	int s_xst[stars], s_yst[stars];
	get_lc(s_xst,s_yst,mapp);
	int* px=&s_x; int *py=&s_y;
	int step=0;
	while(judge(s_xst,s_yst,mapp)!=stars){
//		printf("\n%d %d\n",judge(s_xst,s_yst,mapp),stars);
		printf("you have already took %d steps\n",step);
		printf("Score:%d",score+judge(s_xst,s_yst,mapp)*50);	
		ch=getch();
		if(ch=='q'){//�ж���Ϸ�Ƿ�Ҫ����������ȥ 
			mark=0;
			break;
		}
		if(ch=='r'){
			break;
		}
		ch=getch();
		step++;score--;
		 switch(ch) { 
				case 72://up
					move(1,px,py,mapp);
					break;
				case 80://down
					move(2,px,py,mapp);
					break;
				case 75://left
					move(3,px,py,mapp);
					break;
				case 77://right
					move(4,px,py,mapp);
					break;
				default:
					break;
				
		}
		system("cls");
		checkstar(s_xst,s_yst,mapp);
		map(mapp);
		
	}
	system("cls");
	if(mark==1){
		printf("work out\nScore:%d\nsteps:%d",score+400,step);
		system("pause");
	}
	return mark;
	
}
	

