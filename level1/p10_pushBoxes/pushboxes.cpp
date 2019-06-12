//  □ stand for box      v==1
//  ■ stand for player   v==2
//  ○ stand for the place the box should be put in   v===3
//  ● stand for the place with a box in it     v==4
//  █ stand for block       v==5
#include<cstdio>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
const int maxn=20;
int get_d(){
	char ch=getch();
	if (ch==-32){
		ch=getch();
		if (ch==72) return 2;
		if (ch==80) return 1;
		if (ch==75) return 3;
		if (ch==77) return 4;
		return 0;
	}
	return 0;	
}
int mov[5][2]={{0,0},{1,0},{-1,0},{0,-1},{0,1}};
struct pushbox{
	int map[maxn][maxn];
	int width,height;
	int length,sumlength,score;
	int remain;
	int player_x,player_y;
	void init(){
		remain=0;
		for(int i=1;i<=height;i++)
			for(int j=1;j<=width;j++) {
				if(map[i][j]==1) remain++;
				if(map[i][j]==2) {player_x=i,player_y=j;}
			} 
	}
	void print(){
		for(int i=1;i<=height;i++){
			for(int j=1;j<=width;j++)
				if (!map[i][j]) printf("  ");
				else if (map[i][j]==1) printf("□");   
				else if (map[i][j]==2) printf("■");     
				else if (map[i][j]==3) printf("○");       
				else if (map[i][j]==4) printf("●");
				else if (map[i][j]==5) printf("█");     
			printf("\n");
		}
	} 
	int one_step(int d){
		int nx=player_x+mov[d][0];
		int ny=player_y+mov[d][1];
		if (nx>=1&&nx<=height)
		if (ny>=1&&ny<=width) 
		if (map[nx][ny]!=5&&map[nx][ny]!=4&&map[nx][ny]!=3)
				if (map[nx][ny]==0) {map[nx][ny]=2;map[player_x][player_y]=0;player_x=nx;player_y=ny;}
				if (map[nx][ny]==1){
					int nnx=nx+mov[d][0],nny=ny+mov[d][1];
					if (nnx>=1&&nnx<=height)
					if (nny>=1&&nny<=width)
						if (map[nnx][nny]==0) { map[nx][ny]=2;map[nnx][nny]=1;map[player_x][player_y]=0; player_x=nx;player_y=ny;}
						if (map[nnx][nny]==3) { map[nx][ny]=2;map[nnx][nny]=4;map[player_x][player_y]=0; remain--;player_x=nx;player_y=ny;}
				}
		if (remain) return 0;
		return 1;
	}
	
	void load(int level){
		FILE *fp;
		if (level==1) 	fp = fopen("map1.txt","r");
		if (level==2)   fp = fopen("map2.txt","r");
		if (level==3)   fp = fopen("map3.txt","r");

		fscanf(fp,"%d%d",&width,&height);
		for(int i=1;i<=height;i++)
			for(int j=1;j<=width;j++) fscanf(fp,"%d",&map[i][j]);
		fclose(fp);
	}

	
	
}game;

void game_start(){
	int level=1;
	int success;
	while (level<=3){
		game.load(level);
		game.init(); game.print();
		success=0;
		while (!success){
			success=game.one_step(get_d());
			system("cls");
			game.print();			
		}
		system("cls");
		printf("YOU WIN !!!  Level Up!!!");
		level++; 
	}
}
int main(){
    game_start();
	return 0;
	
}
