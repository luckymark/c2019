#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define Width 12
#define Height 10


int map[Height][Width]={
	{1,0,0,1,1,1,0,0,0,0,0,0},
	{1,0,0,1,4,1,0,0,0,0,0,0},
	{1,0,0,1,0,1,1,1,1,1,1,1},
	{1,1,1,1,3,0,3,0,0,0,4,1},
	{1,4,0,0,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,3,1,0,0,0,0,0},
	{0,0,0,0,1,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,1,0,0,0,0,0},
	{0,0,0,0,1,4,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,0,0,0,0,0}};//1����ǽ   2������  3����Ŀ��λ��  4�������� 0·

int a=4,b=5;//��ʼ��С��λ��
int score=0;//�ж���Ϸ�Ƿ����

void draw_map(int map[Height][Width]){
    int i,j;
    for(i=0;i<Height;i++){
    for(j=0;j<Width;j++){
        switch(map[i][j]){
        case 1 :
            printf("Q");//ǽ
            break;
        case 0 :
            printf(" ");//·
            break;
        case 2 :
            printf("P");//��
            break;
        case 4 :
            printf("D");//Ŀ�ĵ�
            break;
        case 5 :
            printf("F");//�����Ѿ��Ƶ���Ŀ�ĵ�
            break;
        case 3 :
            printf("C");//����
            break;
        }
    }
    printf("\n");
    }
}

void game(){
    if(kbhit()){
    char c=getch();
    switch(c){
    case 72://���ϵĲ���
        switch(map[a-1][b]){
        case 1:
            break;
        case 0:
            map[a-1][b]=2;
            map[a][b]=0;
            a--;
            break;
        case 3:
            if(map[a-2][b]==0){
                map[a-2][b]=3;
                map[a-1][b]=2;
                map[a][b]=0;
                a--;
            }
            if(map[a-2][b]==4){
                map[a-2][b]=5;
                map[a-1][b]=2;
                map[a][b]=0;
                a--;
                score++;
            }
        default :
            break;
        }

        break;
     case 80://���µĲ���
        switch(map[a+1][b]){
        case 1:
            break;
        case 0:
            map[a+1][b]=2;
            map[a][b]=0;
            a++;
            break;
        case 3:
            if(map[a+2][b]==0){
                map[a+2][b]=3;
                map[a+1][b]=2;
                map[a][b]=0;
                a++;
            }
            if(map[a+2][b]==4){
                map[a+2][b]=5;
                map[a+1][b]=2;
                map[a][b]=0;
                a++;
                score++;
            }
        default:
            break;
        }
        break;
    case 77://���ҵĲ���
        switch(map[a][b+1]){
        case 1:
            break;
        case 0:
            map[a][b+1]=2;
            map[a][b]=0;
            b++;
            break;
        case 3:
            if(map[a][b+2]==0){
                map[a][b+2]=3;
                map[a][b+1]=2;
                map[a][b]=0;
                b++;
            }
            if(map[a][b+2]==4){
                map[a][b+2]=5;
                map[a][b+1]=2;
                map[a][b]=0;
                b++;
                score++;
            }
        default:
            break;
        }
        break;
    case 75://����Ĳ���
        switch(map[a][b-1]){
        case 1:
            break;
        case 0:
            map[a][b-1]=2;
            map[a][b]=0;
            b--;
            break;
        case 3:
            if(map[a][b-2]==0){
                map[a][b-2]=3;
                map[a][b-1]=2;
                map[a][b]=0;
                b--;
            }
            if(map[a][b-2]==4){
                map[a][b-2]=5;
                map[a][b-1]=2;
                map[a][b]=0;
                b--;
                score++;
            }
        default:
            break;
        }
        break;
    }
    }
}
int main()
{

	system("mode con cols=80 lines=25");


    while(score<4){
        printf("Q-ǽ��P-�ˣ�D-Ŀ�ĵأ�C���ӣ�F��ʾ���������Ѿ��Ƶ�Ŀ�ĵ���\n");
        system("cls");//����
        game();
        draw_map(map);

    }
    printf("You have succeeded!!");
    return 0;
}
