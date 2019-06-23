#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define OK 1
#define ERROR 0

typedef struct {
	char name[8];
	int id;
	int number;
} student;

typedef struct node {
	student date ;
	struct node *next;
} node, *Linklist;

int make_new ( Linklist L )
{
    char n[8];
    int t, s;
    Linklist p, newn;
    p = L;   /*尾指针指向头节点*/
    FILE *r;
    if ( ( r = fopen ("/tmp/test.txt", "r" ) ) == NULL ) {
		printf("can't open the file!!!\n");
		printf("error:%s\n", strerror(errno));
		exit(0);
    }
    while ( fscanf ( r, "%s%d%d", n, &t, &s ) != EOF ) {
		newn = ( node * ) malloc ( sizeof ( node ) );
		strcpy ( newn -> date.name, n );/*字符串初始化后不能直接赋值需要调用strcpy()*/
		newn -> date.id = t;
		newn -> date.number = s;
		newn->next=NULL;    /*新节点指针域置空*/
		p->next=newn;       /*前一个节点指针（即原先的尾指针指向的节点）指向新节点*/
		p=newn;         /*尾指针指向新的节点*/
    }
    fclose(r);
}

void PrintList (Linklist L) {
    Linklist p;
    p=L;
    printf("名称\t\t\t\t编号\t\t\t\t数量\n");
    while ( p->next )/*当循环条件是p时，因为头节点数据域为空每次会输出一行乱码*/
    {
    	printf("%s\t\t\t\t%d\t\t\t\t%d\n",p->next->date.name,p->next->date.id,p->next->date.number);
    	p = p -> next;
    }
    printf("\n");
}

int ListDelete ( Linklist L ) {

    int i, j = 0;
    Linklist p, r;
    p = L;
    printf("输入要删除的节点位置\n");
    scanf("%d", &i);
    while (p->next!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if ((j!=i-1)||(p->next==NULL)){
        printf("要删除的节点不存在\n");
        return ERROR;
    }
    r = p->next;
    p->next=r->next;
    free(r);
    return OK;
}

int ListInsert(Linklist L )
{
    Linklist p,newn;
    int k,j=0;
    student s;
    p=L;
    printf("输入要插入的节点坐标\n");
    scanf("%d",&k);
    while(p!=NULL&&j<k-1)
    {
        p=p->next;
        j++;
    }
    if((j!=k-1)||(p==NULL))
    {
      printf("要插入的节点不存在");
      return ERROR;
    }
    printf("================输入要插入的信息==============\n");
    printf("*****名称:");	scanf("%s",s.name);
	printf("*****编号:");	scanf("%d",&s.id);
	printf("*****数量:");	scanf("%d",&s.number);
	printf("输入完成\n\n");
    newn=(node*)malloc(sizeof(node));
    newn->date= s ;
    newn->next=p->next;
    p->next=newn;
    return OK;
}


int Locate(Linklist L){
    int s;
    printf("输入编号查找\n");/* error: stray '\243' in program|意思是编译器在编译源文件时遇到了不可识别的非法字符注意*/
    scanf("%d",&s);         /*检查是否有汉字或汉语标点符号或者全角英文字符*/
    Linklist p;
    p=L->next;
    while(p)
	{
		if(p->date.id==s)
        printf("产品编号为:%d\n\n",p->date.number);
		p=p->next;
	}
	return ERROR;
}

int GetElement(Linklist L){
    int i,j=1;
    Linklist p;
	p=L->next;
	printf("输入要查询的位置\n");
	scanf("%d",&i);
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)	return ERROR;
	printf("该生信息如下\n");
    printf("*****名称:%s\n",p->date.name);
	printf("*****编号:%d\n",p->date.id);    /*printf语句中未加入控制输入输出字符导致无法输出结果*/
	printf("*****数量:%d\n",p->date.number);
	return OK;
}
void main()
{
    Linklist L;
	L = ( Linklist ) malloc ( sizeof ( Linklist ) );
	L -> next = NULL;

    make_new(L);
    PrintList(L);

    ListInsert(L);
    PrintList(L);

    ListDelete(L);
    PrintList(L);

    Locate(L);
    GetElement(L);
}