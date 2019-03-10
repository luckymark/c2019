#include <cstdio>
//Let f(n) be the solution of n plates.So just let f(n-1) move to temp storage pillar,the left one plate to
//the target pillar.At last move (n-1) plates in temp storage pillar to target pillar.
//Obviously,Recursion is a good method to solve this problem.
void hanoi(int n,char current_storage_pillar,char temp_storage_pillar,char target_storage_pillar)
{
    if(n==1)
    {
        printf("%c->%c  ",current_storage_pillar,target_storage_pillar);
        return;
    }
    hanoi(n-1,current_storage_pillar,target_storage_pillar,temp_storage_pillar);
    printf("%c->%c  ",current_storage_pillar,target_storage_pillar);
    hanoi(n-1,temp_storage_pillar,current_storage_pillar,target_storage_pillar);
}
int main()
{
    hanoi(4,'A','B','C');
    printf("\n");
    return 0;
}