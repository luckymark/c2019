#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct node{
    int value;
    int number;
    BOOL isVisit;
    struct node* next;
}NODE;
