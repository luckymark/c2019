#include<stdio.h>
#include<stdlib.h>
struct node {
	int value;
	struct node *next;
};
int search(struct node *s,int *m,int *n);
int main()
{
	int i;
	struct node *h=NULL;
	struct node *p;
	for(i=0;i<5;i++){
		p=(struct node*)malloc(sizeof(struct node));
		p->next =h;
		h=p;
	}
	/*��������ֵ*/
	for(p=h;p!=NULL;p=p->next){
		scanf("%d",&p->value);
	}
	for(p=h;p!=NULL;p=p->next){
		printf("%d ",p->value);
	}
	printf("\n");
	 
	/*�ڵ㷴��*/
	struct node *f,*mi,*b;
	f=h;
	mi=h;
	b=h;
	f=f->next;
	mi=mi->next;
	
	do{
		f=f->next;
		mi->next=b;
		b=mi;
		mi=f;
	}while(f->next !=NULL);
	f->next=b;
	h->next=NULL;
	h=f;
	p=h;
	for(p=h;p!=NULL;p=p->next){
		printf("%d ",p->value);
	}
	printf("\n");
	
	/*Q4 ���ҵ�һ��ֵΪ5�Ľڵ�*/
	struct node *s;//search���������
	int outcome=0;
	int x=0,y=0;
	int *m=&x;//�ڼ����ڵ�
	int *n=&y;//�ڼ���ֵΪ5�Ľڵ�
	s=h;
	outcome=search(s,m,n);
	printf("%d\n",outcome);
	if(outcome !=-1){
		outcome=search(s,m,n);
		printf("%d",outcome);
	}	
	return 0;
}
int search(struct node *s,int *m,int *n){
	struct node *a; 
	int outcome=-1;
	for(a=s;a->next!=NULL;a=a->next){
		++*m;
		if(a->value==5){
			++*n;
			outcome=*m;
			s=a->next;
			break;
		}
	}
	return outcome;
} 
