#include <stdio.h>
#include <stdlib.h>
#define M 10
typedef  struct node{
    int value;
   struct node*next;
}node;

int search(node *p);
int deepsearch(node *p);
int k = 0;

int main()
{
    node *l,*h,*n;
    h=(node*)malloc(sizeof(node));
    h->value = 0;
    h->next = NULL;
    l = h;
    for(int i = 0;i<M-1;i++){ //创建链表
       n =(node*) malloc(sizeof(node));
       scanf("%d",&n->value);
       l->next = n;
       l= n;
    }
       n =(node*) malloc(sizeof(node));
       scanf("%d",&n->value);
       l->next = n;
       //输出一下看看
       l = h;
       for(int i = 0;i<M;i++){
           n = l->next;
           l = n;
           printf("%d ",n->value);
       }
       printf("\n");
      //把链表反序
       node *fro,*cur,*last;
        fro = h->next;
        cur = fro->next;
        last= cur->next;
        for(int i = 0;i<M-3;i++){
            cur->next = fro;
            fro = cur;
            cur = last;
            last = last->next;
        }
        cur->next = fro;
        last->next = cur;
        h->next = last;
        //输出一下看看
       l = h;
       for(int i = 0;i<M;i++){
           n = l->next;
           l = n;
           printf("%d ",n->value);
       }
       printf("\n");
        //寻找值为5的点
       int position = search(h);
       printf("%d",position);
       printf("\n");
       position = deepsearch(h);
       printf("%d",position);

    return 0;
}

int search(node *h){
   node *l,*n;
    l = h;
       for(;k<M;k++){
           n = l->next;
           l = n;
           if(n->value == 5){
            h = l;
            return k+1;
            }
            l = n;
       }
       return -1;
}
int deepsearch(node *h){
   node *l,*n;
    l = h;
       for(;k<M;k++){
           n = l->next;
           l = n;
           if(n->value == 5)
            return k;
       }
       return -1;
}
