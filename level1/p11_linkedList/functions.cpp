#include"dec.h"
node *addnode(node *head)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	(*tmp).next=head;
	return tmp;
}
void freeall(node *p,node **t)
{
	if((*p).next!=NULL)
		freeall((*p).next,&((*p).next));
	free(p);
	*t=NULL;
}
node *reverse(node *p)
{
	node *last,*now,*next;
	if(p==NULL)
		return NULL;
	last=p;
	now=(*p).next;
	(*p).next=NULL;
	while(now)
	{
		next=(*now).next;
		(*now).next=last;
		last=now;
		now=next;
	}
	return last;
}
void printlist(node *head)
{
	node *tmp=head;
	while(tmp!=NULL)
	{
		printf("%d\n",(*tmp).val);
		tmp=(*tmp).next;
	}
}
void find5(node *start)
{
	node *tmp=start;
	int i=0,judge=0;
	while(tmp)
	{
		++i;
		if((*tmp).val==5)
		{
			++judge;
			printf("%d:%d\n",judge,i);
		}
		tmp=(*tmp).next;
	}
	if(!judge)
		printf("%d\n",-1);
}
