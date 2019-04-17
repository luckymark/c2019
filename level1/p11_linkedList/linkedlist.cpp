#include<cstdio>
#include<cstring>

using namespace std;

struct Node{
	int val,id;
	Node* next;
	Node(int va,int i){
		val=va;id=i;
		next=NULL;
	} 
}*head=NULL;
int n;
void insert(Node* &o,int v,int i){
	if(!o){
		o=new Node(v,i);
		return;
	}
	insert(o->next,v,i);
	return;
}
void print(Node* o){
	for(;o;o=o->next){
		printf("%d %d\n",o->val,o->id);
	}
	return; 
}
void build(Node* &o,int i){
	if(i>n) return;
	int a;
	scanf("%d",&a);
	insert(o,a,i);
	build(o->next,i+1);
	
	return ;
}
Node* rebuild(Node* o,int i){
	if ( i==1 ) return o; 
	if ( i==2 ) {
		o->next->id=1; 
		insert(o->next,o->val,2);
		delete o;
		return o->next;
	}  
	o->next=rebuild(o->next,i-1);
	insert(o->next,o->val,i);
	delete o;
	return o->next; 
}
Node* search(Node *o,int x){
	if(!o) return NULL;
	if(o->val==x) return o;
	return search(o->next,x);
}
int main(){ 
	scanf("%d",&n);
	// the requirement 1 2
	build(head,1);
	print(head);
	
	// the requirement 3
	head=rebuild(head,n);
	print(head);
	
	// the requirement 4
	Node* p=search(head,5);
	if(!p){
		printf("-1\n");
	}
	else {
		printf("%d\n",p->id);
		
		// the requirement 5
		Node *nextp=search(p->next,5);
		if (!nextp) printf("-1\n");
		else printf("%d\n",nextp->id);
	}
	return 0;
}
