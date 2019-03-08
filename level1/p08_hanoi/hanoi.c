#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1;
#define false 0;

struct wedge
{
    wedge *top;
    wedge *bottom;
    int val;
};

struct pillar
{
    wedge *top;
    wedge *base;
    int length;
    int index;
};
void hanoi(int n, pillar *from, pillar *to, pillar *assist, unsigned long long *count);
void move(pillar *from, pillar *to, unsigned long long *count);
pillar *stackInit(int i);
int stackPush(pillar *s, wedge *se);
int stackPop(pillar *s);
wedge *stackElmCreate(int value);
wedge *stackGet(pillar *s);
int main()
{
    int wedgeCount = 4; //A塔盘数...
    unsigned long long count = 0;
    //init pillar
    pillar *pillarA = stackInit(0);
    pillar *pillarB = stackInit(1);
    pillar *pillarC = stackInit(2);
    //init wedge
    int i = -1;
    while (++i < wedgeCount)
    {
        wedge *se = stackElmCreate(wedgeCount - i - 1);
        stackPush(pillarA, se);
    }
    clock_t t1 = clock();
    hanoi(wedgeCount, pillarA, pillarC, pillarB, &count);
    clock_t t2 = clock();
    double t = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Result: %llutimes. \nexecution time: %fs\n", count, t);
    return 0;
}
void hanoi(int n, pillar *from, pillar *to, pillar *assist, unsigned long long *count)
{
    if (n == 1)
    {
        move(from, to, count);
    }
    else
    {
        hanoi(n - 1, from, assist, to, count);
        move(from, to, count);
        hanoi(n - 1, assist, to, from, count);
    }
}
void move(pillar *from, pillar *to, unsigned long long *count)
{
    wedge *w = stackGet(from);
    stackPop(from);
    stackPush(to, w);
    (*count)++;
    printf("[%llu]%d -> %d\n", *count, from->index, to->index);
}
pillar *stackInit(int i)
{
    pillar *s = (pillar *)malloc(sizeof(pillar));
    s->top = NULL;
    s->base = NULL;
    s->length = 0;
    s->index = i;
    return s;
}
int stackPush(pillar *s, wedge *se)
{
    if (s->length == 0)
    {
        s->base = se;
        se->bottom = NULL;
        se->top = NULL;
    }
    else
    {
        s->top->top = se;
        se->bottom = s->top;
    }
    se->top = NULL;
    s->top = se;

    s->length++;
    return true;
}
int stackPop(pillar *s)
{
    if (s->length == 0)
    {
        return false;
    }
    if (s->length == 1)
    {
        s->top = NULL;
        s->base = NULL;
    }
    else
    {
        wedge *se = s->top->bottom;
        s->top->bottom = NULL;
        s->top->top = NULL;
        s->top = se;
        se->top = NULL;
    }
    s->length--;
    return true;
}
wedge *stackGet(pillar *s)
{
    return s->top;
}
wedge *stackElmCreate(int value)
{
    wedge *se = (wedge *)malloc(sizeof(wedge));
    se->bottom = NULL;
    se->top = NULL;
    se->val = value;
    return se;
}