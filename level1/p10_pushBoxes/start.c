#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include "box.h"

int line, col;  //地图的行数和列数
int step;       //走过的步数
int level;      //关卡

int map[LINE][COL];

void instruction();
void locate(int y, int x);
void hide();

int bomb_num;   //地图中炸弹的个数
struct bomb{
        int x;  //炸弹的行坐标
        int y;  //炸弹的列坐标
}bb[4];

struct player{
        int x;  //玩家的行坐标
        int y;  //玩家的列坐标
}pla;

void start(){
        void print_map();
        BOOL to_move();

        level = 0;      //当前关卡,一共三个关卡
        BOOL is_pass;    //是否通过当前关卡

        restart:
        //打印地图
        ++level;
        print_map();

        //玩家移动
        is_pass = to_move();
        if(is_pass == FALSE){
                --level;
                system("cls");
                goto restart;
        }
        else if(level < 3){
                system("cls");
                goto restart;
        }

        //结束
        printf("\n恭喜！你通过了全部关卡！\n");
        Sleep(5000);
}

void print_map(){
        FILE *fp;
        switch(level){
                case 1: fp = fopen("box_in1.txt", "r");break;
                case 2: fp = fopen("box_in2.txt", "r");break;
                case 3: fp = fopen("box_in3.txt", "r");break;
                default: printf("Abnormal level.\n");
                         break;
        }

        fscanf(fp, "%d%d", &line, &col);
        bomb_num = 0;
        int a;
        locate(0, 0);
        for(int i = 0; i < line; ++i){
                for(int j = 0; j < col; ++j){
                        fscanf(fp, "%d", &a);
                        map[i][j] = a;
                        switch(a){
                                case 1: printf("%s", WALL);
                                        break;
                                case 0: printf("%s", ROAD);
                                        break;
                                case 2: printf("%s", PLAYER);
                                        pla.x = i;
                                        pla.y = 2*j;
                                        break;
                                case 3: printf("%s", BOX);
                                        break;
                                case 4: printf("%s", BOMB);
                                        bb[bomb_num].x = i;
                                        bb[bomb_num].y = j;
                                        ++bomb_num;
                                        break;
                                default: printf("Confusing map.\n");
                                         break;
                        }
                }
                printf("\n");
        }
        fclose(fp);

        //输出指令
        instruction();
}

BOOL to_move(){
        void move(char ist);
        void print_score();

        step = 0;
        char ist;
        while((ist = getch())){
                switch(ist){
                        case 'w': move('w');
                                  break;
                        case 's': move('s');
                                  break;
                        case 'a': move('a');
                                  break;
                        case 'd': move('d');
                                  break;
                        case 'q': return FALSE;
                        case 'e': return TRUE;
                        default: break;
                }
                //检查是否已经过关
                int i;
                for(i = 0; i < bomb_num; ++i){
                        if(map[bb[i].x][bb[i].y] != 7){
                                break;
                        }
                }
                if(i == bomb_num){
                        print_score();
                        return TRUE;
                }
        }
        return FALSE;
}

void move(char ist){
        int xy[2];
        switch(ist){
                case 'w': xy[0] = -1;
                          xy[1] = 0;
                          break;
                case 's': xy[0] = 1;
                          xy[1] = 0;
                          break;
                case 'a': xy[0] = 0;
                          xy[1] = -2;
                          break;
                case 'd': xy[0] = 0;
                          xy[1] = 2;
                          break;
                default: break;
        }
        //判断是否能够移动
        if(map[pla.x+xy[0]][(pla.y+xy[1])/2] == 1){
                return;         //前面是墙
        }
        else if((map[pla.x+xy[0]][(pla.y+xy[1])/2]==3 || map[pla.x+xy[0]][(pla.y+xy[1])/2]==7) && (map[pla.x+2*xy[0]][(pla.y+2*xy[1])/2]==1 || map[pla.x+2*xy[0]][(pla.y+2*xy[1])/2]==3 || map[pla.x+2*xy[0]][(pla.y+2*xy[1])/2]==7)){
                return;         //前面两个都是箱子或一个箱子一个墙
        }

        //移动前的位置
        locate(pla.x, pla.y);
        if(map[pla.x][pla.y/2]==4 || map[pla.x][pla.y/2]==6){
                printf("%s", BOMB);
        }
        else{
                printf("%s", ROAD);
        }
        map[pla.x][pla.y/2] = map[pla.x][pla.y/2] - 2;
        //移动后的位置
        pla.x = pla.x + xy[0];
        pla.y = pla.y + xy[1];
        locate(pla.x, pla.y);
        printf("%s", PLAYER);

        //移动后的下一个位置
        if(map[pla.x][pla.y/2]==3 || map[pla.x][pla.y/2]==7){
                       // printf("come in");
                map[pla.x][pla.y/2] = map[pla.x][pla.y/2] - 3;
                map[pla.x+xy[0]][(pla.y+xy[1])/2] = map[pla.x+xy[0]][(pla.y+xy[1])/2] + 3;
                locate(pla.x+xy[0], pla.y+xy[1]);
                printf("%s", BOX);
        }
        map[pla.x][pla.y/2] = map[pla.x][pla.y/2] + 2;

        ++step;
        locate(line+8, 0);
        printf("当前步数：%d\n", step);

        hide();
}


void print_score(){
        locate(line+9, 0);
        printf("恭喜！\n");
        printf("您通过本关用了%d步。\n", step);
        printf("请等待5秒。\n");
        Sleep(6000);

        FILE *fp = fopen("box_out.txt", "a");
        fprintf(fp, "第%d关，用了%d步。\n", level, step);
        fclose(fp);
}
