#include"maze.h"
void initmaze(pmaze m, int Map[Maplong][Mapwidth])
{
    assert(m!=NULL);
    int i,j;
    for(i=0; i<Maplong; i++)
    {
        for(j=0; j<Mapwidth; j++)
        {
            m->_map[i][j]=Map[i][j];
        }
    }
}
void randommaze(pmaze m)
{
    int i,j,k;
    srand(time(NULL));
    m->_map[1][0]=m->_map[Maplong-2][Mapwidth-1]=1;
    for(i=0; i<Maplong; i++)
    {
        m->_map[0][i]=m->_map[Maplong-1][i]=0;
    }
    for(j=2;j<Mapwidth; j++)
    {
        m->_map[j][0]=m->_map[j-2][Mapwidth-1]=0;
    }
    for(i=1; i<Maplong-1; i++)
    {
        for(j=1; j<Mapwidth-1; j++)
        {
            k=rand()%3;
            if(k)
                m->_map[i][j]=1;
            else
            {
                if((i==1&&j==1)||(i==Maplong-2&&Mapwidth-2==j))
                {
                    m->_map[i][j]=1;
                }
                else
                {
                    m->_map[i][j]=0;
                }
            }
        }
    }
}
int  exitmaze(pmaze m)
{
    if(position_x==Maplong-2&&position_y==Mapwidth-1)
    {
        return 1;
    }
    return 0;
}
void antoprintmaze(pmaze m)
{
    int i,j;
    for(i=0; i<Maplong; i++)
    {
        for(j=0; j<Mapwidth; j++)
        {
            switch(m->_map[i][j])
            {
            case(0):
                printf("0");
                break;
            case(1):
                printf(" ");
                break;
            case(2):
                printf("*");
                break;
            case(3):
                printf(" ");
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
    printf("\n");
}
void initstack(pstack m)
{
    assert(m!=NULL);
    m->top=0;
}
void popstack(pstack m)
{
    assert(m!=NULL);
    if(m->top)
        m->top--;
}
void pushstack(pstack m,mazenode n)
{
    assert(m!=NULL);
    if(m->top==Maxstep)
        return;
    else
    {
        m->num[m->top]=n;
        m->top++;
    }
}
int emptystack(pstack s)
{
    assert(s!=NULL);
    if(0==s->top)
        return 1;
    return 0;
}
mazenode Stacktop(pstack  s)
{
    assert((s!=NULL));
    if(0==s->top)
    {
        printf("error");
        exit(1);
    }
    return s->num[s->top-1];
}
int entermaze(pmaze m,position e)
{
    assert(m!=NULL);
    if((e._x==0||e._x==Maplong-1||e._y==0||e._y==Mapwidth-1)&&(e._x>=0)&&(e._x<Maplong)&&(e._y>=0)&&(e._y<Mapwidth))
    {
        return 1;
    }
    return 0;
}
int Passmaze(pmaze m,position e)
{
    assert(m!=NULL);
    if(1==m->_map[e._x][e._y])
    {
        return 1;
    }
    return 0;
}
void printmaze(pmaze m)
{
    int i,j;
    for(i=0; i<Maplong; i++)
    {
        for(j=0; j<Mapwidth; j++)
        {
            if(i==position_x&&j==position_y)
            {
                if(one==1)
                {
                    temp= m->_map[i][j];
                    px=i;
                    py=j;
                    one=0;
                }
                m->_map[i][j]=4;
            }
            switch(m->_map[i][j])
            {
            case(0):
                printf("0");
                break;
            case(1):
                printf(" ");
                break;
            case(2):
                printf(" ");
                break;
            case(3):
                printf(" ");
                break;
            case(4):
                printf("@");
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
    printf("\n");

}
//void footpath(pmaze m,positon e)
void antoFootpath(pmaze m,position e)
{
    assert(m!=NULL);
    Stack s;
    initstack(&s);
    pushstack(&s,e);
    while(!emptystack(&s))
    {
        position now;
        position next;
        now=Stacktop(&s);
        m->_map[now._x][now._y]=2;
        if(now._x==Maplong-2&&now._y==Mapwidth-1)
        {
            return;
        }
        else
        {
            next=now;
            next._x+=1;
            if(Passmaze(m,next))
            {
                pushstack(&s,next);
                continue;
            }
            next=now;
            next._y+=1;
            if(Passmaze(m,next))
            {
                pushstack(&s,next);
                continue;
            }
            next=now;
            next._y-=1;
            if(Passmaze(m,next))
            {
                pushstack(&s,next);
                continue;
            }
            next=now;
            next._x-=1;
            if(Passmaze(m,next))
            {
                pushstack(&s,next);
                continue;
            }
            m->_map[now._x][now._y]=3;
            popstack(&s);
        }
    }


}
