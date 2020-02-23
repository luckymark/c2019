#include"head.h"

int Left_Right2(char board[N][N][L],int state)
{
	int PChar=state;
	int FIVE=0,FOUR=0,THREE=0,TWO=0,ONE=0,HFOUR=0,HTHREE=0,HTWO=0,HONE=0;		//各种棋局情况：连五，活四，活三，活二，活一，半四，半三，半二，半一
	int LRscore;
	int i,j;
	for(i=0;i<N;i++)
	{
		j=0;
		while(j<N)
		{
			int First=0,Last=0;
			if(board[i][j][1]==PChar)
			{
				First=j;
				int count;
				while(j<N&&board[i][j][1]==PChar)
				{
					j++;
				}
				Last=j;
				count=Last-First;
				int liveleft=0,liveright=0,flaglive=0,flaghalf=0;						//判断是否有一边被堵死
				if(First-1>=0&&board[i][First-1][1]!=BC&&board[i][First-1][1]!=WC)
					liveleft=1;
				if(Last<N&&board[i][Last][1]!=BC&&board[i][Last][1]!=WC)
					liveright=1;
				if(liveleft&&liveright)
					flaglive=1;
				if(liveleft||liveright)
					flaghalf=1;
				switch(count)
				{
					case 1:
						{
							if(flaglive)
								ONE++;
							else
								if(flaghalf)
									HONE++;
							break;
						}
					case 2:
						{
							if(flaglive)
								TWO++;
							else
								if(flaghalf)
									HTWO++;
							break;
						}
					case 3:
						{
							if(flaglive)
								THREE++;
							else
								if(flaghalf)
									HTHREE++;
							break;
						}
					case 4:
						{
							if(flaglive)
								FOUR++;
							else
								if(flaghalf)
									HFOUR++;
							break;
						}
					case 5:
						{
							FIVE++;
							break;
						}
					default:;
				}
			}
			j++;
		}
	}
	LRscore=1000000*FIVE+10000*FOUR+1000*(THREE+HFOUR)+100*(TWO+HTHREE)+10*(ONE+HTWO)+HONE;
	return LRscore;
}

int Up_Down2(char board[N][N][L],int state)
{
	int PChar=state;
	int FIVE=0,FOUR=0,THREE=0,TWO=0,ONE=0,HFOUR=0,HTHREE=0,HTWO=0,HONE=0;		//各种棋局情况：连五，活四，活三，活二，活一，半四，半三，半二，半一
	int UDscore;
	int i,j;
	for(i=0;i<N;i++)
	{
		j=0;
		while(j<N)
		{
			int First=0,Last=0;
			if(board[j][i][1]==PChar)
			{
				First=j;
				int count;
				while(j<N&&board[j][i][1]==PChar)
				{
					j++;
				}
				Last=j;
				count=Last-First;
				int liveup=0,livedown=0,flaglive=0,flaghalf=0;						//判断是否有一边被堵死
				if(First-1>=0&&board[First-1][i][1]!=BC&&board[First-1][i][1]!=WC)
					liveup=1;
				if(Last<N&&board[Last][i][1]!=BC&&board[Last][i][1]!=WC)
					livedown=1;
				if(liveup&&livedown)
					flaglive=1;
				if(liveup||livedown)
					flaghalf=1;
				switch(count)
				{
					case 1:
						{
							if(flaglive)
								ONE++;
							else
								if(flaghalf)
									HONE++;
							break;
						}
					case 2:
						{
							if(flaglive)
								TWO++;
							else
								if(flaghalf)
									HTWO++;
							break;
						}
					case 3:
						{
							if(flaglive)
								THREE++;
							else
								if(flaghalf)
									HTHREE++;
							break;
						}
					case 4:
						{
							if(flaglive)
								FOUR++;
							else
								if(flaghalf)
									HFOUR++;
							break;
						}
					case 5:
						{
							FIVE++;
							break;
						}
					default:;
				}
			}
			j++;
		}
	}
	UDscore=1000000*FIVE+10000*FOUR+1000*(THREE+HFOUR)+100*(TWO+HTHREE)+10*(ONE+HTWO)+HONE;
	return UDscore;
}

int Left_Up2(char board[N][N][L],int state)
{
	int PChar=state;
	int FIVE=0,FOUR=0,THREE=0,TWO=0,ONE=0,HFOUR=0,HTHREE=0,HTWO=0,HONE=0;		//各种棋局情况：连五，活四，活三，活二，活一，半四，半三，半二，半一
	int LUscore;
	int i,j;
	i=0;
	while(i<N)														//先判断对角线
	{
		int First=0,Last=0;
		if(board[i][i][1]==PChar)
		{
			First=i;
			int count;
			while(i<N&&board[i][i][1]==PChar)
			{
				i++;
			}
			Last=i;
			count=Last-First;
			int livelu=0,liverd=0,flaglive=0,flaghalf=0;						//判断是否有一边被堵死
			if(First-1>=0&&board[First-1][First-1][1]!=BC&&board[First-1][First-1][1]!=WC)
				livelu=1;
			if(Last<N&&board[Last][Last][1]!=BC&&board[Last][Last][1]!=WC)
				liverd=1;
			if(livelu&&liverd)
				flaglive=1;
			if(livelu||liverd)
				flaghalf=1;
			switch(count)
			{
				case 1:
					{
						if(flaglive)
							ONE++;
						else
							if(flaghalf)
								HONE++;
						break;
					}
				case 2:
					{
						if(flaglive)
							TWO++;
						else
							if(flaghalf)
								HTWO++;
						break;
					}
				case 3:
					{
						if(flaglive)
							THREE++;
						else
							if(flaghalf)
								HTHREE++;
						break;
					}
				case 4:
						{
						if(flaglive)
							FOUR++;
						else
							if(flaghalf)
								HFOUR++;
						break;
					}
				case 5:
					{
						FIVE++;
						break;
					}
				default:;
			}
		}
		i++;
	}
	for(i=0;i<N-1;i++)
	{
		j=0;
		while(j<=i)
		{
			int First=0,Last=0;
			if(board[N-1-i+j][j][1]==PChar)
			{
				First=j;
				int count;
				while(j<=i&&board[N-1-i+j][j][1]==PChar)
				{
					j++;
				}
				Last=j;
				count=Last-First;
				int liveup=0,livedown=0,flaglive=0,flaghalf=0;						//判断是否有一边被堵死
				if(First-1>=0&&board[N-1-i+First-1][First-1][1]!=BC&&board[N-1-i+First-1][First-1][1]!=WC)
					liveup=1;
				if(Last<=i&&board[N-1-i+Last][Last][1]!=BC&&board[N-1-i+Last][Last][1]!=WC)
					livedown=1;
				if(liveup&&livedown)
					flaglive=1;
				if(liveup||livedown)
					flaghalf=1;
				switch(count)
				{
					case 1:
						{
							if(flaglive)
								ONE++;
							else
								if(flaghalf)
									HONE++;
							break;
						}
					case 2:
						{
							if(flaglive)
								TWO++;
							else
								if(flaghalf)
									HTWO++;
							break;
						}
					case 3:
						{
							if(flaglive)
								THREE++;
							else
								if(flaghalf)
									HTHREE++;
							break;
						}
					case 4:
						{
							if(flaglive)
								FOUR++;
							else
								if(flaghalf)
									HFOUR++;
							break;
						}
					case 5:
						{
							FIVE++;
							break;
						}
					default:;
				}
			}
			j++;
		}
	}
	for(i=0;i<N-1;i++)
	{
		j=0;
		while(j<=i)
		{
			int First=0,Last=0;
			if(board[j][N-1-i+j][1]==PChar)
			{
				First=j;
				int count;
				while(j<=i&&board[j][N-1-i+j][1]==PChar)
				{
					j++;
				}
				Last=j;
				count=Last-First;
				int liveup=0,livedown=0,flaglive=0,flaghalf=0;						//判断是否有一边被堵死
				if(First-1>=0&&board[First-1][N-1-i+First-1][1]!=BC&&board[First-1][N-1-i+First-1][1]!=WC)
					liveup=1;
				if(Last<=i&&board[Last][N-1-i+Last][1]!=BC&&board[Last][N-1-i+Last][1]!=WC)
					livedown=1;
				if(liveup&&livedown)
					flaglive=1;
				if(liveup||livedown)
					flaghalf=1;
				switch(count)
				{
					case 1:
						{
							if(flaglive)
								ONE++;
							else
								if(flaghalf)
									HONE++;
							break;
						}
					case 2:
						{
							if(flaglive)
								TWO++;
							else
								if(flaghalf)
									HTWO++;
							break;
						}
					case 3:
						{
							if(flaglive)
								THREE++;
							else
								if(flaghalf)
									HTHREE++;
							break;
						}
					case 4:
						{
							if(flaglive)
								FOUR++;
							else
								if(flaghalf)
									HFOUR++;
							break;
						}
					case 5:
						{
							FIVE++;
							break;
						}
					default:;
				}
			}
			j++;
		}
	}
	LUscore=1000000*FIVE+10000*FOUR+1000*(THREE+HFOUR)+100*(TWO+HTHREE)+10*(ONE+HTWO)+HONE;
	return LUscore;
}

int Left_Down2(char board[N][N][L],int state)
{
	int PChar=state;
	int FIVE=0,FOUR=0,THREE=0,TWO=0,ONE=0,HFOUR=0,HTHREE=0,HTWO=0,HONE=0;		//各种棋局情况：连五，活四，活三，活二，活一，半四，半三，半二，半一
	int LDscore;
	int i,j;
	i=0;
	while(i<N)														//先判断对角线
	{
		int First=0,Last=0;
		if(board[i][N-1-i][1]==PChar)
		{
			First=i;
			int count;
			while(i<N&&board[i][N-1-i][1]==PChar)
			{
				i++;
			}
			Last=i;
			count=Last-First;
			int livelu=0,liverd=0,flaglive=0,flaghalf=0;						//判断是否有一边被堵死
			if(First-1>=0&&board[First-1][N-1-(First-1)][1]!=BC&&board[First-1][N-1-(First-1)][1]!=WC)
				livelu=1;
			if(Last<N&&board[Last][N-1-Last][1]!=BC&&board[Last][N-1-Last][1]!=WC)
				liverd=1;
			if(livelu&&liverd)
				flaglive=1;
			if(livelu||liverd)
				flaghalf=1;
			switch(count)
			{
				case 1:
					{
						if(flaglive)
							ONE++;
						else
							if(flaghalf)
								HONE++;
						break;
					}
				case 2:
					{
						if(flaglive)
							TWO++;
						else
							if(flaghalf)
								HTWO++;
						break;
					}
				case 3:
					{
						if(flaglive)
							THREE++;
						else
							if(flaghalf)
								HTHREE++;
						break;
					}
				case 4:
						{
						if(flaglive)
							FOUR++;
						else
							if(flaghalf)
								HFOUR++;
						break;
					}
				case 5:
					{
						FIVE++;
						break;
					}
				default:;
			}
		}
		i++;
	}
	for(i=0;i<N-1;i++)
	{
		j=0;
		while(j<=i)
		{
			int First=0,Last=0;
			if(board[j][i-j][1]==PChar)
			{
				First=j;
				int count;
				while(j<=i&&board[j][i-j][1]==PChar)
				{
					j++;
				}
				Last=j;
				count=Last-First;
				int liveup=0,livedown=0,flaglive=0,flaghalf=0;						//判断是否有一边被堵死
				if(First-1>=0&&board[First-1][i-(First-1)][1]!=BC&&board[First-1][i-(First-1)][1]!=WC)
					liveup=1;
				if(Last<=i&&board[Last][i-Last][1]!=BC&&board[Last][i-Last][1]!=WC)
					livedown=1;
				if(liveup&&livedown)
					flaglive=1;
				if(liveup||livedown)
					flaghalf=1;
				switch(count)
				{
					case 1:
						{
							if(flaglive)
								ONE++;
							else
								if(flaghalf)
									HONE++;
							break;
						}
					case 2:
						{
							if(flaglive)
								TWO++;
							else
								if(flaghalf)
									HTWO++;
							break;
						}
					case 3:
						{
							if(flaglive)
								THREE++;
							else
								if(flaghalf)
									HTHREE++;
							break;
						}
					case 4:
						{
							if(flaglive)
								FOUR++;
							else
								if(flaghalf)
									HFOUR++;
							break;
						}
					case 5:
						{
							FIVE++;
							break;
						}
					default:;
				}
			}
			j++;
		}
	}
	for(i=0;i<N-1;i++)
	{
		j=0;
		while(j<=i)
		{
			int First=0,Last=0;
			if(board[N-1-i+j][N-1-j][1]==PChar)
			{
				First=j;
				int count;
				while(j<=i&&board[N-1-i+j][N-1-j][1]==PChar)
				{
					j++;
				}
				Last=j;
				count=Last-First;
				int liveup=0,livedown=0,flaglive=0,flaghalf=0;						//判断是否有一边被堵死
				if(First-1>=0&&board[N-1-i+First-1][N-1-(First-1)][1]!=BC&&board[N-1-i+First-1][N-1-(First-1)][1]!=WC)
					liveup=1;
				if(Last<=i&&board[N-1-i+Last][N-1-Last][1]!=BC&&board[N-1-i+Last][N-1-Last][1]!=WC)
					livedown=1;
				if(liveup&&livedown)
					flaglive=1;
				if(liveup||livedown)
					flaghalf=1;
				switch(count)
				{
					case 1:
						{
							if(flaglive)
								ONE++;
							else
								if(flaghalf)
									HONE++;
							break;
						}
					case 2:
						{
							if(flaglive)
								TWO++;
							else
								if(flaghalf)
									HTWO++;
							break;
						}
					case 3:
						{
							if(flaglive)
								THREE++;
							else
								if(flaghalf)
									HTHREE++;
							break;
						}
					case 4:
						{
							if(flaglive)
								FOUR++;
							else
								if(flaghalf)
									HFOUR++;
							break;
						}
					case 5:
						{
							FIVE++;
							break;
						}
					default:;
				}
			}
			j++;
		}
	}
	LDscore=1000000*FIVE+10000*FOUR+1000*(THREE+HFOUR)+100*(TWO+HTHREE)+10*(ONE+HTWO)+HONE;
	return LDscore;
}

int Evaluation(char board[N][N][L],int side)
{
	int PChar;
	switch(side)
	{
		case BLACK:
			{
				PChar=BC;
				break;
			}
		case WHITE:
			{
				PChar=WC;
				break;
			}
		default:;
	}
	int score=Left_Right2(board,PChar)+Up_Down2(board,PChar)+Left_Up2(board,PChar)+Left_Down2(board,PChar);
	return score;
}
