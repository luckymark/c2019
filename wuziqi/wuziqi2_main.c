#include "wuziqi_types.h"
#include "wuziqi2_main.h"
#include <time.h>
#include <sys/time.h>
#include<stdlib.h> 
/*
1、实现了极大极小值搜索.
2、增加alpha、beta的裁剪,效果一般。
*/
u8 gBoard[M_SIZE][M_SIZE];                      //棋盘
u8 AIChessColor = WHITE;                        //AI执白后行.
u8 humChessColor = BLACE;
u8 gDeep = DEEP;
u8 version = 2;

#if DEBUG
chess_queue gRecord;
#endif

/*初始化棋盘*/
static void gobang_init(void);
/*极大值层*/
static int max_alphabeta(s8 depth, chess_t chess, s32 alpha, s32 beta);
/*极小层*/	
static int min_alphabeta(s8 depth, chess_t chess, s32 alpha, s32 beta);

/*极大极小值算法*/
void chess_ai_minmax_alphabeta(chess_t *chess, s8 depth);
/*玩家下棋*/
static int hum_play_chess(void);
/*AI下棋*/
static int AI_play_chess(Boolean isFirst);
/*赢棋检测*/
Boolean is_win(u8 x, u8 y, u8 color);
/*打印棋盘*/
void print_chess_board(void);

//入口函数
int main(void)
{
    int ret = 0;
    u8 i = 0;
	printf("**************hello friend***************\n");
	printf("input:x,y play chess \n");
	printf("***************************************\n\n");
    gobang_init();
    while(i<(M_SIZE*M_SIZE)/2)
    {
        if (AIChessColor == BLACE) //执黑先行
        {
            //AI下棋
            if (i == 0)
            {
                ret = AI_play_chess(TRUE); //AI执黑第一次下棋,棋盘是空的
            }
            else
            {
                ret = AI_play_chess(FALSE);
            }
            if (GO_WIN == ret)      //胜利,打印棋盘,退出去
            {
                printf("AI win!\n");
                system("cls");
                print_chess_board();
                break;
            }
            print_chess_board();
            agin:
            //玩家下棋
            ret = hum_play_chess();
            if (-2 == ret)      //scanf输入报错,直接退出去
            {
                break;
            }
            else if (GO_OK != ret)//输入数据非法,超出15或已经有子的位置
            {
                goto agin;
            }
            else if (GO_WIN == ret)   //胜利
            {
                printf("Humber win!\n");
                system("cls");
                print_chess_board();
                break;
            }
            
        }
        else
        {   
            //玩家下棋
            ret = hum_play_chess();
            if (-2 == ret)      //scanf输入报错,直接退出去
            {
                break;
            }
            else if (GO_OK != ret)//输入数据非法,超出15或已经有子的位置
            {
                continue;
            }
            else if (GO_WIN == ret)   //胜利
            {
                printf("Humber win!\n");
                system("cls");
                print_chess_board();
                break;
            }
            print_chess_board();
            //AI下棋
            ret = AI_play_chess(FALSE);
            if (GO_WIN == ret)      //胜利,打印棋盘,退出去
            {
                printf("AI win!\n");
                system("cls");
                print_chess_board();
                break;
            }
        }
        system("cls");
        print_chess_board();
        i++;
    }
    return GO_OK;
}


/*
玩家下棋
*/
static int hum_play_chess(void)
{
    int x = 0;
    int y = 0;
    int ret = 0;
    printf("play chess:");
    ret = scanf("%d, %d", &x, &y);
    //玩家的子,从1算起
    x = x - 1;
    y = y - 1;
    if (!ret)
    {   
        printf("Scanf Error.\n");
        return -2;
    }
    if (check(x)||check(y))
    {
        printf("Number Error.\n");
        return GO_ERROR;
    }
    if (gBoard[x][y] != SPACE)
    {
        printf("Has chess.\n");
        return GO_ERROR;    
    }      
    gBoard[x][y] = humChessColor;
    if (is_win(x, y, humChessColor))
    {
        return GO_WIN;
    }
    return GO_OK;
}
/*AI下棋*/
static int AI_play_chess(Boolean isFirst)
{
    chess_t chess;
    chess.x = 0;
    chess.y = 0;
    struct timeval start_t, end_t;
    long use_time = 0;          //us
    //double use_time_sec = 0;
    if (isFirst)    //棋盘空的下棋,随机一个中间的子.(空子队列生成不了)
    {
        chess.x =(int)(rand()%5) + 5;
        chess.y =(int)(rand()%5) + 5; 
    }
    else
    {
        printf("Waiting AI...\n");
        gettimeofday(&start_t, NULL);
        chess_ai_minmax_alphabeta(&chess, gDeep);
        gettimeofday(&end_t, NULL);
        use_time = 1000000*(end_t.tv_sec - start_t.tv_sec)+(end_t.tv_usec - start_t.tv_usec);
    }
    printf("AI chess:(%d,%d),use time:%fs\n", chess.x+1, chess.y+1, use_time/1000000.0);
    gBoard[chess.x][chess.y] = AIChessColor;
    if (is_win(chess.x, chess.y, AIChessColor))
    {
        return GO_WIN;
    }
    return GO_OK;
}

/*初始化*/
static void gobang_init(void)
{
    u8 i, j;
#if DEBUG
    gRecord.len = gDeep;
#endif
    //AIChessColor = BLACE;                //配置为AI执黑子
    //humChessColor = WHITE;
    for (i=0; i<M_SIZE; i++)        
    {
        for (j=0; j<M_SIZE; j++)
        {
            gBoard[i][j] = SPACE;       //棋盘初始化
        }
    }  
}

/*打印棋盘*/
void print_chess_board(void)
{
    u8 i, j;
    printf("   ");
    for (i=0; i<M_SIZE; i++)
    {
        printf("%x ", i+1);
    }
    printf("\n  -------------------------------\n");
    for (j=0; j<M_SIZE; j++)
    {
        
        if (j<9)
        {
            printf("\n%d |", j+1);
        }
        else
        {
            printf("\n%d|", j+1);
        }
        for (i=0; i<M_SIZE; i++)
        {
            printf("%d ", gBoard[j][i]);
        }
        printf("|%d", j+1);
    }
    printf("\n  -------------------------------\n");
}

/*判断是否胜利*/
Boolean is_win(u8 x, u8 y, u8 color)
{           
	int count = 0;
	int i,j;
	int size = 15;
	//横
	for (i=(x-4>0?x-4:0); (i<=x+4)&&(i<size); i++) 
	{
		if (color == (gBoard[i][y]))
		{
			count++;
			if (count >= 5)
			{
				return TRUE;
			}
		}
		else
		{
			count = 0;
		}
	}
	//竖
	count = 0;
	for (j=(y-4>0?y-4:0); (j<=y+4)&&(j<size); j++) 
	{
		if (color == (gBoard[x][j]))
		{
			count++;
			if (count >= 5)
			{
				return TRUE;
			}
		}
		else
		{
			count = 0;
		}
	}
	//正斜线(\)
	count = 0;
	for (i=x-4,j=y-4;(i>=0)&&(i<=x+4)&&(i<size)&&(j>=0)&&(j<=y+4)&&(j<size); i++,j++) 
	{
		if (color == (gBoard[i][j]))
		{
			count++;
			if (count >= 5)
			{
				return TRUE;
			}
		}
		else
		{
			count = 0;
		}
	}
	//反斜线(/)
	count = 0;
	for (i=x-4,j=y+4;(i>=0)&&(i<=x+4)&&(i<size)&&(j>=y-4)&&(j>=0)&&(j<size); i++,j--) 
	{
		if (color == (gBoard[i][j]))
		{
			count++;
			if (count >= 5)
			{
				return TRUE;
			}
		}
		else
		{
			count = 0;
		}
	}
	return FALSE;
}

/*计分表,依据连子个数(bumber)和两端的空子个数(empty)*/
static u32 score_table(u8 number, u8 empty)
{
    if (number >= 5)
    {
        return WIN5;
    }
    else if (number == 4)
    {
        if (empty == 2)	
		{
            return ALIVE4;
		}
        else if (empty==1)
		{			
            return DIE4;
		}
    }
    else if (number == 3)	
    {
		if (empty == 2)	
		{
            return ALIVE3;
		}
		else if (empty == 1)
		{			
            return DIE3;
		}
	}
	else if (number == 2)
	{
		if (empty == 2)	
		{
            return ALIVE2;
		}
		else if (empty == 1)
		{			
            return DIE2;
		}
    }
    else if (number == 1&&empty == 2)
	{
        return ALIVE1;
	}
    return 0;
}


/*正斜线、反斜线、横、竖，均转成一维数组来计算*/
static u32 count_score(u8 n[], u8 chessColor)
{   
    u8 i = 1;           //n[0]已经提前计算
	u8 empty = 0;       //空的位子
	u8 number = 0;      //连子的个数
	u32 scoretmp = 0;
    if (n[0] == SPACE)	
    {
        empty++;
    }
	else if (n[0] == chessColor)
    {
        number++;
    }
    
    while (i < M_SIZE)
    {
        if (n[i] == chessColor)
        {
            number++;
        }
        else if (n[i] == SPACE)
        {
            if (number == 0)
            {
                empty = 1;
            }
            else
            {
                scoretmp += score_table(number, empty+1);
				empty = 1;
				number = 0;
            }
        }
        else
		{
			scoretmp += score_table(number, empty);
			empty = 0;
			number = 0;
		}
		i++;
    }
    scoretmp += score_table(number, empty);
	return scoretmp;
}

/*把当前局势所有连线都存到一维数组,然后算一遍分数*/
static s32 evaluate_board(void)//评估函数，评估局势
{
	u32 AIScore=0;
	u32 humScore=0;
    u8 i, j;
    s8 x, y;        //如果是u8,x--,y--运算时可能溢出
    u8 n[M_SIZE];
    memset(n, 0, sizeof(n));
	//横排 
	for (i=0; i<M_SIZE; i++)
	{
        for(j=0; j<M_SIZE; j++)
        {
            n[j] = gBoard[i][j];
        }
    	AIScore += count_score(n, AIChessColor);
    	humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	}
	//纵排
	for (j=0; j<M_SIZE; j++)
	{
		for(i=0; i<M_SIZE; i++)
        {      
            n[i] = gBoard[i][j];
        }
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
	//上半正斜线(\)
	for (i=0; i<M_SIZE; i++)
	{
		for(x=i,y=0; x<M_SIZE&&y<M_SIZE; x++,y++)
		{
            n[y] = gBoard[x][y];
		}
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
	//下半正斜线
	for (j=1; j<M_SIZE; j++)
	{
		for(x=0,y=j; y<M_SIZE&&x<M_SIZE; x++,y++)
		{
            n[x] = gBoard[x][y];
		}
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
	//上半反斜线(/)
	for (i=0; i<M_SIZE; i++)
	{
		for(y=i,x=0; y>=0&&x<M_SIZE; y--,x++)
		{
            n[x] = gBoard[x][y];
		}
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
	//下半反斜线
	for (j=1; j<M_SIZE; j++)
	{
		for (y=j,x=M_SIZE-1; y<M_SIZE&&x>=0; y++,x--)
		{
            n[y-j] = gBoard[x][y];
		}
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
    return AIScore-humScore;
}

/*是否有邻居:两步之内是否有子存在(不论是对手还是自己的子都可以)*/
static Boolean has_neighbors(int x, int y)
{
	int s = 2;	//两步之内有子
	u8 i = 0, j = 0;
	for (i=(x-s>0?x-s:0); i<=x+s&&i<M_SIZE; i++)
		for (j=(y-s>0?y-s:0); j<=y+s&&j<M_SIZE; j++)
			if (i!=0 || j!=0)
				if (SPACE != (gBoard[i][j]))
					return TRUE;
	return FALSE;
}

//还可以优化:将目标空子们先进行估分，然后排序,因为alpha-beta剪枝依赖于空子顺序.
/*产生空子序列(可以下子的空位)*/		
static void generate_point(chess_queue *queue)	
{
    int i,j,k = 0;
	for (i=0; i<M_SIZE; i++)
    {   
		for (j=0; j<M_SIZE; j++)
        {      
			if ((gBoard[i][j]==SPACE) && has_neighbors(i,j))//有邻居的空子,做为可下子的队列
			{
                queue->chess[k].x = i;
                queue->chess[k].y = j;
                queue->len = k+1;
                k++;
			}
        }
    }
}

#if 0
static int max_alphabeta(s8 depth, chess_t chess)	
{
	s32 res = evaluate_board();
    u8 i, x, y;
    s32 tmpScore;
    s32 best = -WIN5;
    chess_queue queue; 
	if ((depth <= 0) || (is_win(chess.x, chess.y, humChessColor)))//上一步是玩家下棋可能产生输赢
	{
        return res;
	}
	generate_point(&queue);			//生成可以下棋子的空子序列
	for (i=0; i<queue.len; i++)
	{
	    x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = AIChessColor;    //尝试下一个子
        tmpScore = min_alphabeta(depth-1, queue.chess[i]);
        gBoard[x][y] = SPACE;           //恢复成空子
		if (tmpScore > best)
        {
            best = tmpScore; 
        }
	} 
	return best;
}

static int min_alphabeta(s8 depth, chess_t chess)										 
{
	s32 res = evaluate_board();
    u8 i, x, y;
    s32 tmpScore;
    s32 best = WIN5;
    chess_queue queue;
    if ((depth <= 0) || (is_win(chess.x, chess.y, AIChessColor)))//上一步是AI下棋可能产生输赢
    {
        return res;
    }
	generate_point(&queue);
	for (i=0; i<queue.len; i++)
	{
	    x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = humChessColor;    //尝试下一个子
        tmpScore = max_alphabeta(depth-1, queue.chess[i]);
        gBoard[x][y] = SPACE;  
		if (tmpScore < best)
        {
            best = tmpScore; 
        }
	} 
	return best;
}
#endif

//alpha：表示目前为止上一层找到的最小数
//beta：表示目前为止上一层找到的最大数
/*当min层（玩家）下棋时,考虑最坏的情况*/
static int min_alphabeta(s8 depth, chess_t chess, s32 alpha, s32 beta)
{
	s32 res = evaluate_board();
    u8 i, x, y;
    s32 tmpScore;
    s32 best = WIN5;
    chess_queue queue;
#if DEBUG    
    if (depth <= 0)
    {
        if (res > 0)
        {
            for (i=0; i<gRecord.len; i++)
            {
                printf("deep%d:(%d,%d)->", gDeep-i, gRecord.chess[i].x, gRecord.chess[i].y);
            }
            printf("%d\n", res);
        }
    }
#endif
    if ((depth <= 0) || (is_win(chess.x, chess.y, AIChessColor)))//上一步是AI下棋可能产生输赢
    {
        return res;
    }
    if (check(chess.x)| check(chess.y))
    {
        printf("Min Error!\n");
        return GO_ERROR;
    }
	generate_point(&queue);
	for (i=0; i<queue.len; i++)
	{
	    x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = humChessColor;    //尝试下一个子
    #if DEBUG
        gRecord.chess[gRecord.len-depth].x = x; 
        gRecord.chess[gRecord.len-depth].y = y;
    #endif
    
        tmpScore = max_alphabeta(depth-1, queue.chess[i], best<alpha?best:alpha, beta);
        gBoard[x][y] = SPACE;  
		if (tmpScore < best)
        {      
            best = tmpScore; 
        }

        if (tmpScore < beta)
        {
            break;
        }
	} 
	return best;
}

/*当max层（电脑AI）下棋时,考虑最好的情况*/
static int max_alphabeta(s8 depth, chess_t chess, s32 alpha, s32 beta)	
{
	s32 res = evaluate_board();
    u8 i, x, y;
    s32 tmpScore;
    s32 best = -WIN5;
    chess_queue queue;
#if DEBUG    
    if (depth <= 0)
    {
        //if (res > 0)
        {
            for (i=0; i<gRecord.len; i++)
            {
                printf("deep%d:(%d,%d)->", gDeep-i, gRecord.chess[i].x, gRecord.chess[i].y);
            }
            printf("%d\n", res);
        }
    }
#endif   
	if ((depth <= 0) || (is_win(chess.x, chess.y, humChessColor)))//上一步是玩家下棋可能产生输赢
	{
        return res;
	}
    if (check(chess.x)| check(chess.y))
    {
        printf("Max Error!\n");
        return GO_ERROR;
    }
	generate_point(&queue);

	for (i=0; i<queue.len; i++)
	{
	    x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = AIChessColor;    //尝试下一个子
    #if DEBUG
        gRecord.chess[gRecord.len-depth].x = x;
        gRecord.chess[gRecord.len-depth].y = y;
    #endif
        tmpScore = min_alphabeta(depth-1, queue.chess[i], alpha, best>beta?best:beta);
        gBoard[x][y] = SPACE;           //恢复成空子
		if (tmpScore > best)
        {      
            best = tmpScore; 
        }
        if (tmpScore > alpha)
        {
            break;
        }
	} 
	return best;
}

/*极大极小值搜索depth步后的最优解*/
void chess_ai_minmax_alphabeta(chess_t *chess, s8 depth)
{
	u8 i = 0, k = 0;
    u8 x = 0, y = 0;
    s32 tmp = 0;
    s32 best = -WIN5;
    chess_queue option_queue;           //待选的空子队列
    chess_queue sure_queue;             //最合适的下子位置
	generate_point(&option_queue);
    
	for (i=0; i<option_queue.len; i++)
	{
        x = option_queue.chess[i].x;
        y = option_queue.chess[i].y;
	    gBoard[x][y] = AIChessColor;    //将该子置AI选的颜色，防止后面递归时，再递归到
    #if DEBUG							//用于打印回溯
	    gRecord.chess[gRecord.len-depth].x = x;      
        gRecord.chess[gRecord.len-depth].y = y;
        printf("###############deep:%d(%d,%d)################\n", depth, x, y);
    #endif
        tmp = min_alphabeta(depth-1, option_queue.chess[i], WIN5, -WIN5);        
		if (tmp == best)
        {      
            sure_queue.chess[k].x = option_queue.chess[i].x;
            sure_queue.chess[k].y = option_queue.chess[i].y;
			sure_queue.len = k+1;
            k++;
        }
		if (tmp > best)    //找到一个更好的分,把以前存的位子全部清除
		{
			best = tmp;
            k = 0;
			sure_queue.len = 1;         //清空终选队列
            sure_queue.chess[k].x = option_queue.chess[i].x;
            sure_queue.chess[k].y = option_queue.chess[i].y;
		}
		gBoard[x][y] = SPACE;           //恢复成空子
	}
	k =(int)(rand()%sure_queue.len);    //如果有多个最高分数,随机选择一个
	if (check(sure_queue.chess[k].x)||check(sure_queue.chess[k].y))
    {
        chess->x = 0;
        chess->y = 0;
        printf("Error AI space(%d,%d)\n", sure_queue.chess[k].x, sure_queue.chess[k].y);
        return;
    }
	chess->x = sure_queue.chess[k].x;
	chess->y = sure_queue.chess[k].y;
}


