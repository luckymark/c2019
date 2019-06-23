#include <stdio.h>
#include <stdlib.h>
#include "evalue.h"

extern int board[SIZE][SIZE];
int myturn, opoturn;
extern int ai_turn;

// 估计一个位置的值，并返回
// 只需要检索这个位置所在的横、纵、斜排
int evalue(DPT *head, int turn){
    myturn = turn;
    opoturn = (myturn == BLACK) ? WHITE : BLACK;

    int value = 0;

    // 开始估值
    int up, down, left, right;
    int i, j, k;    // 循环变量
    int *p = (int*)malloc((SIZE+1)*sizeof(int));

    // 检索横排
    k = 0;
    for(i = 0; i < SIZE; ++i){
        *(p+k) = board[head->x][i];
        ++k;
    }
    *(p+k) = END;
    value = value + getvalue(p, myturn, head) - getvalue(p, opoturn, head);

    // 检索纵排
    k = 0;
    for(i = 0; i < SIZE; ++i){
        *(p+k) = board[i][head->y];
        ++k;
    }
    *(p+k) = END;
    value = value + getvalue(p, myturn, head) - getvalue(p, opoturn, head);

    // 更新边界
    if(head->x < head->y){
        left = head->y - head->x;
        up = 0;
        right = SIZE - 1;
        down = head->x + (SIZE - 1 - head->y);
    }
    else{
        left = 0;
        up = head->x - head->y;
        right = head->y + (SIZE - 1 - head->x);
        down = SIZE - 1;
    }

    // 检索斜排“\”
    k = 0;
    for(i = up, j = left; i<=down && j<=right; ++i, ++j){
            *(p + k) = board[i][j];
            ++k;
    }
    *(p+k) = END;
    value = value + getvalue(p, myturn, head) - getvalue(p, opoturn, head);

    // 更新边界
    if(head->x < SIZE-1-head->y){
        up = 0;
        left = 0;
        down = head->x + head->y;
        right = head->y + head->x;
    }
    else{
        up = head->x - (SIZE - 1 - head->y);
        right = SIZE - 1;
        left = head->y - (SIZE - 1 - head->x);
        down = SIZE - 1;
    }

    // 检索斜排“/”
    k = 0;
    for(i = up, j = right; i<=down && j>=left; ++i, --j){
        *(p+k) = board[i][j];
        ++k;
    }
    *(p+k) = END;
    value = value + getvalue(p, myturn, head) - getvalue(p, opoturn, head);

    return value;
}

// 获取某一种棋型的值，并返回
int getvalue(int *p, int turn, DPT *head){
    int level = 0;

    // 为什么我要写得这么丑呢。。
    // 因为之前我试图通过在if语句带的花括号里改变level的值，来改变AI的进攻性和防守性
    // 但是我设置的不太好，几番测试下来觉得还是目前这个版本走的最好
    // 这几个花括号暂且留着，也许以后会进一步探究这方面
    level = is_level_1(p, turn);
    if(level) {
        ++head->fives;
    }
    else{
        level = is_level_2(p, turn);
        if(level) {}
        else{
            level = is_level_3(p, turn);
            if(level) {}
            else{
                level = is_level_4(p, turn);
                if(level){}
                else{
                    level = is_level_5(p, turn);
                    if(level) {}
                    else {
                        level = is_level_6(p, turn);
                        if (level) {}
                    }
                }
            }
        }
    }

    return level;
}

int is_level_1(int *p, int turn){
    // ooooo
    int n = 0;
    for(int i=0; *(p+i)!=END; ++i){
        if(*(p+i)==turn){
            ++n;
            if(n==5)
                return LEVEL1;
        }
        else
            n = 0;
    }

    return FALSE;
}

int is_level_2(int *p, int turn){
    // +oooo+
    int sample[6] = {EMPTY, turn, turn, turn, turn, EMPTY};
    if(match(sample, 6, p))
        return LEVEL2;
    else
        return FALSE;
}

int is_level_3(int *p, int turn){
    // oo+oo
    int sample1[5] = {turn, turn, EMPTY, turn, turn};
    if(match(sample1, 5, p))
        return LEVEL31;

    // oooo+  +oooo
    int sample2[5] = {turn, turn, turn, turn, EMPTY};
    int sample3[5] = {EMPTY, turn, turn, turn, turn};
    if(match(sample2, 5, p) || match(sample3, 5, p))
        return LEVEL32;

    // +ooo++  ++ooo+  ooo+o  o+ooo
    int sample4[6] = {EMPTY, turn, turn, turn, EMPTY, EMPTY};
    int sample5[6] = {EMPTY, EMPTY, turn, turn, turn, EMPTY};
    int sample6[5] = {turn, EMPTY, turn, turn, turn};
    int sample7[5] = {turn, turn, turn, EMPTY, turn};
    if(match(sample4, 6, p) || match(sample5, 6, p) || match(sample6, 5, p) || match(sample7, 5, p))
        return LEVEL33;

    // +oo+o+  +o+oo+
    int sample8[6] = {EMPTY, turn, turn, EMPTY, turn, EMPTY};
    int sample9[6] = {EMPTY, turn, EMPTY, turn, turn, EMPTY};
    if(match(sample8, 6, p) || match(sample9, 6, p))
        return LEVEL34;

    return FALSE;
}

int is_level_4(int *p, int turn){
    // ++oo++
    int sample1[6] = {EMPTY, EMPTY, turn, turn, EMPTY, EMPTY};
    if(match(sample1, 6, p))
        return LEVEL41;

    // +o++oo+  +oo++o+
    int sample2[7] = {EMPTY, turn, EMPTY, EMPTY, turn, turn, EMPTY};
    int sample3[7] = {EMPTY, turn, turn, EMPTY, EMPTY, turn, EMPTY};
    if(match(sample2, 7, p) || match(sample3, 7, p))
        return LEVEL42;

    // o+o+o
    int sample4[5] = {turn, EMPTY, turn, EMPTY, turn};
    if(match(sample4, 5, p))
        return LEVEL43;

    // ooo++  ++ooo
    int sample5[5] = {turn, turn, turn, EMPTY, EMPTY};
    int sample6[5] = {EMPTY, EMPTY, turn, turn, turn};
    if(match(sample5, 5, p) || match(sample6, 5, p))
        return LEVEL44;

    return FALSE;
}

int is_level_5(int *p, int turn){
    // ++o+o+  +o+o++
    int sample1[6] = {EMPTY, EMPTY, turn, EMPTY, turn, EMPTY};
    int sample2[6] = {EMPTY, turn, EMPTY, turn, EMPTY, EMPTY};
    if(match(sample1, 6, p) || match(sample2, 6, p))
        return LEVEL51;

    // +o++o+
    int sample3[6] = {EMPTY, turn, EMPTY, EMPTY, turn, EMPTY};
    if(match(sample3, 6, p))
        return LEVEL52;

    // oo+++  +++oo
    int sample4[5] = {turn, turn, EMPTY, EMPTY, EMPTY};
    int sample5[5] = {EMPTY, EMPTY, EMPTY, turn, turn};
    if(match(sample4, 5, p) || match(sample5, 5, p))
        return LEVEL53;

    return FALSE;
}

int is_level_6(int *p, int turn){
    // +++o++  ++o+++
    int sample1[6] = {EMPTY, EMPTY, EMPTY, turn, EMPTY, EMPTY};
    int sample2[6] = {EMPTY, EMPTY, turn, EMPTY, EMPTY, EMPTY};
    if(match(sample1, 6, p) || match(sample2, 6, p))
        return LEVEL6;

    return FALSE;
}

BOOL match(int *sample, int n, int *text){
    int i, j;
    for(i = 0; *(text+i+n-1) != END; ++i){
        for(j = 0; j < n; ++j){
            if(*(text+i+j) != *(sample+j))
                break;
        }
        if(j == n)
            return TRUE;
    }
    return FALSE;
}
