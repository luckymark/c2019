#include "pch.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"
#include "windows.h"

void init_system();   //初始化系统
void close_system();  //关闭系统
void init_globales(); //初始化参数

void play_chess();															 //开始五子棋游戏
void gamestart();															 //开始下棋
int count_xyk_by_message(MOUSEMSG *m, int *x, int *y, int *a, int *b);		 //计算鼠标所在区域状态
int judge(int a, int b, int c);							 //判断胜负条件
void regret(int x2, int y2,  int chessbox[][2]);			 //悔棋
void battleAI();															 //AI对战程序
void AIdecideNext(int *x, int *y, int *a, int *b, int num); //AI决策函数返回数组中下棋的下标。
int MaxMinSearch(int deep, int alpha, int beta, int num);	//alpha-beta搜索
int generator(int num);									//生成棋子位置
int evaluate(int num);										//评估全局面棋子得分
int evaluate_point(int x, int y, int num);					//单个点棋子得分

void draw_chessmen(int x, int y, int num, int a, int b); //绘制黑白棋子
void draw_chessboard();													  //画棋盘、菜单、状态框，画标题
void text();															  //绘制标题
void draw_menu();														  //绘制菜单
void over_black();														  //绘制黑棋胜字样
void over_white();														  //绘制白棋胜字样
void position();														  //绘制状态栏及内容
void text_black();														  //绘制黑棋下字样
void text_white();														  //绘制白棋下字样
void draw_regret(int m, int n, int x2, int y2);							  //所有悔棋情况
void draw_re(int x2, int y2);											  //绘制悔棋棋子


int m_x0, m_y0, m_wh = 40, m_x01, m_y01;		  //对战区坐标
int m_x_box, m_y_box, m_x_box1, m_y_box1;		  //棋盘起始坐标
int m_x_chess, m_y_chess, m_x_chess1, m_y_chess1; //可下棋坐标
int m_row = 14, m_row1 = 15;
int num = 0; //步数,偶数轮到黑棋下，奇数轮到白棋下
int chessbox[255][2];
int l_chess_range, r_chess_range, u_chess_range,d_chess_range;
int init_visit=1;


int Score_point[15][15];//评分数组
int minmax_result_x, minmax_result_y;
int chess[15][15] = { 0 };//记录棋盘上棋子信息
#define GAME_RUNNING 1
#define GAME_OVER 0
#define MOUSE_POS_ELSE 99
#define MOUSE_POS_AREA 1
#define NUM_BLACK 10
#define NUM_WHITE 20
#define MOUSE_POS_START 100
#define MOUSE_POS_REGRET 200
#define GAME_ROBOT 3
#define Inf 2 << 20

int main()
{
	init_system();

	draw_chessboard();

	play_chess();

	close_system();

	return 0;
}
/*================================================
== 函数名：AIdecideNext
== 功  能：AI对战系统
== 参  数：
		  int *x, int *y：交叉点横纵坐标
		  int *a, int *b：交叉点对应二维数组下标
		  level：难度
== 返回值：无
=================================================*/
void AIdecideNext(int *x, int *y, int *a, int *b, int num)
{
	//初始化一些变量start
	int deep = 6,beta= Inf,alpha= -Inf;
	//初始化一些变量end
	int AI_color = num % 2; //偶数0轮到黑棋下，奇数1轮到白棋下
	//alpha beta剪枝开始
	MaxMinSearch(deep,alpha,beta,AI_color);
	//alpha beta剪枝结束，结果放在	minmax_result_x，minmax_result_y中
	*a = minmax_result_x;
	*b = minmax_result_y;
	//得到数组坐标后进行转换
	*x = (*b) * m_wh + m_x0; //坐标横坐标
	*y = (*a) * m_wh + m_y0; //得到后传出

}
/*================================================
== 函数名：evaluate
== 功  能：评估局面分数
== 参  数：
			int num下棋数目
== 返回值：局面分数
=================================================*/
int evaluate(int num)//0就是黑棋将下，1白棋将下
{
	int x, y, i, j, k;      //循环变量 
	int number1 = 0, number2 = 0;   //number用来统计玩家或电脑棋子连成个数 
	int empty = 0;    //empty用来统计空点个数 
	int player_score = 0, AI_score = 0;//先记下来，后面优化可能用这个
	for (x = 0; x < 15; x++)            //把评分数组先清零 
		for (y = 0; y < 15; y++)
			Score_point[x][y] = 0;
	for (x = 0; x < 15; x++)
	{
		for (y = 0; y < 15; y++)
		{
			if (chess[x][y] == 0)    //如果这个点为空  
			{
				for (i = -1; i <= 1; i++)
				{
					for (j = -1; j <= 1; j++)   //判断8个方向  
					{
						if (i != 0 || j != 0)   //若是都为0的话，那不就是原坐标嘛 
						{
							//对玩家落点评分 
							for (k = 1; i <= 4; k++)   //循环4次 
							{                        //这点没越界  且这点存在黑子（玩家） 
								if (x + k * i >= 0 && x + k * i <= 14 &&
									y + k * j >= 0 && y + k * j <= 14 &&
									chess[x + k * i][y + k * j] == NUM_BLACK)
								{
									number1++;
								}
								else if (chess[x + k * i][y + k * j] == 0)     //这点是个空点，+1后退出 
								{
									empty++;
									break;
								}
								else                    //否则是墙或者对方的棋子了  
								{
									break;
								}
							}
							for (k = -1; k >= -4; k--)            //向它的相反方向判断  
							{                        //这点没越界  且这点存在黑子（玩家） 
								if (x + k * i >= 0 && x + k * i <= 14 &&
									y + k * j >= 0 && y + k * j <= 14 &&
									chess[x + k * i][y + k * j] == NUM_BLACK)
								{
									number1++;
								}
								else if (chess[x + k * i][y + k * j] == 0)     //这点是个空点，+1后退出 
								{
									empty++;
									break;
								}
								else
								{
									break;
								}
							}
							if (number2 == 1)   //2个棋子  
							{
								Score_point[x][y] += 100;
								player_score += 100;

							}
							else if (number1 == 2)   //3个棋子  
							{
								if (empty == 1)
								{
									Score_point[x][y] += 100;   //有一个空点+5分 死3  
									player_score += 100;
								}
								else if (empty == 2)
								{
									Score_point[x][y] += 1000;  //有两个空点+10分 活3 
									player_score += 1000;
								}
							}
							else if (number1 == 3)   //4个棋子  
							{
								if (empty == 1)
								{
									Score_point[x][y] += 1000;  //有一个空点+20分 死4  
									player_score += 1000;
								}
								else if (empty == 2)
								{
									Score_point[x][y] += 10000;  //有2个空点+100分 活4 
									player_score += 10000;
								}
							}
							else if (number1 >= 4)
							{
								Score_point[x][y] += 100000;  //对方有5个棋子，分数要高点，先堵 
								player_score += 100000;
							}
							empty = 0;   //统计空点个数的变量清零  
							//对电脑落点评分
							for (k = 1; i <= 4; k++)   //循环4次
							{       //这点没越界  且这点存在白子（电脑） 
								if (x + k * i >= 0 && x + k * i <= 14 &&
									y + k * j >= 0 && y + k * j <= 14 &&
									chess[x + k * i][y + k * j] == NUM_WHITE)
								{
									number2++;
								}
								else if (chess[x + k * i][y + k * j] == 0)
								{
									empty++; break;   //空点 
								}
								else
								{
									break;
								}
							}
							for (k = -1; k >= -4; k--)   //向它的相反方向判断  
							{
								if (x + k * i >= 0 && x + k * i <= 14 &&
									y + k * j >= 0 && y + k * j <= 14 &&
									chess[x + k * i][y + k * j] == NUM_WHITE)
								{
									number2++;
								}
								else if (chess[x + k * i][y + k * j] == 0)
								{
									empty++; break;
								}
								else
								{
									break;   //注释与上面玩家版相同 
								}
							}
							if (number2 == 0)
							{
								Score_point[x][y] += 10;    //1个棋子 
								AI_score += 10;
							}
							else if (number2 == 1)
							{
								Score_point[x][y] += 100;    //2个棋子  
								AI_score += 100;
							}
							else if (number2 == 2)   //3个棋子 
							{
								if (empty == 1)
								{
									Score_point[x][y] += 100;  //死3 
									AI_score += 100;
								}
								else if (empty == 2)
								{
									Score_point[x][y] += 1000;  //活3  
									AI_score += 1000;
								}
							}
							else if (number2 == 3)   //4个棋子 
							{
								if (empty == 1)
								{
									Score_point[x][y] += 1000;   //死4 
									AI_score += 1000;
								}
								else if (empty == 2)
								{
									Score_point[x][y] += 10000;   //活4 
									AI_score += 10000;
								}
							}
							else if (number2 >= 4)
							{
								Score_point[x][y] += 100000;   //自己落在这点能形成5个，也就能胜利了，分数最高 
								AI_score += 100000;
							}

							number1 = 0;     //清零，以便下次重新统计
							number2 = 0;
							empty = 0;
						}
					}
				}
			}
		}
	}
	return (num % 2) ? AI_score : player_score;//死编码，后面如果有需要记得改

}
/*================================================
== 函数名：evaluate_point
== 功  能：评估局面分数
== 参  数：
			int x,int y坐标
			int num下棋数
== 返回值：单个点分数
=================================================*/
int evaluate_point(int x,int y,int num)//0就是黑棋将下，1白棋将下
{
	int  i, j, k;      //循环变量 
	int number1 = 0, number2 = 0;   //number用来统计玩家或电脑棋子连成个数 
	int empty = 0;    //empty用来统计空点个数 
	int player_score = 0, AI_score = 0;//先记下来，后面优化可能用这个

			if (chess[x][y] == 0)    //如果这个点为空  
			{
				for (i = -1; i <= 1; i++)
				{
					for (j = -1; j <= 1; j++)   //判断8个方向  
					{
						if (i != 0 || j != 0)   //若是都为0的话，那不就是原坐标嘛 
						{
							//对玩家落点评分 
							for (k = 1; i <= 4; k++)   //循环4次 
							{                        //这点没越界  且这点存在黑子（玩家） 
								if (x + k * i >= 0 && x + k * i <= 14 &&
									y + k * j >= 0 && y + k * j <= 14 &&
									chess[x + k * i][y + k * j] == NUM_BLACK)
								{
									number1++;
								}
								else if (chess[x + k * i][y + k * j] == 0)     //这点是个空点，+1后退出 
								{
									empty++;
									break;
								}
								else                    //否则是墙或者对方的棋子了  
								{
									break;
								}
							}
							for (k = -1; k >= -4; k--)            //向它的相反方向判断  
							{                        //这点没越界  且这点存在黑子（玩家） 
								if (x + k * i >= 0 && x + k * i <= 14 &&
									y + k * j >= 0 && y + k * j <= 14 &&
									chess[x + k * i][y + k * j] == NUM_BLACK)
								{
									number1++;
								}
								else if (chess[x + k * i][y + k * j] == 0)     //这点是个空点，+1后退出 
								{
									empty++;
									break;
								}
								else
								{
									break;
								}
							}
							if (number2 == 1)   //2个棋子  
							{
								
								player_score += 100;

							}
							else if (number1 == 2)   //3个棋子  
							{
								if (empty == 1)
								{
									   //有一个空点+5分 死3  
									player_score += 100;
								}
								else if (empty == 2)
								{
									  //有两个空点+10分 活3 
									player_score += 1000;
								}
							}
							else if (number1 == 3)   //4个棋子  
							{
								if (empty == 1)
								{
									  //有一个空点+20分 死4  
									player_score += 1000;
								}
								else if (empty == 2)
								{
									 //有2个空点+100分 活4 
									player_score += 10000;
								}
							}
							else if (number1 >= 4)
							{
								//对方有5个棋子，分数要高点，先堵 
								player_score += 100000;
							}
							empty = 0;   //统计空点个数的变量清零  
							//对电脑落点评分
							for (k = 1; i <= 4; k++)   //循环4次
							{       //这点没越界  且这点存在白子（电脑） 
								if (x + k * i >= 0 && x + k * i <= 14 &&
									y + k * j >= 0 && y + k * j <= 14 &&
									chess[x + k * i][y + k * j] == NUM_WHITE)
								{
									number2++;
								}
								else if (chess[x + k * i][y + k * j] == 0)
								{
									empty++; break;   //空点 
								}
								else
								{
									break;
								}
							}
							for (k = -1; k >= -4; k--)   //向它的相反方向判断  
							{
								if (x + k * i >= 0 && x + k * i <= 14 &&
									y + k * j >= 0 && y + k * j <= 14 &&
									chess[x + k * i][y + k * j] == NUM_WHITE)
								{
									number2++;
								}
								else if (chess[x + k * i][y + k * j] == 0)
								{
									empty++; break;
								}
								else
								{
									break;   //注释与上面玩家版相同 
								}
							}
							if (number2 == 0)
							{
								   //1个棋子 
								AI_score += 10;
							}
							else if (number2 == 1)
							{
								    //2个棋子  
								AI_score += 100;
							}
							else if (number2 == 2)   //3个棋子 
							{
								if (empty == 1)
								{
								  //死3 
									AI_score += 100;
								}
								else if (empty == 2)
								{
									  //活3  
									AI_score += 1000;
								}
							}
							else if (number2 == 3)   //4个棋子 
							{
								if (empty == 1)
								{
									   //死4 
									AI_score += 1000;
								}
								else if (empty == 2)
								{
									  //活4 
									AI_score += 10000;
								}
							}
							else if (number2 >= 4)
							{
							   //自己落在这点能形成5个，也就能胜利了，分数最高 
								AI_score += 100000;
							}

							number1 = 0;     //清零，以便下次重新统计
							number2 = 0;
							empty = 0;
						}
					}
				}
			}
	return (num % 2) ? AI_score : player_score;//死编码，后面如果有需要记得改
}
/*================================================
== 函数名：generator
== 功  能：计算新的点
== 参  数：
			int num下棋数
			int buff_for_sort[255][3]保存点，用于启发式函数数组，最后排序
== 返回值：返回可行点数目
=================================================*/
int generator(int num, int buff_for_sort[255][3])
{
	int funtion_code = 1;//1是启发式生成
	//求出可行范围，选取原则是棋子范围+2的矩形
	int left_range = (l_chess_range - 2 >= 0) ? l_chess_range - 2 : 0;
	int right_range = ( r_chess_range<=12) ? r_chess_range + 2 : 14;
	int down_range = (d_chess_range - 2 >= 0) ? d_chess_range - 2 : 0;
	int up_range = (u_chess_range <= 12) ? u_chess_range + 2 : 14;
	//可行范围内遍历点
	int count_possible_point = 0;//记录有多少个可行点
	int search_amount = 10;//每个可行范围只搜评分高的10个点，启发式函数用
	for (int i = left_range; i <= right_range; i++)
	{
		for (int j = down_range; j <= up_range; j++)
		{
			if (chess[i][j] != NUM_BLACK && chess[i][j] != NUM_WHITE)//此格子上没有棋子时候才统计
			{
				if (funtion_code)
				{
					/*启发式函数用这*/
					buff_for_sort[count_possible_point][0] = evaluate_point(i, j, num);//0记录分数，1记录a，2记录b
				}

					/*普通搜索用这里*/
					buff_for_sort[count_possible_point][1] = i;//[0]留出用于启发式函数存东西
					buff_for_sort[count_possible_point][2] = j;

				count_possible_point++;
			}
		}
	}
	if (funtion_code)
	{
		//把分数大的放前面，笨办法,随手写的冒泡，复杂度O(n^2)也算之前没有考虑清楚，应该直接上结构体数组方便用sort,复杂度O(nlogn)
		for (int i = 0; i < count_possible_point-1; i++)
		{
			for (int j = i + 1; j < count_possible_point; j++)
			{
				if (buff_for_sort[i][0] < buff_for_sort[j][0])
				{
					int t = buff_for_sort[i][0];
					buff_for_sort[i][0] = buff_for_sort[j][0];
					buff_for_sort[j][0] = t;
					t = buff_for_sort[i][1];
					buff_for_sort[i][1] = buff_for_sort[j][1];
					buff_for_sort[j][1] = t;
					t = buff_for_sort[i][2];
					buff_for_sort[i][2] = buff_for_sort[j][2];
					buff_for_sort[j][2] = t;
				}
			}
		}
	}
	return count_possible_point;
}
/*================================================
== 函数名：MaxMinSearch(int deep,int beta,int alpha,int num)
== 功  能：alpha-beta搜索，带启发式搜索功能
== 参  数：
		  int deep 深度
		  alpha, beta 分别代表了最大层的最大值和最小层的最小值

== 返回值：评估得分
=================================================*/
int MaxMinSearch(int deep,int alpha,int beta,int num) //alpha是最大
{
	int heuristic_number = 10;//因为启发式函数已经排好序了，所以通常不用再搜那么多点，设置最多搜多少个点有好处。
	int buff_for_sort[255][3];
	for (int i = 0; i < 255; i++)
		for (int j = 0; j < 3; j++)
			buff_for_sort[i][j] = 0;
	int count_possible_point=generator(num%2,buff_for_sort);//得到可以下子的点,num%2得到的和之前相同，也就是说如果是0就是黑棋将下，1白棋将下，generator改变了buff_for_sort
	if (deep == 0 )//深度为0的时候直接评价返回
		return evaluate(num%2); // 根据局面评价函数直接返回，注意深度的层数,evaluate将返回一个人或者AI的分数
	else
	{
		int i = 0;
		//深度为奇数或者偶数都可以
		int heuristic_range = (heuristic_number < count_possible_point) ? heuristic_number :count_possible_point;//因为启发式函数已经排好序了，所以通常不用再搜那么多点,找更小那个就行
		for (;i< heuristic_range;i++)//在可行点内
		{
			//MakeNextMove
			chess[buff_for_sort[i][1]][buff_for_sort[i][2]] = (num % 2) ? NUM_WHITE: NUM_BLACK;//假设下了这步棋，可行点处都是空棋，不用判断是不是空棋了
			int num_pass = (num == 1) ? 0 : 1;//传入相反棋的颜色
			int val = -MaxMinSearch(deep-1, -beta, -alpha, num_pass);
			chess[buff_for_sort[i][1]][buff_for_sort[i][2]] = 0;//撤销假设棋子
			if (val >= beta)//在min层比beta大的不搜
			{
				minmax_result_x = buff_for_sort[i][1];//记下最后走哪个点
				minmax_result_y = buff_for_sort[i][2];//记下最后走哪个点
				return beta;
			}
			/*
			if (val <= alpha)
			{
				minmax_result_x = buff_for_sort[i][1];//记下最后走哪个点
				minmax_result_y = buff_for_sort[i][2];//记下最后走哪个点
				return alpha;
			}
			*/
			if (val > alpha)//相当于只做了beta剪枝，因为转换了问题
			{
				alpha = val;
			}
		}
		//如果此时还没有找到
		i = i - 1;
		minmax_result_x = buff_for_sort[i][1];//记下最后走哪个点
		minmax_result_y = buff_for_sort[i][2];//记下最后走哪个点
		return alpha;
	}
}
/*================================================
== 函数名：battleAI()
== 功  能：AI对战系统
== 参  数：无
== 返回值：无
=================================================*/
void battleAI()
{
	for (int ii = 0; ii < 15; ii++)
		for (int jj = 0; jj < 15; jj++)
		{
			chess[ii][jj] = 0;
		}

	draw_chessboard();
	num = 0;
	int x1, y1;
	x1 = m_x0 + m_wh * (m_row + 2);
	y1 = m_y0 + m_wh * 5;
	TCHAR str[] = _T("请下棋");
	settextstyle(m_wh, m_wh / 2 - 1, _T("楷体"));
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	outtextxy(x1 + 1, y1, str);

	int x, y; //鼠标坐标
	int pos;  //鼠标状态
	int x2, y2;
	int a, b;
	int mstate = GAME_RUNNING;
	MOUSEMSG m;
	IMAGE img;
	int exit_flag = 0;


	while (1)
	{
		m = GetMouseMsg();
		pos = count_xyk_by_message(&m, &x, &y, &a, &b); //鼠标点击后就由m得到x,y,a,b

		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
		{
			if (pos == MOUSE_POS_AREA)
			{
				if (chess[a][b] == NUM_BLACK || chess[a][b] == NUM_WHITE)
					continue; //If there has existed
				else
				{
					//people chess start
					draw_chessmen(x, y, num, a, b); //画出刚下的棋
					chessbox[num][0] = a;				   //记录此步的位置
					chessbox[num][1] = b;				   
					//text tip start
					if (num % 2 == 0)
					{
						text_white();
					}
					if (num % 2 != 0)
					{
						text_black();
					}
					//text tip end
					// 找出有棋子的矩形范围，方便后续操作start
					if (init_visit)
					{
						l_chess_range = a;
						r_chess_range = a;
						u_chess_range = b;
						d_chess_range = b;
					}
					else
					{
						l_chess_range = (l_chess_range > a) ? a : l_chess_range;
						r_chess_range = (r_chess_range < a) ? a : r_chess_range;
						u_chess_range = (u_chess_range < b) ? b : u_chess_range;
						d_chess_range = (d_chess_range > b) ? b : d_chess_range;

					}
					// 找出范围，方便后续操作end
					num++;  //步数++

					x2 = x; //暂存刚才的那一步，用于悔棋
					y2 = y;
					if (judge(a, b, NUM_BLACK))
					{
						over_black();
						return;
					}
					if (judge(a, b, NUM_WHITE))
					{
						over_white();
						return;
					}
					//people chess end

					//AI chess start
					AIdecideNext(&x, &y, &a, &b, num); //AI计算下一步去哪里
					// 找出范围，方便后续操作start
						l_chess_range = (l_chess_range > a) ? a : l_chess_range;
						r_chess_range = (r_chess_range < a) ? a : r_chess_range;
						u_chess_range = (u_chess_range < b) ? b : u_chess_range;
						d_chess_range = (d_chess_range > b) ? b : d_chess_range;
					// 找出范围，方便后续操作end

					draw_chessmen(x, y, num, a, b); //画出刚下的棋
					chessbox[num][0] = a;
					chessbox[num][1] = b;
					//text tip start
					if (num % 2 == 0)
					{
						text_white();
					}
					if (num % 2 != 0)
					{
						text_black();
					}
					//text tip end
					num++;
					x2 = x;
					y2 = y;
					if (judge(a, b, NUM_BLACK))
					{
						over_black();
						return;
					}
					if (judge(a, b, NUM_WHITE))
					{
						over_white();
						return;
					}
					//AI chess end
				}
			}
			/* AI暂不支持悔棋
			else if (pos == MOUSE_POS_REGRET)
			{
				regret(x2, y2,  chessbox);
			}
			*/
			else if (pos == GAME_OVER)
			{
				exit_flag = 1;
			}
		}
		}
		if (exit_flag)
			break; //如果点了退出回退上个页面
	}
}
/*================================================
== 函数名：init_system()
== 功  能：初始化系统
== 参  数：无
== 返回值：无
=================================================*/
void init_system()
{
	initgraph(1024, 768);
	init_globales();
	l_chess_range = 0;
	r_chess_range = 0;
	u_chess_range = 0;
	d_chess_range = 0;
}
/*================================================
== 函数名：close_system()
== 功  能：关闭系统
== 参  数：无
== 返回值：无
=================================================*/
void close_system()
{
	_getch();
	closegraph();
}
/*================================================
== 函数名：init_globales()
== 功  能：初始化参数
== 参  数：无
== 返回值：无
=================================================*/
void init_globales()
{
	m_x0 = 1024 / 2 - (m_row / 2) * m_wh; /*小棋盘*/
	m_x01 = m_x0 + m_row * m_wh;
	m_y0 = 768 / 2 - (m_row / 2) * m_wh;
	m_y01 = m_y0 + m_row * m_wh;

	m_x_box = m_x0 - m_wh; /*大棋盘*/
	m_x_box1 = m_x01 + m_wh;
	m_y_box = m_y0 - m_wh * 2;
	m_y_box1 = m_y01 + m_wh;

	m_x_chess = m_x0 - m_wh / 2; /*可下棋区域*/
	m_y_chess = m_y0 - m_wh / 2;
	m_x_chess1 = m_x01 + m_wh / 2;
	m_y_chess1 = m_y01 + m_wh / 2;
}
/*================================================
== 函数名：draw_chessboard()
== 功  能：画棋盘、菜单、状态框，画标题
== 参  数：无
== 返回值：无
=================================================*/
void draw_chessboard()
{
	//画棋盘
	int i;
	setbkcolor(BLACK);
	cleardevice(); /*用背景色清空屏幕*/
	setlinestyle(PS_SOLID, 1);
	setlinecolor(WHITE);
	rectangle(m_x_box, m_y_box, m_x_box1, m_y_box1);
	setfillcolor(RGB(172, 81, 24));
	setfillstyle(BS_SOLID);
	floodfill((m_x0 + m_x01) / 2, (m_y0 + m_y01) / 2, WHITE);

	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	rectangle(m_x0 - 4, m_y0 - 4, m_x01 + 4, m_y01 + 4);

	setlinestyle(PS_SOLID, 1);
	setlinecolor(BLACK);
	rectangle(m_x0, m_y0, m_x01, m_y01);

	for (i = m_x0 + m_wh; i < m_x01; i += m_wh) //绘制交叉线
	{
		line(i, m_y0, i, m_y01);
	}
	for (i = m_y0 + m_wh; i < m_y01; i += m_wh)
	{
		line(m_x0, i, m_x01, i);
	}

	setlinecolor(BLACK);
	setfillcolor(BLACK); /*绘制画笔颜色以及填充颜色*/

	fillcircle(m_x0 + m_wh * 3, m_y0 + m_wh * 3, 3); //绘制星位
	fillcircle(m_x0 + m_wh * 11, m_y0 + m_wh * 3, 3);
	fillcircle(m_x0 + m_wh * 3, m_y0 + m_wh * 11, 3);
	fillcircle(m_x0 + m_wh * 11, m_y0 + m_wh * 11, 3);
	fillcircle(m_x0 + m_wh * 7, m_y0 + m_wh * 7, 3);

	draw_menu(); /*绘制菜单*/
	position();  /*绘制状态框*/
	text();		 /*绘制标题*/
}
/*================================================
== 函数名：play_chess()
== 功  能：开始五子棋游戏
== 参  数：无
== 返回值：无
=================================================*/
void play_chess()
{
	int x, y; //鼠标坐标
	int pos;  //鼠标状态
	int a, b;
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		pos = count_xyk_by_message(&m, &x, &y, &a, &b);

		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN: /*判别鼠标左键点击区域*/
		{
			if (pos == MOUSE_POS_ELSE)
				continue; //其他区域
			if (pos == MOUSE_POS_START)
			{
				gamestart(); //开始方框
				break;
			}
			if (pos == GAME_ROBOT)
			{
				battleAI(); //开始方框
				break;
			}
			if (pos == GAME_OVER)
				exit(1); //结束方框
		}
		}
	}
}
/*================================================
== 函数名：gamestart()
== 功  能：开始下棋
== 参  数：无
== 返回值：无
=================================================*/
void gamestart()
{
	draw_chessboard();

	for(int ii=0;ii<15;ii++)
		for (int jj = 0; jj < 15; jj++)
		{
			chess[ii][jj] = 0;
		}

	num = 0;

	int x1, y1;
	x1 = m_x0 + m_wh * (m_row + 2);
	y1 = m_y0 + m_wh * 5;
	TCHAR str[] = _T("请下棋");
	settextstyle(m_wh, m_wh / 2 - 1, _T("楷体"));
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	outtextxy(x1 + 1, y1, str);

	int x, y; //鼠标坐标
	int pos;  //鼠标状态
	int x2, y2;
	int a, b;
	int mstate = GAME_RUNNING;
	MOUSEMSG m;
	IMAGE img;
	int exit_flag = 0;
	while (1)
	{
		m = GetMouseMsg();
		pos = count_xyk_by_message(&m, &x, &y, &a, &b);

		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
		{
			if (pos == MOUSE_POS_AREA)
			{
				if (chess[a][b] == NUM_BLACK || chess[a][b] == NUM_WHITE)
					continue;
				else
				{
					draw_chessmen(x, y, num, a, b);
					chessbox[num][0] = a;
					chessbox[num][1] = b;
					if (num % 2 == 0)
					{
						text_white();
					}
					if (num % 2 != 0)
					{
						text_black();
					}
					num++;
					x2 = x;
					y2 = y;
					if (judge(a, b, NUM_BLACK))
					{
						over_black();
						return;
					}
					if (judge(a, b, NUM_WHITE))
					{
						over_white();
						return;
					}
				}
			}
			else if (pos == MOUSE_POS_REGRET)
			{
				regret(x2, y2, chessbox);
			}
			else if (pos == GAME_OVER)
			{
				exit_flag = 1;
			}
		}
		}
		if (exit_flag)
			break; //如果点了退出回退上个页面
	}
}
/*============================================================================
== 函数名：count_xyk_by_message(MOUSEMSG *m, int *x, int *y, int *a, int *b)
== 功  能：计算鼠标所在区域状态，并返回点击区域信息
== 参  数：MOUSEMSG *m：鼠标信息
		  int *x, int *y：交叉点横纵坐标
		  int *a, int *b：交叉点对应二维数组下标
== 返回值：MOUSE_POS_AREA  ：可下棋区域
		  MOUSE_POS_START ：菜单开始方框
		  MOUSE_POS_REGRET：菜单悔棋方框
		  GAME_OVER       ：菜单结束方框
		  MOUSE_POS_ELSE  ：非功能区域
		  GAME_ROBOT      ：人机对战区域
==============================================================================*/
int count_xyk_by_message(MOUSEMSG *m, int *x, int *y, int *a, int *b)
{
	int x1, y1;

	x1 = m->x; // 鼠标的x信息
	y1 = m->y;

	if ((x1 >= m_x_chess && x1 <= m_x_chess1) && (y1 >= m_y_chess && y1 <= m_y_chess1)) //鼠标点在可下棋范围内
	{
		*x = m_x0 + (m->x - m_x_chess) / m_wh * m_wh; //交叉点横坐标等于这个转换公式
		*y = m_y0 + (m->y - m_y_chess) / m_wh * m_wh;

		*b = (*x - m_x_chess) / m_wh; //数组横坐标
		*a = (*y - m_y_chess) / m_wh;

		return (MOUSE_POS_AREA);
	}

	if ((x1 >= m_x0 - m_wh * 4 && x1 <= m_x0 - m_wh * 2) && (y1 >= m_y0 + m_wh * 3 && y1 <= m_y0 + m_wh * 4))
		return (MOUSE_POS_START);

	if ((x1 >= m_x0 - m_wh * 4 && x1 <= m_x0 - m_wh * 2) && (y1 >= m_y0 + m_wh * 5 && y1 <= m_y0 + m_wh * 6))
		return (MOUSE_POS_REGRET);

	if ((x1 >= m_x0 - m_wh * 4 && x1 <= m_x0 - m_wh * 2) && (y1 >= m_y0 + m_wh * 7 && y1 <= m_y0 + m_wh * 8))
		return (GAME_OVER);

	if ((x1 >= m_x0 - m_wh * 4 && x1 <= m_x0 - m_wh * 2) && (y1 >= m_y0 + m_wh * 9 && y1 <= m_y0 + m_wh * 10))
		return (GAME_ROBOT);

	return (MOUSE_POS_ELSE);
}
/*=========================================================================
== 函数名：void regret(int x2, int y2, int chessbox[][2])
== 功  能：悔棋
== 参  数：int x2, int y2：棋子所在的交叉点坐标
		  int chess[15][15]：交叉点棋子信息（判定是黑、白、无棋）
		  int chessbox[][2]：上一棋子数组下标
== 返回值：无
==========================================================================*/
void regret(int x2, int y2,  int chessbox[][2])
{
	int amount = 1;
	while (amount > 0)
	{
		int m, n;
		m = chessbox[num - 1][0];
		n = chessbox[num - 1][1];
		draw_regret(m, n, x2, y2);
		chess[m][n] = 0;
		num = num - 1;

		if (num % 2 == 0)
		{
			text_black();
		}
		if (num % 2 != 0)
		{
			text_white();
		}
		amount--;
	}
}
/*================================================
== 函数名：draw_regret(int m, int n, int x2, int y2)
== 功  能：绘制所有悔棋情况
== 参  数：int m, int n：棋子所在交叉点下标
		  int x2, int y2：棋子所在交叉点坐标
== 返回值：无
=================================================*/
void draw_regret(int m, int n, int x2, int y2)
{
	draw_re(x2, y2);
	if (m == 3 && n == 3)
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK);							 /*绘制画笔颜色以及填充颜色*/
		fillcircle(m_x0 + m_wh * 3, m_y0 + m_wh * 3, 3); //绘制星位
	}
	if (m == 3 && n == 11)
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK); /*绘制画笔颜色以及填充颜色*/
		fillcircle(m_x0 + m_wh * 11, m_y0 + m_wh * 3, 3);
	}
	if (m == 11 && n == 3)
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK); /*绘制画笔颜色以及填充颜色*/
		fillcircle(m_x0 + m_wh * 3, m_y0 + m_wh * 11, 3);
	}
	if (m == 11 && n == 11)
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK); /*绘制画笔颜色以及填充颜色*/
		fillcircle(m_x0 + m_wh * 11, m_y0 + m_wh * 11, 3);
	}
	if (m == 7 && n == 7)
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK); /*绘制画笔颜色以及填充颜色*/
		fillcircle(x2, y2, 3);
	}
	if (m == 0 && n == 0)
	{
		setlinecolor(RGB(172, 81, 24));
		setlinestyle(PS_SOLID, 1);
		line(x2, y2, x2 - 15, y2);
		line(x2, y2, x2, y2 - 15);
		setlinestyle(PS_SOLID, 2);
		setlinecolor(BLACK);
		rectangle(m_x0 - 4, m_y0 - 4, m_x01 + 4, m_y01 + 4);
	}
	if (m == 0 && n == 14)
	{
		setlinecolor(RGB(172, 81, 24));
		setlinestyle(PS_SOLID, 1);
		line(x2, y2, x2 + 15, y2);
		line(x2, y2, x2, y2 - 15);
		setlinestyle(PS_SOLID, 2);
		setlinecolor(BLACK);
		rectangle(m_x0 - 4, m_y0 - 4, m_x01 + 4, m_y01 + 4);
	}
	if (m == 14 && n == 0)
	{
		setlinecolor(RGB(172, 81, 24));
		setlinestyle(PS_SOLID, 1);
		line(x2, y2, x2 - 15, y2);
		line(x2, y2, x2, y2 + 15);
		setlinestyle(PS_SOLID, 2);
		setlinecolor(BLACK);
		rectangle(m_x0 - 4, m_y0 - 4, m_x01 + 4, m_y01 + 4);
	}
	if (m == 14 && n == 14)
	{
		setlinecolor(RGB(172, 81, 24));
		setlinestyle(PS_SOLID, 1);
		line(x2, y2, x2 + 15, y2);
		line(x2, y2, x2, y2 + 15);
		setlinestyle(PS_SOLID, 2);
		setlinecolor(BLACK);
		rectangle(m_x0 - 4, m_y0 - 4, m_x01 + 4, m_y01 + 4);
	}
	if ((n > 0 && n < 14) && m == 0)
	{
		setlinecolor(RGB(172, 81, 24));
		setlinestyle(PS_SOLID, 1);
		line(x2, y2, x2, y2 - 15);
		setlinestyle(PS_SOLID, 2);
		setlinecolor(BLACK);
		rectangle(m_x0 - 4, m_y0 - 4, m_x01 + 4, m_y01 + 4);
	}
	if ((n > 0 && n < 14) && m == 14)
	{
		setlinecolor(RGB(172, 81, 24));
		setlinestyle(PS_SOLID, 1);
		line(x2, y2, x2, y2 + 15);
		setlinestyle(PS_SOLID, 2);
		setlinecolor(BLACK);
		rectangle(m_x0 - 4, m_y0 - 4, m_x01 + 4, m_y01 + 4);
	}
	if ((m > 0 && m < 14) && n == 0)
	{
		setlinecolor(RGB(172, 81, 24));
		setlinestyle(PS_SOLID, 1);
		line(x2, y2, x2 - 15, y2);
		setlinestyle(PS_SOLID, 2);
		setlinecolor(BLACK);
		rectangle(m_x0 - 4, m_y0 - 4, m_x01 + 4, m_y01 + 4);
	}
	if ((m > 0 && m < 14) && n == 14)
	{
		setlinecolor(RGB(172, 81, 24));
		setlinestyle(PS_SOLID, 1);
		line(x2, y2, x2 + 15, y2);
		setlinestyle(PS_SOLID, 2);
		setlinecolor(BLACK);
		rectangle(m_x0 - 4, m_y0 - 4, m_x01 + 4, m_y01 + 4);
	}
}
/*================================================
== 函数名：draw_re(int x2, int y2)
== 功  能：绘制悔棋棋子
== 参  数：int x2, int y2：棋子所在交叉点坐标
== 返回值：无
=================================================*/
void draw_re(int x2, int y2)
{
	setlinecolor(RGB(172, 81, 24));
	setfillcolor(RGB(172, 81, 24));
	fillcircle(x2, y2, 15);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	line(x2 - 15, y2, x2 + 15, y2);
	line(x2, y2 - 15, x2, y2 + 15);
}
/*=============================================================================
== 函数名：draw_chessmen(int x, int y, int num, int a, int b)
== 功  能：绘制黑白棋子
== 参  数：int x, int y   ：下棋交叉点横纵坐标
		  int num        ：棋子数
		  int a, int b   ：交叉点数组下标
		  int chess[][15]：交叉点数组信息
== 返回值：无
===============================================================================*/
void draw_chessmen(int x, int y, int num, int a, int b)
{
	if (num % 2 == 0)
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, 15);
		chess[a][b] = NUM_BLACK;
	}

	if (num % 2 != 0)
	{
		setlinecolor(WHITE);
		setfillcolor(WHITE);
		fillcircle(x, y, 15);
		chess[a][b] = NUM_WHITE;
	}
}
/*================================================
== 函数名：text()
== 功  能：绘制标题
== 参  数：无
== 返回值：无
=================================================*/
void text()
{
	int x1, y1;
	TCHAR str[] = _T("五 子 棋");
	settextstyle(m_wh, m_wh, _T("黑体"));
	setbkcolor(RGB(172, 81, 24));
	settextcolor(BLACK);
	x1 = m_x0 + m_wh * 3;
	y1 = m_y0 - m_wh / 3 * 2 - 30;
	outtextxy(x1, y1, str);
}
/*================================================
== 函数名：judge(int a, int b, int c)
== 功  能：判断胜负条件
== 参  数：int a,int b   ：数组下标（代表行和列）
		  int c          ：代表颜色
		  int chess[][15]：代表棋子颜色
== 返回值：无
=================================================*/
int judge(int a, int b, int c)
{
	int i, j, n1, n2; //i 表示行，j表示列
	while (1)
	{
		n1 = 0;
		n2 = 0;
		/*水平向左统计同种颜色棋子个数*/
		for (i = a, j = b; j >= 0; j--)
		{
			if (chess[i][j] == c)
				n1++;
			else
				break;
		}
		/*水平向右统计同种颜色棋子个数*/
		for (i = a, j = b; j <= m_row1; j++)
		{
			if (chess[i][j] == c)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return (1);
			break;
		}
		/*垂直向上统计同种颜色棋子个数*/
		n1 = 0;
		n2 = 0;
		for (i = a, j = b; i >= 0; i--)
		{
			if (chess[i][j] == c)
				n1++;
			else
				break;
		}
		/*垂直向下统计同种颜色棋子个数*/
		for (i = a, j = b; i <= m_row1; i++)
		{
			if (chess[i][j] == c)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return (1);
			break;
		}
		/*向左上方统计同种颜色棋子个数*/
		n1 = 0;
		n2 = 0;
		for (i = a, j = b; i >= 0, j >= 0; i--, j--)
		{
			if (chess[i][j] == c)
				n1++;
			else
				break;
		}
		/*向右下方统计同种颜色棋子个数*/
		for (i = a, j = b; i <= m_row1, j <= m_row1; i++, j++)
		{
			if (chess[i][j] == c)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return (1);
			break;
		}
		/*向右上方统计同种颜色棋子个数*/
		n1 = 0;
		n2 = 0;
		for (i = a, j = b; i >= 0, j <= m_row1; i--, j++)
		{
			if (chess[i][j] == c)
				n1++;
			else
				break;
		}
		/*向左下方统计同种颜色棋子个数*/
		for (i = a, j = b; i <= m_row1, j >= 0; i++, j--)
		{
			if (chess[i][j] == c)
				n2++;
			else
				break;
		}

		if (n1 + n2 - 1 >= 5)
		{
			return (1);
			break;
		}
		return (0);
		break;
	}
}
/*================================================
== 函数名：draw_menu()
== 功  能：绘制菜单
== 参  数：无
== 返回值：无
=================================================*/
void draw_menu()
{
	int x, y;

	setlinestyle(PS_SOLID, 1);
	setlinecolor(WHITE);

	x = m_x0 - m_wh * 4;
	y = m_y0 + m_wh * 3;
	rectangle(x, y, x + m_wh * 2, y + m_wh); //开始方框
	setfillcolor(RGB(172, 81, 24));
	setfillstyle(BS_SOLID);
	floodfill(x + 1, y + 1, WHITE);
	TCHAR str1[] = _T("双人");
	settextstyle(m_wh - 2, m_wh / 2 - 2, _T("楷体"));
	setbkcolor(RGB(172, 81, 24));
	settextcolor(BLACK);
	outtextxy(x + 4, y + 1, str1);

	x = x;
	y = y + m_wh * 2;
	rectangle(x, y, x + m_wh * 2, y + m_wh); //悔棋方框
	setfillcolor(RGB(172, 81, 24));
	setfillstyle(BS_SOLID);
	floodfill(x + 1, y + 1, WHITE);
	TCHAR str2[] = _T("悔棋");
	settextstyle(m_wh - 2, m_wh / 2 - 2, _T("楷体"));
	setbkcolor(RGB(172, 81, 24));
	settextcolor(BLACK);
	outtextxy(x + 4, y + 1, str2);

	x = x;
	y = y + m_wh * 2;
	rectangle(x, y, x + m_wh * 2, y + m_wh); //结束方框
	setfillcolor(RGB(172, 81, 24));
	setfillstyle(BS_SOLID);
	floodfill(x + 1, y + 1, WHITE);
	TCHAR str3[] = _T("结束");
	settextstyle(m_wh - 2, m_wh / 2 - 2, _T("楷体"));
	setbkcolor(RGB(172, 81, 24));
	settextcolor(BLACK);
	outtextxy(x + 4, y + 1, str3);

	x = x;
	y = y + m_wh * 2;
	rectangle(x, y, x + m_wh * 2, y + m_wh); //人机对战方框
	setfillcolor(RGB(172, 81, 24));
	setfillstyle(BS_SOLID);
	floodfill(x + 1, y + 1, WHITE);
	TCHAR str4[] = _T("人机");
	settextstyle(m_wh - 2, m_wh / 2 - 2, _T("楷体"));
	setbkcolor(RGB(172, 81, 24));
	settextcolor(BLACK);
	outtextxy(x + 4, y + 1, str4);
}
/*================================================
== 函数名：over_black()
== 功  能：绘制黑棋胜字样
== 参  数：无
== 返回值：无
=================================================*/
void over_black()
{
	int x, y;
	x = m_x0 + m_wh * (m_row + 2);
	y = m_y0 + m_wh * 5;
	TCHAR str[] = _T("黑方胜");
	settextstyle(m_wh, m_wh / 2 - 1, _T("楷体"));
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	outtextxy(x + 1, y, str);
	TCHAR str1[] = _T("按开始再来一局");
	settextstyle(m_wh / 2, m_wh / 5 - 1, _T("黑体"));
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	x = m_x0 + m_wh * (m_row + 2) + 7;
	y = m_y0 + m_wh * 6;
	outtextxy(x + 1, y, str1);
}
/*================================================
== 函数名：over_white()
== 功  能：绘制白棋胜字样
== 参  数：无
== 返回值：无
=================================================*/
void over_white()
{
	int x, y;
	x = m_x0 + m_wh * (m_row + 2);
	y = m_y0 + m_wh * 5;
	TCHAR str[] = _T("白方胜");
	settextstyle(m_wh, m_wh / 2 - 1, _T("楷体"));
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	outtextxy(x + 1, y, str);
	TCHAR str1[] = _T("按开始再来一局");
	settextstyle(m_wh / 2, m_wh / 5 - 1, _T("黑体"));
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	x = m_x0 + m_wh * (m_row + 2) + 7;
	y = m_y0 + m_wh * 6;
	outtextxy(x + 1, y, str1);
}
/*================================================
== 函数名：position()
== 功  能：绘制状态栏及内容
== 参  数：无
== 返回值：无
=================================================*/
void position()
{
	int x, y;
	x = m_x0 + m_wh * (m_row + 2);
	y = m_y0 + m_wh * 4;
	setlinecolor(WHITE);
	rectangle(x, y, x + m_wh * 3, y + m_wh * 3);
	setfillcolor(RGB(172, 81, 24));
	setfillstyle(BS_SOLID);
	floodfill(x + 1, y + 1, WHITE);

	TCHAR str1[] = _T("提示");
	settextstyle(m_wh / 2, m_wh / 3, _T("楷体"));
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	outtextxy(x + m_wh / 3 * 2, y + 2, str1);

	x = x;
	y = y + m_wh;
	TCHAR str[] = _T("请点击开始");
	settextstyle(m_wh, m_wh / 3 - 2, _T("楷体"));
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	outtextxy(x, y, str);
}
/*================================================
== 函数名：text_black()
== 功  能：绘制黑棋下字样
== 参  数：无
== 返回值：无
=================================================*/
void text_black()
{
	int x, y;
	x = m_x0 + m_wh * (m_row + 2);
	y = m_y0 + m_wh * 5;
	TCHAR str[] = _T("黑子下");
	settextstyle(m_wh, m_wh / 2 - 1, _T("楷体"));
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	outtextxy(x + 1, y, str);
}
/*================================================
== 函数名：text_white()
== 功  能：绘制白棋下字样
== 参  数：无
== 返回值：无
=================================================*/
void text_white()
{
	int x, y;
	x = m_x0 + m_wh * (m_row + 2);
	y = m_y0 + m_wh * 5;
	TCHAR str[] = _T("白子下");
	settextstyle(m_wh, m_wh / 2 - 1, _T("楷体"));
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	outtextxy(x + 1, y, str);
}
