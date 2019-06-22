#include"generate_evaluate.h"
/*void generate_evaluatehuman(board_empty* empty1)
{
	int score[300] = { 0 };
	int len = empty1->len;
	int i, j;
	int temp;
	for (i = 0; i < len; i++)
	{
		score[i] = evaluatehuman(empty1->board9[i].x, empty1->board9[i].y) ;
	}
	for(i=0;i<len;i++)
	{ 
		for (j = 0; j < len-i-1; j++)
		{
			if (score[j] > score[j + 1])
			{
				temp=empty1->board9[j+1].x;
				empty1->board9[j + 1].x = empty1->board9[j].x;
				empty1->board9[j].x=temp;
				temp = empty1->board9[j + 1].y;
				empty1->board9[j + 1].y = empty1->board9[j].y;
				empty1->board9[j].y = temp;
				temp =score[j];
				score[j] = score[j+1];
				score[j+1] = temp;
			}
		}
	}

	
}*/
void generate_evaluate(board_empty* empty1)
{
	int number = 0;
	board_empty Five;
	Five.len = 0;
	board_empty Comfour;
	Comfour.len = 0;
	board_empty Humfour;
	Humfour.len = 0;
	board_empty Comblock;
	Comblock.len = 0;
	board_empty Humblock;
	Humblock.len = 0;
	board_empty Comtwothree;
	Comtwothree.len = 0;
	board_empty  Humtwothree;
	Humtwothree.len = 0;
	board_empty Comthree;
	Comthree.len = 0;
	board_empty Comblockthree;
	Comblockthree.len = 0;
	board_empty Humblockthree;
	Humblockthree.len = 0;
	board_empty Humthree;
	Humthree.len = 0;
	board_empty Comtwo;
	Comtwo.len = 0;
	board_empty Humtwo;
	Humtwo.len = 0;
	board_empty Comblocktwo;
	Comblocktwo.len = 0;
	board_empty Humblocktwo;
	Humblocktwo.len = 0;
	board_empty Other;
	Other.len = 0;
	int i, j;
	int a0,a1,a2, a3, a4, a5, a6, a7, a8, a9, a10,a11,a12,a13,a14,a15,a16,a17;
	a0 = a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = a9 = a10 = a11 = a12 = a13=a14=a15=a16=a17=0;
	int scoreHum;
	int scoreCom;
	empty1->len = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j] == 0 && near1(i, j))//必须是有邻居的才行
			{	scoreHum = evaluatehuman(i, j);
			    scoreCom = evaluate(i, j);
									if (scoreCom >=FIVE)
									{//先看电脑能不能连成5
										empty1->board9[a0].x = i;
										empty1->board9[a0].y = j;
										empty1->len += 1;
										return;
									}
									else if (scoreHum >= FIVE)
									{//再看玩家能不能连成5
								   
										Five.len = a1 + 1;
										Five.board9[a1].x = i;
										Five.board9[a1].y = j;
										a1++;
									}
									else if (scoreCom >= FOUR) 
									{
										Comfour.len = a2 + 1;
										Comfour.board9[a2].x = i;
										Comfour.board9[a2].y = j;
										a2++;
									}
									else if (scoreHum >= FOUR) 
									{
										Humfour.len = a5 + 1;
										Humfour.board9[a5].x = i;
										Humfour.board9[a5].y = j;
										a5++;
									}
									else if (scoreCom >= BLOCKED_FOUR)
									{
										Comblock.len = a3 + 1;
										Comblock.board9[a3].x = i;
										Comblock.board9[a3].y = j;
										a3++;

									}
									else if (scoreHum >= BLOCKED_FOUR)
									{
										Humblock.len = a4 + 1;
										Humblock.board9[a4].x = i;
										Humblock.board9[a4].y = j;
										a4++;
									}
									else if (scoreCom >= 2 * THREE)
									{
										//双三
										Comtwothree.len = a6 + 1;
										Comtwothree.board9[a6].x = i;
										Comtwothree.board9[a6].y = j;
										a6++;
									}
									else if (scoreHum >= 2 * THREE)
									{
										Humtwothree.len = a7 + 1;
										Humtwothree.board9[a7].x = i;
										Humtwothree.board9[a7].y = j;
										a7++;
									}
									else if (scoreCom >= THREE) 
									{
										Comthree.len = a8 + 1;
										Comthree.board9[a8].x = i;
										Comthree.board9[a8].y = j;
										a8++;
									}
									else if (scoreHum >= THREE) 
									{
										Humthree.len = a9 + 1;
										Humthree.board9[a9].x = i;
										Humthree.board9[a9].y = j;
										a9++;
									}
									else if (scoreCom >= BLOCKED_THREE)
									{
										Comblockthree.len = a15 + 1;
										Comblockthree.board9[a15].x = i;
										Comblockthree.board9[a15].y = j;
										a15++;
									}
									else if (scoreHum >= BLOCKED_THREE)
									{
										Humblockthree.len = a14 + 1;
										Humblockthree.board9[a14].x = i;
										Humblockthree.board9[a14].y = j;
										a14++;
									}
									else if (scoreCom >= TWO) 
									{
										Comtwo.len = a10 + 1;
										Comtwo.board9[a10].x = i;
										Comtwo.board9[a10].y = j;
										a10++;
									}
									else if (scoreHum >= TWO) 
									{
										Humtwo.len = a11 + 1;
										Humtwo.board9[a11].x = i;
										Humtwo.board9[a11].y = j;
										a11++;
									}
									else if (scoreCom >= BLOCKED_TWO)
									{
									Comblocktwo.len = a16 + 1;
									Comblocktwo.board9[a16].x = i;
									Comblocktwo.board9[a16].y = j;
									a16++;
									}
									else if (scoreHum >= BLOCKED_TWO)
									{
									Humblocktwo.len = a17 + 1;
									Humblocktwo.board9[a17].x = i;
									Humblocktwo.board9[a17].y = j;
									a17++;
									}
									else 
									{
										Other.len = a12 + 1;
										Other.board9[a12].x = i;
										Other.board9[a12].y = j;
										a12++;
									}

				}
		}
	}

	//如果成五，是必杀棋，直接返回
	if (Five.len)
	{
		for (i = 0; i < Five.len; i++)
		{
			empty1->board9[i].x = Five.board9[i].x;
			empty1->board9[i].y = Five.board9[i].y;
			empty1->len ++;
		}
		return;
	}

	if (Comfour.len > 0 || Humfour.len > 0)
	{
		for (i = 0; i < Comfour.len; i++)
		{
			empty1->board9[i].x = Comfour.board9[i].x;
			empty1->board9[i].y = Comfour.board9[i].y;
			empty1->len ++;
		}
		for (i = Comfour.len,j=0; j < Humfour.len; j++)
		{
			empty1->board9[i+j].x = Humfour.board9[j].x;
			empty1->board9[i+j].y = Humfour.board9[j].y;
			empty1->len ++;
		}
		return ;
	}
	if (Comtwothree.len > 0 || Humtwothree.len > 0)
	{
		for (i = 0; i < Comtwothree.len; i++)
		{
			empty1->board9[i].x = Comtwothree.board9[i].x;
			empty1->board9[i].y = Comtwothree.board9[i].y;
			empty1->len ++;
		}
		for (i = Comtwothree.len, j = 0; j < Humtwothree.len; j++)
		{
			empty1->board9[i + j].x = Humtwothree.board9[j].x;
			empty1->board9[i + j].y = Humtwothree.board9[j].y;
			empty1->len ++;
		}
		return;
	}
	//以上都是杀棋，直接返回
	//以下按顺序存入
	for (i = 0; i < Comblock.len; i++)
	{
		empty1->board9[i].x = Comblock.board9[i].x;
		empty1->board9[i].y = Comblock.board9[i].y;
		empty1->len++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	for (i = Comblock.len,j= 0; j < Humblock.len; j++)
	{
		empty1->board9[i+j].x = Humblock.board9[j].x;
		empty1->board9[i+j].y = Humblock.board9[j].y;
		empty1->len++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	for (i = Comblock.len+ Humblock.len,j=0;j < Comthree.len; j++)
	{
		empty1->board9[i+j].x = Comthree.board9[j].x;
		empty1->board9[i+j].y = Comthree.board9[j].y;
		empty1->len ++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	for (i = Comthree.len+Comblock.len + Humblock.len, j = 0; j < Humthree.len; j++)
	{
		empty1->board9[i + j].x = Humthree.board9[j].x;
		empty1->board9[i + j].y = Humthree.board9[j].y;
		empty1->len ++;
		number++;
		if (number > 10)
		{
			return;
		}
	}	
	for (i = Comthree.len+ Humthree.len + Comblock.len + Humblock.len, j = 0; j < Comblockthree.len; j++)
	{
		empty1->board9[i + j].x = Comblockthree.board9[j].x;
		empty1->board9[i + j].y = Comblockthree.board9[j].y;
		empty1->len++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	for (i = Comthree.len + Humthree.len+ Comblockthree.len + Comblock.len + Humblock.len, j = 0; j < Humblockthree.len; j++)
	{
		empty1->board9[i + j].x = Humblockthree.board9[j].x;
		empty1->board9[i + j].y = Humblockthree.board9[j].y;
		empty1->len++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	for (i = Comthree.len+ Humthree.len+ Comblockthree.len+Humblockthree.len + Comblock.len + Humblock.len, j = 0; j < Comtwo.len; j++)
	{
		empty1->board9[i + j].x = Comtwo.board9[j].x;
		empty1->board9[i + j].y = Comtwo.board9[j].y;
		empty1->len ++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	for (i = Comthree.len + Humthree.len+ Comtwo.len + Comblockthree.len + Humblockthree.len + Comblock.len + Humblock.len, j = 0; j <Humtwo.len; j++)
	{
		empty1->board9[i + j].x = Humtwo.board9[j].x;
		empty1->board9[i + j].y = Humtwo.board9[j].y;
		empty1->len ++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	for (i = Comthree.len + Humthree.len + Comblockthree.len + Humblockthree.len+Comtwo.len+ Humtwo.len + Comblock.len + Humblock.len, j = 0; j < Comblocktwo.len; j++)
	{
		empty1->board9[i + j].x = Comblocktwo.board9[j].x;
		empty1->board9[i + j].y = Comblocktwo.board9[j].y;
		empty1->len++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	for (i = Comthree.len + Humthree.len  + Comblockthree.len + Humblockthree.len + Comtwo.len + Humtwo.len+ Comblocktwo.len + Comblock.len + Humblock.len, j = 0; j < Humblocktwo.len; j++)
	{
		empty1->board9[i + j].x = Humblocktwo.board9[j].x;
		empty1->board9[i + j].y = Humblocktwo.board9[j].y;
		empty1->len++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	for (i = Comthree.len + Humthree.len + Comtwo.len + Comblockthree.len + Humblockthree.len  + Humtwo.len + Comblocktwo.len + Humblocktwo.len + Comblock.len + Humblock.len, j = 0; j < Other.len; j++)
	{
		empty1->board9[i + j].x = Other.board9[j].x;
		empty1->board9[i + j].y = Other.board9[j].y;
		empty1->len ++;
		number++;
		if (number > 10)
		{
			return;
		}
	}
	return ;
	}