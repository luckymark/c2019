#include"evaluate.h"
#include"examasume.h"
int evaluate(int x,int y)//����һ������ĸ�����Ĺ�ֵ
{
    int i,j;
	i = x;
	j = y;
    int score=0;
    score+=leftrightexamassume(i,j)+updownexamassume(i,j)+leftuprightdownexamassume(i,j)+leftdownrightupexamassume(i,j);
    return score;
}
int evaluatehuman(int x, int y)
{
	int i, j;
	i = x;
	j = y;
	int score = 0;
	score += -leftrightexamassumehuman(i, j) - updownexamassumehuman(i, j) - leftuprightdownexamassumehuman(i, j)  -leftdownrightupexamassumehuman(i, j);

	return score;
}
