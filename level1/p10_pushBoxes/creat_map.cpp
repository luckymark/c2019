#include<iostream>
#include<windows.h>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<ctime>
#include<fstream>

using namespace std;

#define FILE "gamemap.dat"

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
int pos; 
int res_map[1000][1000];
int set_len,fa[10000007],rank[10000007];

int tfind(int x){return x == fa[x]?x:fa[x] = tfind(fa[x]);}	

void vector_swap(int x){
	pos--;
	swap(edges[x],edges[pos]);
}

int get_rand(){                            //随机取边 
	int now = pos,rand_num;
	srand(int(time(0)));
	rand_num = rand()%now;
	return rand_num;
}

void creat_map(int w,int h){       //Kruskal算法生成迷宫 
	w = 2*w + 2,h = 2*h+2;
	int tmp_map[h+1][w+1];
	edges.clear();
	point_set.clear();
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
}

void print_map(int w,int h){
    w = 2*w + 2,h = 2*h+2;
    for(int i = 0;i<=h;i++){
		for(int j = 0;j<=w;j++){
			if(res_map[i][j] == 1) cout<<"#";
			else cout<<" ";
		}
		cout<<endl;
	}
}

int main(){
	fstream mapfile(FILE,ios::in|ios::out|ios::trunc);
	fstream mapdata("mapdata.dat",ios::out|ios::trunc);
	int w = 5,h = 3;
	int tw,th;
	for(int i = 1;i<10;i++){
		creat_map(w,h);
		print_map(w,h);
		tw = 2*(w+1);
		th = 2*(h+1);
		for(int j = 0;j<=th;j++){
		    for(int k = 0;k<=tw;k++){
			    mapfile << res_map[j][k] <<" ";
		    }
	    }
	    mapdata << tw <<" " << th <<endl;
	    w++,h++;
	    mapfile<<endl;
	}
	mapdata.close();
	mapfile.close();
	return 0;
}