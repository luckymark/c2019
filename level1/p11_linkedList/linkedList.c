#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
 
//定义结点类型 
typedef struct Node {
    ElemType data;              
    struct Node *next;        
}Node,*LinkedList;
 
 
//单链表的初始化
 
LinkedList LinkedListInit() {
    Node *L;
    L = (Node *)malloc(sizeof(Node)); 
    if(L == NULL) { 
        printf("申请内存空间失败\n");
    }
    L->next = NULL;                  
 	return L;
}
 
 
//单链表的建立1，头插法建立单链表
 
LinkedList LinkedListCreatH() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));  
    L->next = NULL;                    
     
    ElemType x;                         
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));  
        p->data = x;                     
        p->next = L->next;                    
        L->next = p; 
    }
    return L; 
} 
 
 
//单链表的插入，在链表的第i个位置插入x的元素
 
LinkedList LinkedListInsert(LinkedList L,int i,ElemType x) {
    Node *pre;                     
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
    	pre = pre->next;                
	}
    Node *p;                                
    p = (Node *)malloc(sizeof(Node));
    p->data = x; 
    p->next = pre->next;
    pre->next = p;
     
    return L;                           
} 
 
 
//单链表的删除，在链表中删除值为x的元素
 
LinkedList LinkedListDelete(LinkedList L,ElemType x)
{
    Node *p,*pre;                  
    p = L->next;
    while(p->data != x) {            
        pre = p; 
        p = p->next;
    }
    pre->next = p->next;         
    free(p);
    return L;
} 


//单链表反转 

 LinkedList reverseList(LinkedList head){
 
    Node *pre = NULL;
    Node *next = NULL;

    while (head != NULL) {

        next = head->next;

        head->next = pre;

        pre = head;

        head = next;
    }

    return pre;
}
 
 
int main() {
    LinkedList list,start;
 	printf("请输入单链表的数据："); 
    list = LinkedListCreatH();
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    int i;
    ElemType x;
    printf("请输入插入数据的位置：");
    scanf("%d",&i);
    printf("请输入插入数据的值：");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    printf("请输入要删除的元素的值：");
    scanf("%d",&x);
    LinkedListDelete(list,x); 
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
	//反转链表 
	reverseList(list);
	
    printf("\n");
     
    return 0;
}

