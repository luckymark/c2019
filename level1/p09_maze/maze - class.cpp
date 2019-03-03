#include<iostream>
#include<windows.h>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<ctime>
#include<conio.h>

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


//声明迷宫地图类，可以调用函数用于刷新及打印地图 
class MazeMap{
private:
    int pos,set_len;
    int Map[500][500];
	int fa[100000],rank[100000];
    vector<edge> edges;
    vector<point> point_set;
    
    //内部并查集、交换元素、取边函数 
    int tfind(int x){
	    return x == fa[x]?x:fa[x] = tfind(fa[x]);
    }	
    
    void vector_swap(int x){
	    pos--;
	    swap(edges[x],edges[pos]);
    }
    
    int get_rand(){                  
	    int now = pos,rand_num;
	    srand(int(time(0)));
	    rand_num = rand()%now;
        return rand_num;
    }
public:
    //Kruskal算法生成迷宫 
    vector<point> refresh(int w,int h){ 
	    edges.clear();
	    point_set.clear();
	    w = 2*w + 2,h = 2*h+2;
	    int tmp_map[h+1][w+1];
	    vector<point> res;
	    for(int i = 0;i<=h;i++){
    		for(int j = 0;j<=w;j++){
		    	Map[i][j] = 1;
		    }
    	}
	    for(int i = 1;i<h;i+=2){
		    for(int j = 1;j<w;j+=2)
		    {
			    Map[i][j] = 0;
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
	    
	    set_len = edges.size();
	    pos = edges.size();
	    
	    while(set_len){
		    int now = get_rand(),from,to;
		    edge t = edges[now];
		    from = tfind(t.from),to = tfind(t.to);
		    if(from != to){
			    if(rank[from] > rank[to]) fa[to] = from;
			    else fa[from] = to;
			    Map[t.posx][t.posy] = 0; 
		    }
	    	set_len--;
		    vector_swap(now);
	    }
	    bool flag = 0;
	    for(int i = 1;i<w;i++){
		    if(flag) break;
		    for(int j = w-1;j>=1;j--){
			    if(Map[1][i] == 0&&Map[h-1][j] == 0 && tfind(tmp_map[1][i]) == tfind(tmp_map[h-1][j]))
			    {
				    flag = 1;
				    res.push_back(point(0,i));
				    res.push_back(point(h,j));
				    Map[0][i] = Map[h][j] = 0;
				    break;
			    }
		    }
	    }
	    return res;
    }
    
    //打印地图 
    void Show(int posx,int posy,int w,int h){
        for(int i = 0;i<=h;i++){
		    for(int j = 0;j<=w;j++){
			    if(i == posx&&j == posy) cout<<"\033[31m"<<"@";
			    else if(Map[i][j] == 1) cout<<"\033[32m" <<"#";
			    else cout<<" ";
		    }
		    cout<<endl;
	    }
    }
    
    int Get(int posx,int posy){
    	return Map[posx][posy];
    }
};

int dirx[4] = {-1,0,1,0};
int diry[4] = {0,-1,0,1};
int start_w,start_h,pos; 
string s[7] = {"Welcome to Decision's maze!","You can use WASD to move.","Press 1 to chose Simple Mode(Smallest map).","Press 2 to chose Ordinary Mode(Small map).",
               "Press 3 to chose Middle Mode(Large map).","Press 4 to chose Hard Mode(The largest map).",
               "Press 5 to exit."};
string con_information[3] = {"CONGRATULATIONS!","You are out of the maze!","Press 1 to menu."};

//设置控制台大小 
void preInit(){
	system("mode con cols=160 lines=40");
}

//光标跳转用于局部清除 
void Gotoxy(int posx,int posy){            
	COORD CUR;
	HANDLE hout;
	CUR.X = posy;
	CUR.Y = posx;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,CUR);
}

//玩家移动 
void PlayerMove(int posx,int posy,int dir){
	Gotoxy(posx,posy);
	cout<<" ";
	Gotoxy(posx + dirx[dir],posy + diry[dir]);
	cout<<"\033[1m\033[31m"<<"@";
}

//传入字符串数组及个数,并在屏幕中央打印 
void PrintInformation(string* ss,int num){               
    system("cls");
	int maxx = 0,len;
	for(int i = 0;i<num;i++){
		len = ss[i].length();
		maxx = max(len,maxx);
	}
	start_w = (W - maxx) / 2;
	start_h = (H - num*2) / 2;
	for(int i = 1;i<=H;i++){
		if(i == start_h){
			for(int k = 0;k<num;k++){
				int tmp = start_w + maxx+1;
				for(int l = 1;l<=W;l++){
					if(l==start_w - 2||l==tmp + 2) cout<<"\033[1m\033[31m"<<"#";
					else if(l==start_w+1) cout<<"\033[1m\033[31m"<<ss[k],l+=ss[k].length() - 1;
					else cout<<" ";
				}
				cout<<endl;
				for(int l = 1;l<=W;l++){
					if(l==start_w - 2||l==tmp + 2) cout<<"\033[1m\033[31m"<<"#";
					else cout<<" ";
				}
				cout<<endl;
			}
			i+=2*num;
		}
		else if(i == start_h + 2*num + 1 || i == start_h-1){
			for(int j = 1;j<=W;j++){
				if(j>=start_w - 2&&j<=start_w + maxx + 3) cout<<"\033[1m\033[31m"<<"#";
				else cout<<" ";
			}
			cout<<endl;
		}
		else cout<<endl;
		
	}
}

//获取移动方向 
int GetDir(){
	char c = getch();
	if(c == 'w') return 0;
	else if(c == 'a') return 1;
	else if(c == 's') return 2;
	else if(c == 'd') return 3;
}

//游戏主函数 
void game(int w,int h){
	system("cls");
	MazeMap Maze;
	vector<point> p = Maze.refresh(w,h);
	w = 2*w + 2,h = 2*h+2;	
	point player = point(p[0].x,p[0].y);
	Maze.Show(player.x,player.y,w,h);
	while(player.x != p[1].x || player.y != p[1].y){
		int dir = GetDir();
		int nowx = player.x + dirx[dir],nowy = player.y + diry[dir];
		if(Maze.Get(nowx,nowy) == 0 && nowx>=0 && nowy>=0){
			PlayerMove(player.x,player.y,dir);
			Gotoxy(h+1,0);
			player.x = nowx;
			player.y = nowy;
		}
		Sleep(125);
	}
	if(player.x == p[1].x && player.y == p[1].y){
		PrintInformation(con_information,3);
		char t;
		t = getch();
		Sleep(125);
		if(t == '1'){
			PrintInformation(s,7);
			return ;
		}
	}	
}

//菜单栏 
void menu(){
	int t;
	while(1){
		t = getch();
	    switch(t){
		    case(49):
		        game(10,5);
		        break;
            case(50):
                game(20,10);
                break;
            case(51):
                game(30,15);
                break;
            case(52):
                game(50,15);
                break;
		    case(53):
			    return ;
	    }
	}
}

int main(){
	preInit();
	PrintInformation(s,7);
	menu();
	return 0;
}
