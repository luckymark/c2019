//
//  main.cpp
//  git.warehouse
//
//  Created by 兼桑 on 2019/4/17.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
using namespace std;
int i;
FILE *fp=fopen("text.txt","w+");
typedef struct list{
    char name;
    int num;
    struct list *next;
}list1;

list1 *head=(list1*)malloc(sizeof(list1));
list1 *a=head,*node=head;
void showlist(){
    if(head->next!=NULL)
    {
        printf("%c %d\n",head->name,head->num);
        head=head->next;
        return showlist();}
}
void add(char nam,int numb){
    a=node->next;
    a->name=nam;
    a->num=numb;
    node=a->next;
}
void input(){
    char nam;int numb;
    scanf("%c%d",&nam,&numb);
    fprintf(fp, "%c%d",nam,numb);
    return add(nam,numb);
}
void output(){
    char nam;int numb;
    scanf("%c%d",&nam,&numb);
    list1 *pre=head;
    node=node->next;
    if(nam!=node->name)
    {
        node=node->next;
        return output();
    }
    if(node->next!=NULL)
    {
        pre->next=node->next;
    }
    else
        pre->next=NULL;
}
int main()
{
    int c[100],j=0;char b[100];
    
    if (fp == NULL)
    {
        printf("读取失败\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%c%d",&b[j],&c[j]);
        ++j;
    }
    fclose(fp);
    int k=0;
    for(k=0;k<=j;++k)
    {
        add( b[k], c[k]);
    }
    printf("choose the number:\n1.show the list\n2.input\n3.output\n4.quit");
    scanf("%d",&i);
    switch(i)
    {
        case 1:showlist();break;
        case 2:input();break;
        case 3:output();break;
        case 4:exit(0);break;
        default:printf("error!");break;
    }
}
