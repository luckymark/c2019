// I don't know if I set the target in my own account successfully

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<time.h> 
#include<conio.h>
int map[100][100];  // 0 is road ,1 is block, 3 is person, 2 is terminal 
int n=11,m=20;
#define alpha (1)
#define beta 60
#define sleep_time 5000
void sleep(){
	for(int i=1;i<sleep_time;i++);
	return ;
}
int random(int l,int r){
	return rand()%(r-l+1) +l; 
}
void print(){
	printf("Please use UP, DWON, LEFT and RIGHT to go out of the maze\nYou are in ● and the exit is □\n\n");
	for(int i=0;i<=n*2;i++){
		for(int j=0;j<=m*2;j++)
			if (map[i][j]==1) printf("█");   //because space should be a two-char ,so it can't be put in a map of char;
			else if (map[i][j]==0) printf("  ");       // so I can only use if and else
			else if (map[i][j]==2) printf("□");       // exit 
			else if (map[i][j]==3) printf("●");       // player
		printf("\n");
	}
}

void build(int up,int dn,int lt,int rt){   // build the maze by divide it into two part and connet these two part
	if(up==dn&&lt==rt) return;             // and then build that two part in the same way 
	int d=random(0,1);
	if ( (dn-up)>=(rt-lt)*alpha ) d=1;
	if ( (rt-lt)>=(dn-up)*alpha ) d=0;
	if (up==dn) d=0;
	if (lt==rt) d=1;
	if ( d  ){
		int d1=random(up,dn-1);
		int d2=random(lt,rt);
		map[d1*2][d2*2-1]=0;
		build(up,d1,lt,rt);
		build(d1+1,dn,lt,rt);		
	}
	if ( !d ){
		int d1=random(lt,rt-1);
		int d2=random(up,dn);
		map[d2*2-1][d1*2]=0;
		build(up,dn,lt,d1);
		build(up,dn,d1+1,rt); 
	}
//	if (dn-up>=2&&rt!=m&&rt-lt>=2&&dn!=n)    // make the map be a forest but not a single tree , and the bigger beta is ,the more trees is would be
//		if (random(1,100)<beta) 
//			map[(dn+up)/2*2-1][(rt+lt)/2*2]=0;
	return ;
}

int player_x,player_y,exit_x,exit_y;

void init_maze(){
	srand( (unsigned)time( NULL ) ); 
	for(int i=0;i<=n*2;i++)  //the cell is in (i*2-1,j*2-1)
		for(int j=0;j<=m*2;j++){
			if(i%2+j%2==2) map[i][j]=0;
			else map[i][j]=1;	
		}
	build(1,n,1,m);
//	build(1,n,1,m);    if I use the funtion twice , the maze will be easier to solve and the map won't look like a " tree "
	player_x=random(1,n/2-1)*2-1;
	player_y=random(1,m/2-1)*2-1;
	exit_x=random(n/2,n)*2-1;
	exit_y=random(m/2,m)*2-1;
	map[player_x][player_y]=3;
	map[exit_x][exit_y]=2;
	return ;	
}
int mov[5][2]={{0,0},{1,0},{-1,0},{0,-1},{0,1}};
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
int move(int d){ // d is short for direction
	int nx=player_x+mov[d][0];
	int ny=player_y+mov[d][1];
	if (nx>=0&&nx<=2*n)
	if (ny>=0&&ny<=2*m)
		if (map[nx][ny]!=1){
			if (map[nx][ny]==2) return 1;  // success
			map[player_x][player_y]=0;
			player_x=nx; player_y=ny; 
			map[player_x][player_y]=3;
		}
	return 0;
}
void game_start(){
	init_maze();
	print();
	int success=0;
	while(!success){
		success=move( get_d() );
		system("cls");
		print();
		sleep();
	}
	sleep();sleep();sleep();
	system("cls");
	printf("YOU WIN !!!");
	return;
}
int main(){
	game_start();
	return 0;
} 
