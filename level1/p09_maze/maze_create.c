// 生成迷宫的方法是在网上找来的方法的基础上添加了随机
// 初始时迷宫中全部是墙
// 选择一系列定点，在其中的一些点之间打通路
//有一个缺陷，到达终点的路不止一条……
//这个算法生成的迷宫太沙雕了
//以后要想办法改进才行
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "maze.h"

#define WALL "▇"
#define ROAD "  "

void hide();

const int bridge_line = LINE/2;
const int bridge_num = (LINE/2)*(LINE/2);

//栈
typedef struct sqstack{
        POINTER *base;    //栈底
        POINTER *top;     //栈顶
        int stack_size; //栈内元素的数量
}SQSTACK;

void maze_create(char mymap[LINE][LINE]){
        void init_map(char mymap[LINE][LINE]);
        void init_bridge(char bridge[LINE/2][LINE/2]);
        void init_bridge_n(POINTER *r);
        void DFS(POINTER bridge_n[bridge_num], char mymap[LINE][LINE], char bridge[bridge_line][bridge_line]);
        void print_map(char mymap[LINE][LINE]);

        //初始化地图
        init_map(mymap);

        //选择一系列定点，我们将这些定点称作桥
        //通过在桥与桥之间建立通道来生成迷宫
        //初始化桥
        char bridge[bridge_line][bridge_line];
        init_bridge(bridge);
        POINTER bridge_n[bridge_num];
        init_bridge_n(bridge_n);

        //深度优先算法生成迷宫
        DFS(bridge_n, mymap, bridge);

        //打印地图
        print_map(mymap);
}

//初始化地图，0表示墙，1表示路
void init_map(char mymap[LINE][LINE]){
        for(int i = 0; i < LINE; ++i){
                memset(mymap[i], 0, sizeof(mymap[i]));
        }
        mymap[1][0] = 1;
        mymap[LINE-2][LINE-1] = 1;
}

//初始化桥，桥的值为0代表未被访问过
void init_bridge(char bridge[bridge_line][bridge_line]){
        for(int i = 0; i < bridge_line; ++i){
                memset(bridge[i], 0, sizeof(bridge[i]));
        }
        bridge[0][0] = 1;
}

//用一系列的结构体，来记录每座桥的坐标
void init_bridge_n(POINTER r[bridge_num]){
        for(int i = 0; i < bridge_num; ++i){
                r[i].x = i/bridge_line;
                r[i].y = i%bridge_line;
        }
}


//深度优先算法生成迷宫
void DFS(POINTER bridge_n[bridge_num], char mymap[LINE][LINE], char bridge[bridge_line][bridge_line]){
        void init_stack(SQSTACK *s);
        void Push(SQSTACK *s, POINTER b);
        int Pop(SQSTACK *s, POINTER *e);

        //建立一个栈并对其初始化
        SQSTACK sta;
        init_stack(&sta);

        //预处理，压栈bridge_n[0]
        Push(&sta, bridge_n[0]);
        mymap[1][1] = 1;

        //栈不空时，从栈顶取出元素，向其四周拓展路径
        POINTER e;  //用来取出栈顶元素
        while(Pop(&sta, &e)){
                int pos[4]; //方位,0为上，1为下，2为左，3为右
                for(int i = 0; i < 4; ++i){
                        srand((unsigned)time(NULL));
                        //生成pos数组中的元素
                        for(;;){
                                pos[i] = rand()%4;
                                //pos数组中的元素不可以相同
                                for(int j = 0; j < i; ++j){
                                        if(pos[i] == pos[j]){goto again;}
                                }
                                break;
                                again:  ;
                        }
                        switch(pos[i]){
                                case 0:if(bridge[e.x-1][e.y]==0 && e.x-1>=0){
                                                mymap[2*e.x-1][2*e.y+1] = 1;
                                                mymap[2*e.x][2*e.y+1] = 1;      //打墙
                                                bridge[e.x-1][e.y] = 1;         //在入栈前标记为已访问
                                                Push(&sta, bridge_n[(e.x-1)*bridge_line+e.y]);
                                        }
                                        break;
                                case 1:if(bridge[e.x+1][e.y]==0 && e.x+1<bridge_line){
                                                mymap[2*e.x+3][2*e.y+1] = 1;
                                                mymap[2*e.x+2][2*e.y+1] = 1;    //打墙
                                                bridge[e.x+1][e.y] = 1;         //在入栈前标记为已访问
                                                Push(&sta, bridge_n[(e.x+1)*bridge_line+e.y]);
                                        }
                                        break;
                                case 2:if(bridge[e.x][e.y-1]==0 && e.y-1>=0){
                                                mymap[2*e.x+1][2*e.y-1] = 1;
                                                mymap[2*e.x+1][2*e.y] = 1;      //打墙
                                                bridge[e.x][e.y-1] = 1;         //在入栈前标记为已访问
                                                Push(&sta, bridge_n[e.x*bridge_line+e.y-1]);
                                        }
                                        break;
                                case 3:if(bridge[e.x][e.y+1]==0 && e.y+1<bridge_line){
                                                mymap[2*e.x+1][2*e.y+3] = 1;
                                                mymap[2*e.x+1][2*e.y+2] = 2;    //打墙
                                                bridge[e.x][e.y-1] = 1;         //在入栈前标记为已访问
                                                Push(&sta, bridge_n[e.x*bridge_line+e.y+1]);
                                        }
                                        break;
                                default:printf("生成随机方位时出错\n");
                        }
                }
        }
}

//初始化栈
void init_stack(SQSTACK *s){
        s->base = (POINTER *)malloc(MAXSIZE*sizeof(POINTER));
        if(!(s->base)){
                printf("初始化栈时，申请内存失败。\n");
                exit(EOF);
        }
        s->top = s->base;
        s->stack_size = MAXSIZE;
}

//入栈
void Push(SQSTACK *s, POINTER b){
        *(s->top++) = b;
}

//出栈
int Pop(SQSTACK *s, POINTER *e){
        if(s->base == s->top){
                return 0;
        }
        else{
                *e = *(--s->top);
                return 1;
        }
}

//打印地图
void print_map(char mymap[LINE][LINE]){
        for(int i = 0; i < LINE; ++i){
                for(int j = 0; j < LINE; ++j){
                        if(mymap[i][j] == 0){
                                printf("%s", WALL);
                        }
                        else{
                                printf("%s", ROAD);
                        }
                }
                printf("\n");
        }
        hide();
}
