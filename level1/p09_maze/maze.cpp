#include<iostream>
#include<windows.h>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<set>
#include<list>
#include<vector>
#include<ctime>

using namespace std;

#define W 160
#define H 40

struct edge{
	int from,to,posx,posy;
	edge(int u,int v,int a,int b):from(u),to(v),posx(a),posy(b){}
};

struct point{
	int x,y;
	point(int h,int w):x(h),y(w){}
};

vector<edge> edges;
vector<point> point_set;
int start_w,start_h,pos; 
int res_map[1000][1000];
int dirx[4] = {-1,0,1,0};
int diry[4] = {0,-1,0,1};
int set_len,fa[10000007],rank[10000007];
string s[7] = {"Welcome to Decision's maze!","You can use WASD to move.","Press 1 to chose Simple Mode(Smallest map).","Press 2 to chose Ordinary Mode(Small map).",
               "Press 3 to chose Middle Mode(Large map).","Press 4 to chose Hard Mode(The largest map).",
               "Press 5 to exit."};
string con_information[3] = {"CONGRATULATIONS!","You are out of the maze!","Press 1 to menu."};

/*---------------------------------------自定义变量及头部文件结束---------------------------------------*/ 
    
int tfind(int x){return x == fa[x]?x:fa[x] = tfind(fa[x]);}	

void pre_init(){system("mode con cols=160 lines=40");}

void vector_swap(int x){
	pos--;
	swap(edges[x],edges[pos]);
}


int get_keynum(){                          //获取按下的数字按键 
	while(1){
		for(int i = 1;i<=5;i++){
			if(GetKeyState(i+48)&0x8000){
				return i;
			}
		}
	}
}

char get_key(){                            //获取按下的字母方向 
	char ss[] = "WASD";
	while(1){
		for(int i = 0;i<4;i++){
			if(GetKeyState(ss[i])&0x8000){
				return i;
			}
		}
	}
}
	           
int get_rand(){                            //随机取边 
	int now = pos,rand_num;
	srand(int(time(0)));
	rand_num = rand()%now;
	return rand_num;
}

void gotoxy(int posx,int posy){            //光标跳转用于局部清除 
	COORD CUR;
	HANDLE hout;
	CUR.X = posy;
	CUR.Y = posx;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,CUR);
}

vector<point> creat_map(int w,int h){       //Kruskal算法生成迷宫 
	w = 2*w + 2,h = 2*h+2;
	int tmp_map[h+1][w+1];
	vector<point> res;
	for(int i = 0;i<=h;i++) for(int j = 0;j<=w;j++) res_map[i][j] = 1;
	
	for(int i = 1;i<h;i+=2){
		for(int j = 1;j<w;j+=2)
		{
			res_map[i][j] = 0;
		    tmp_map[i][j] = point_set.size();
		    point_set.push_back(point(i,j));
		}
    }
    
    set_len = point_set.size();
    for(int i = 0;i<set_len;i++) fa[i] = i,rank[i] = 1;
    for(int i = 1;i<=h;i+=2){
    	for(int j = 1;j<=w;j+=2){
    		if(i+2<=h) edges.push_back(edge(tmp_map[i][j],tmp_map[i+2][j],i+1,j));
    		if(j+2<=w) edges.push_back(edge(tmp_map[i][j],tmp_map[i][j+2],i,j+1));
		}
	}
	set_len = pos = edges.size();
	while(set_len){
		int now = get_rand(),from,to;
		edge t = edges[now];
		from = tfind(t.from),to = tfind(t.to);
		if(from != to){
			if(rank[from] > rank[to]) fa[to] = from;
			else fa[from] = to;
			res_map[t.posx][t.posy] = 0; 
		}
		set_len--;
		vector_swap(now);
	}
	bool flag = 0;
	for(int i = 1;i<w;i++){
		if(flag) break;
		for(int j = w-1;j>=1;j--){
			if(res_map[1][i] == 0&&res_map[h-1][j] == 0 && tfind(tmp_map[1][i]) == tfind(tmp_map[h-1][j]))
			{
				flag = 1;
				res.push_back(point(0,i));
				res.push_back(point(h,j));
				res_map[0][i] = res_map[h][j] = 0;
				break;
			}
		}
	}
	return res;
}

void print_information(string* ss,int num){               //传入字符串数组及个数,并在屏幕中央打印 
    system("cls");
	int maxx = 0,len;
	for(int i = 0;i<num;i++) len = ss[i].length(),maxx = max(len,maxx);
	start_w = (W - maxx) / 2;
	start_h = (H - num*2) / 2;
	for(int i = 1;i<=H;i++){
		if(i == start_h){
			for(int k = 0;k<num;k++){
				int tmp = start_w + maxx+1;
				for(int l = 1;l<=W;l++){
					if(l==start_w - 2||l==tmp + 2) cout<<"#";
					else if(l==start_w+1) cout<<ss[k],l+=ss[k].length() - 1;
					else cout<<" ";
				}
				cout<<endl;
				for(int l = 1;l<=W;l++){
					if(l==start_w - 2||l==tmp + 2) cout<<"#";
					else cout<<" ";
				}
				cout<<endl;
			}
			i+=2*num;
		}
		else if(i == start_h + 2*num + 1 || i == start_h-1){
			for(int j = 1;j<=W;j++){
				if(j>=start_w - 2&&j<=start_w + maxx + 3) cout<<"#";
				else cout<<" ";
			}
			cout<<endl;
		}
		else cout<<endl;
		
	}
}

void print_map(int posx,int posy,int w,int h){
    for(int i = 0;i<=h;i++){
		for(int j = 0;j<=w;j++){
			if(i == posx&&j == posy) cout<<"@";
			else if(res_map[i][j] == 1) cout<<"#";
			else cout<<" ";
		}
		cout<<endl;
	}
}

void player_move(int posx,int posy,int dir){
	gotoxy(posx,posy);
	cout<<" ";
	gotoxy(posx + dirx[dir],posy + diry[dir]);
	cout<<"@";
}

void game(int w,int h){
	system("cls");
	vector<point> p = creat_map(w,h);
	w = 2*w + 2,h = 2*h+2;	
	point player = point(p[0].x,p[0].y);
	print_map(player.x,player.y,w,h);
	while(player.x != p[1].x || player.y != p[1].y){
		int dir = get_key();
		int nowx = player.x + dirx[dir],nowy = player.y + diry[dir];
		if(res_map[nowx][nowy] == 0 && nowx>=0 && nowy>=0){
			player_move(player.x,player.y,dir);
			gotoxy(h+1,0);
			player.x = nowx;
			player.y = nowy;
		}
		Sleep(125);
	}
	if(player.x == p[1].x && player.y == p[1].y){
		print_information(con_information,3);
		int t = get_keynum();
		Sleep(125);
		if(t == 1){
			print_information(s,7);
			return ;
		}
	}	
}

void menu(){
	int t = 0;
	while(1){
	    switch(t = get_keynum()){
		    case(1):
		        game(10,5);
		        break;
            case(2):
                game(20,10);
                break;
            case(3):
                game(30,15);
                break;
            case(4):
                game(50,15);
                break;
		    case(5):
			    return ;
	    }
	}

}


int main(){
	pre_init();
	print_information(s,7);
	menu();
	return 0;
}
