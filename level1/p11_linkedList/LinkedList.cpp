#include <stdio.h>
#include <stdlib.h>
int el_seek(struct node* head, int i, int num);
struct node{
	int value;
	struct node *next;
};
int main(){
	/*q1*/
	int n;
	scanf("%d",&n);
	struct node *head, *q, *p;
	head=NULL;
	while(n--){
		q=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&q->value);
		q->next=NULL;
		if(head==NULL){
			head=q;
		}
		else{
			p->next=q;
		}
		p=q;
	}
	/*遍历链表  q2*/
	struct node *p1;
	p1=head;
	while(p1!=NULL){
		printf("%d ",p1->value);
		p1=p1->next;
	}
	/*链表反序  q3*/
	struct node *p2,*p3, *p4;
	p2=head;
	p3=p2;
	p2=p2->next;
	while(p2->next!=NULL){
		p4=p2;
		p2=p2->next;
		p4->next=p3;
		p3=p4;
	}
	p2->next=p4;
	head->next=NULL;
	head=p2;
	printf("\n");
	struct node *pa;
	pa=head;
	while(pa!=NULL){
		printf("%d ",pa->value);
		pa=pa->next;
	}
	/*查找 q4 q5*/
	int i;//find the i-th element of the list
	i=1;
	int a;
	a=el_seek(head,i,5);
	while(a!=-1){
		a=el_seek(head,i,5);
		printf("\n%d\n",a);
		i++;
	}
	return 0;
}

int el_seek(struct node* head, int i, int num){
	int cnt=0;//记节点 
	int l=0;//判断第几个 
	int judge=-1;
	struct node *point;
	point=head;
	while(point!=NULL){
		cnt++;
		if(point->value==num)l++;
		if(l==i){
			judge=cnt;
			break;
		}
		point=point->next;
	}
	return judge;
}
