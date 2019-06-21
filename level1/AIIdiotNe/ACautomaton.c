//
// Created by Newton on 2019/6/19.
//

#include "FIR.h"

extern char PatternTable[PATTERNNUM][7];
extern char PatternTable1[PATTERNNUM][7];
extern int ValueTable[PATTERNNUM];

extern Node *root;
extern Node *root1;
extern Node *Q[MAXLTH];
extern Node *Q1[MAXLTH];

extern bool gamer;
extern bool Victory;

extern char chessboard[WIDTH][WIDTH];

int Max(int a, int b)
{
    return a>b?a:b;
}

/** Initialize the root of the tree */
void InitTrie(void)
{
    root =(Node*)malloc(sizeof(Node));
    root1=(Node*)malloc(sizeof(Node));
    // printf("Root is init");
}
/**
 * Init the node's member
 * @param root [the point that need to be initialize]
 */
void InitNode(Node *newnode)
{
    int i;
    newnode->end=false;
    newnode->fail=NULL;
    newnode->score=0;

    for (i=0; i<CHESSTYPE; i++){
        newnode->next[i]=NULL;
    }
}

/**
 * the pre-operation from construct a tri, use the idea of BFS
 * @param s     [the next string that going to be insert in the Trie]
 * @param order [to index the score]
 */
void EnTrie(char *s, int order)
{
    Node *CurNode=root;
    Node *newnode;

    int i;

    for (i=0; s[i]; i++){
        int CurLetter=s[i]-'0';
        if (NULL== CurNode->next[CurLetter]){
            newnode = (Node *)malloc(sizeof(Node));
            InitNode(newnode);
            CurNode->next[CurLetter]=newnode;
        }
        CurNode=CurNode->next[CurLetter];
    }
    CurNode->end=true;
    CurNode->score=ValueTable[order];

}
/**
 * build two AC automaton to speed up
 * @param s     [description]
 * @param order [description]
 */
void EnTrie1(char *s, int order)
{
    Node *CurNode=root1;
    Node *newnode;

    int i;

    for (i=0; s[i]; i++){
        int CurLetter=s[i]-'0';
        if (NULL == CurNode->next[CurLetter]){
            newnode = (Node*)malloc(sizeof(Node));
            InitNode(newnode);
            CurNode->next[CurLetter]=newnode;
        }
        CurNode=CurNode->next[CurLetter];
    }
    CurNode->end=true;
    CurNode->score=ValueTable[order];
}
/**
 * use EnTrie to Build the Trie
 */
void BuildTrie(void)
{
    int i;

    InitNode(root);
    for (i=0; i<PATTERNNUM; i++){
        EnTrie(PatternTable[i], i);
    }

    InitNode(root1);
    for (i=0; i<PATTERNNUM; i++){
        EnTrie1(PatternTable1[i], i);
    }
}
/**
 * use BFS to build failure function
 */
void BuildFailPointer(void)
{
    int head=0, tail=1, i;
    Q[head] = root;
    Q1[head]=root1;
    Node *CurNode, *Head;

    while (head < tail){
        Head=Q[head++];		// the head of the current queue
        for (i=0; i<CHESSTYPE; i++){
            if (NULL != Head->next[i]){
                if (root == Head){		// set the fail pointer of the kid of the root to root
                    Head->next[i]->fail=root;
                }
                else{
                    CurNode=Head->fail;
                    while ( NULL != CurNode){
                        if (NULL != CurNode->next[i]){
                            Head->next[i]->fail=CurNode->next[i];
                            break;
                        }
                        CurNode = CurNode->fail;
                    }
                    if (NULL == CurNode){
                        Head->next[i]->fail=root;
                    }
                }
                Q[tail++]=Head->next[i];
            }
        }
    }

    head=0;
    tail=1;
    while (head < tail){
        Head=Q1[head++];		// the head of the current queue
        for (i=0; i<CHESSTYPE; i++){
            if (NULL != Head->next[i]){
                if (root1 == Head){		// set the fail pointer of the kid of the root to root
                    Head->next[i]->fail=root1;
                }
                else{
                    CurNode=Head->fail;
                    while ( NULL != CurNode){
                        if (NULL != CurNode->next[i]){
                            Head->next[i]->fail=CurNode->next[i];
                            break;
                        }
                        CurNode = CurNode->fail;
                    }
                    if (NULL == CurNode){
                        Head->next[i]->fail=root1;
                    }
                }
                Q1[tail++]=Head->next[i];
            }
        }
    }
    // printf("FailPointer is OK!"); // used to test

}
/**
 * run the ac automaton to evaluate the situation locally
 * @param  s [description]
 * @return   [the corespond score of the current string]
 */
int LocalRunAC(char *s)
{
    Node *p=root;
    int score=0;
    int i=0;

    while ( s[i]){
        int x=s[i]-'0';

        if ( NULL== p->next[x]){
            if (root == p){
                i++;
                continue;
            }
            p=p->fail;
            continue;
        }

        p=p->next[x];
        i++;
        if (p->end)
            score=Max(score, p->score);
    }
    // printf("RunAC is ok");  //used to test

    return score;
}
int LocalRunAC1(char *s)
{
    Node *p=root1;
    int score=0;
    int i=0;
    // printf("RunAC1 is ok"); //used to test
    while ( s[i]){
        int x=s[i]-'0';
        if (NULL == p->next[x]){
            if (root1 == p){
                i++;
                continue;
            }
            p=p->fail;
            continue;
        }

        p=p->next[x];
        i++;
        if (p->end)
            score=Max(score, p->score);
    }

    return score;
}
/**
 * Run the AC automaton to evaluate the situation globally
 * @param  s [description]
 * @return   [description]
 */
int AllRunAC(char *s)
{
    Node *p=root;
    int score=0;
    int i=0;

    while ( s[i]){
        int x=s[i]-'0';
        if (NULL == p->next[x]){
            if (root ==p){
                i++;
                continue;
            }
            p=p->fail;
            continue;
        }

        p=p->next[x];
        i++;
        if (p->end){
            if (INF== p->score)
                return INF;
            score+= p->score;
        }
    }

    return score;
}
int AllRunAC1(char *s)
{
    Node *p= root1;
    int score=0;
    int i=0;

    while ( s[i]){
        int x= s[i]-'0';
        if (NULL == p->next[x]){
            if (root1 ==p){
                i++;
                continue;
            }
            p=p->fail;
            continue;
        }

        p= p->next[x];
        i++;
        if (p->end){
            if ( INF== p->score)
                return INF;
            score+= p->score;
        }
    }

    return score;
}