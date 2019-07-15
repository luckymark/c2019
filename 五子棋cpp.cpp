#include<stdio.h>
#include<string.h>
#include<windows.h>//API函数头文件
#include<conio.h>//控制台输 入输出头文件

/*界面颜色宏定义*/
#define WhiteColor 63
#define BlackColor 48
#define Menu  2
#define ChessBackground 125
#define ChessBoardColor 48
#define TipColor 6//绿色

HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);//得到一个标准的输出句柄 

char Chess[15][15][3];//棋型字符数组

int type=0;//记录人人对战or人机对战，type为0人人对战，type为1人机对战，默认为人人对战

int flag=-1;//记录黑白棋哪方先落子，flag为0白子（电脑）先，flag为1黑子（玩家）先

int count=0;//记录下棋步数，一共可下225步

int status[15][15]={0};//标识当前位置状态，status[i][j]为0表明此位置为空，status[i][j]为1表明为白棋（电脑），status[i][j]为2表明当前位置为黑棋（玩家）

int Winner=0;//标识赢家，Winner=1表明白棋（电脑）胜，Winner=2表明黑棋（玩家）胜

int x=40, y=1;//表示当前鼠标的位置

int prex=0, prey=0;//记录当前棋手下棋位置，用于悔棋函数

int prex1=0, prey1=0;//记录棋手上一步下棋的位置，用于电脑悔棋参数

int Value1[15][15]={0};//攻击权值，用于电脑优先位置判断

int Value2[15][15]={0};//防守权值，用于电脑优先位置判断

void GameStart();//下棋函数

void TextColor(int color)//设置颜色函数
{
	SetConsoleTextAttribute(hOutput,color);//设置控制台文本属性
}

void ChessBord()//绘制棋盘形状
{
	int i, j;
	strcpy(Chess[0][0],"┌");//设置棋盘四角
	strcpy(Chess[14][0],"└");
	strcpy(Chess[0][14],"┐");
	strcpy(Chess[14][14],"┘");
	for(i=1;i<14;i++)
	{
		strcpy(Chess[i][0],"├");
    	strcpy(Chess[i][14],"┤");
	}
	for(j=1;j<14;j++)
	{
		strcpy(Chess[0][j],"┬");
		strcpy(Chess[14][j],"┴");
    }
	for(i=1;i<14;i++)
		for(j=1;j<14;j++)
			strcpy(Chess[i][j],"┼");
}

void ShowChessBoard()//输出棋盘形状
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			TextColor(ChessBoardColor);//棋盘颜色
			printf("%s",Chess[i][j]);
			//printf(" "); // win10环境需要添加该语句，否则界面显示有问题
		}
		printf("\n");
	}
}

void getto(int x,int y)//光标函数
{
	COORD cursor={0,0};//定义一个光标对象
	cursor.X=x;
	cursor.Y=y;
	SetConsoleCursorPosition(hOutput,cursor);//设置光标位置
}

void ChooseFirst() //先手函数，确定人人/机模式以及先后手
{
	switch(y)
	 {
		 case 3:
			 {
				  TextColor(TipColor);//设置提示的颜色
				  x=50,y=3;getto(x,y);
				  printf("1.白子先手");
				  getto(x,y+2);
				  printf("2.黑子先手");
				  getto(x,y);
				  while(1)
				  {
					  switch(getch())//从控制台无回显地取一个字符
					  {
					  case '1':
						  flag=0;break;
					  case '2':
						  flag=1;break;
					  case 72:if(y<=3)y=3;else y-=2;getto(x,y);break;//上
					  case 80:if(y>=5)y=5;else y+=2;getto(x,y);break;//下
					  case 13:if(y==3) flag=0;else flag=1; break;//flag=0 白子先手 flag=1 黑子先手
					  case 'e':case 'E':case 27:
						  {
						  int message=MessageBox(NULL,"是否退出？","友情提示",MB_OKCANCEL);
						  if(IDCANCEL==message)
							  continue;
						  if(IDOK==message)
						  {
							  getto(36,15);
							  exit(0);
						  }
						  }break;//提前终止比赛
					  default:break;
					  }
					  if(flag!=-1)
						  break;//选择好先后手，跳出循环
				  }
			 }break;
			 case 5:
			 {
				  type=1; //人机对战模式
				  TextColor(TipColor);//设置提示的颜色
				  x=50,y=3;getto(x,y);
				  printf("1.电脑先手");
				  getto(x,y+2);
				  printf("2.玩家先手");
				  getto(x,y);
				  while(1)
				  {
					  switch(getch())
					  {
					  case '1':
						  flag=0;break;
					  case '2':
						  flag=1;break;
					  case 72:if(y<=3)y=3;else y-=2;getto(x,y);break;
					  case 80:if(y>=5)y=5;else y+=2;getto(x,y);break;
					  case 13:if(y==3) flag=0;else flag=1;break; //flag=0 电脑先手 flag=1 玩家先手
					  case 'e':case 'E':
						 {
							 int message=MessageBox(NULL,"是否退出？","友情提示",MB_OKCANCEL);
							 if(IDCANCEL==message)
								 continue;
							 if(IDOK==message)
							 {
								 getto(36,15);
								 exit(0);
							 }
						 }break;//提前终止比赛
					  default:break;
					  }
					  if(flag!=-1)
						  break;//选择好先后手，跳出循环
				  }
			 }break;
			 default:
				 break;
	 }
}

void ShowMenu()//输出菜单选项，用户可视化界面
{
	getto(40,1);
	TextColor(Menu);
	printf("欢迎使用五子棋");
	getto(36,3);
	printf("1.人人对战");
	getto(36,5);
	printf("2.人机对战");
	getto(36,7);
	printf("B悔棋(按快捷键B即可实行悔棋)");
	getto(36,9);
	printf("E退出(按快捷键E即可实行退出)");
	getto(36,11);
	printf("R重新开始(按快捷键R即可实行重新开始)");
	getto(0,16);
	printf("                                 操作说明：\n\n");
	printf("1.用户应先选择游戏模式，可以按快捷键'1'、'2'进行选择，也可通过移动光标实现\n\n2.确定下棋位置可按↑、↓、←、→一步步移动光标,也可按'W'（快速到列首）、'S'（快速到列尾）、'A'（快速到行首）、'D'（快速到行尾）\n\n3.按enter确定落子，同时本游戏提供相应快捷键操作（详见棋盘右侧）");
	x=36,y=3;
	getto(x,y);
	while(1)
	{
		if(flag!=-1)
			break;
		switch(getch())//从控制台无回显地取一个字符
		{
		case '1':
			{
				ChooseFirst(); //调用先手函数							
			}break;
		case '2':
			{
				y=5;
				ChooseFirst(); //调用先手函数	
			}break;
		 case 72:
			 {
				 if(y<=3)y=3;else y-=2;//控制光标不上超第三行
				 getto(x,y);
			 }break;
		 case 80:
			 {	 if(y>=5)y=5;else y+=2;//控制光标不下超第五行
			     getto(x,y);
			 }break;
		case 13:
			{
				ChooseFirst(); //调用先手函数							
			}break;
		case 'e':case 'E':case 27://提前终止比赛
			{
				  int message=MessageBox(NULL,"是否退出？","友情提示",MB_OKCANCEL);
				  if(IDCANCEL==message)
					  continue;
				  if(IDOK==message)
				  {getto(36,15);exit(0);}
			}break;//提前终止比赛
		default:
			break;
		}
	
	}//while结束，得到用户的选择结果，即何方先下
}

void showplayer()//显示哪方执子
{

	TextColor(TipColor);
	if(type==0)//人人模式
	{
		if(count%2==flag)
			printf("白子执手");
		else
			printf("黑子执手");
	}
	else      //人机模式
	{
		if(count%2==flag)
			printf("电脑执手");
		else
			printf("玩家执手");
	}
}

void WhiteChess(int x,int y)//输出白棋子
{
	getto(x,y);
	TextColor(WhiteColor);
    printf("●");
	prex1=prex;
	prey1=prey;
	prex=x;   //保存前一次下棋位置，方便悔棋
	prey=y;
}

void BlackChess(int x,int y)//输出黑棋子
{
	getto(x,y);
    TextColor(BlackColor);
    printf("●");
	prex1=prex;
    prey1=prey;
	prex=x;   //保存前一次下棋位置，方便悔棋
	prey=y;
} 

int ResultCheck(int x,int y,int player) //判断是否有人胜利，若有人获胜则返回player,反之返回0    
{
	int n1, n2;
	int i, j;
	n1=n2=0;
	for(i=x,j=y;j>=0;j--)//往左数
	{
		if(status[i][j]==player)
			n1++;
		else
			break;
	}
	for(i=x,j=y+1;j<15;j++)//往右数
	{
		if(status[i][j]==player)
			n2++;
		else
			break;
	}
	if(n1+n2>=5)    //若连成五子，游戏结束
		return player;
	n1=n2=0;
	for(i=x,j=y;i>=0;i--)//往上数
	{
		if(status[i][j]==player)
			n1++;
		else
			break;
	}
	for(i=x+1,j=y;i<15;i++)//往下数
	{
		if(status[i][j]==player)
			n2++;
		else
			break;
	}
	if(n1+n2>=5)  //若连成五子，游戏结束
		return player;
	n1=n2=0;
	for(i=x,j=y;i>=0&&j>=0;i--,j--)//往左上数
	{
		if(status[i][j]==player)
			n1++;
		else
			break;
	}
	for(i=x+1,j=y+1;i<15&&j<15;i++,j++)//往右下数
	{
		if(status[i][j]==player)
			n2++;
		else
			break;
	}
	if(n1+n2>=5)  //若连成五子，游戏结束
		return player;
	n1=n2=0;
	for(i=x,j=y;i<15&&j>=0;i++,j--)//往左下数
	{
		if(status[i][j]==player)
			n1++;
		else
			break;
	}
	for(i=x-1,j=y+1;i>=0&&j<15;i--,j++)//往右上数
	{
		if(status[i][j]==player)
			n2++;
		else
			break;
	}
	if(n1+n2>=5)   //若连成五子，游戏结束
		return player;
	return 0; //未有五子连成
}

void Back()//悔棋函数
{
	if(status[prey][prex/2])//避免用户多次悔棋
	{
		status[prey][prex/2]=0;//将该位置状态标为0
		getto(prex,prey);
		TextColor(ChessBoardColor);//将该位置的棋子覆盖掉
		printf("%s",Chess[prey][prex/2]);//重新绘制该位置的表格
	    count--;//下棋步数自减
		getto(prex,prey);
	}
}
 
void Back1()//悔棋函数2，当进行人机对战时调用
{
	if(status[prey1][prex1/2])//避免用户多次悔 棋
	{
		status[prey1][prex1/2]=0;//将该位置状态标为0
		getto(prex1,prey1);
		TextColor(ChessBoardColor);//将该位置的棋子覆盖掉
		printf("%s",Chess[prey1][prex1/2]);//重新绘制该位置的表格
	    count--;//下棋步数自减
		getto(prex1,prey1);
	}
}

void ShowResult()//输出下棋结果
{
	getto(36,15);
	if(count>=225)
		printf("平局！");
	if(type==0)  //人人对战模式
	{
		if(Winner==1)
			MessageBox(NULL,"白子君棒棒哒~~战胜了黑子君~O(∩_∩)O~~","五子棋游戏",MB_OK);
		if(Winner==2)
			MessageBox(NULL,"黑子君棒棒哒~~战胜了白子君~~O(∩_∩)O~~","五子棋游戏",MB_OK);
	}
	else      //人机对战模式
	{
		if(Winner==1)
			MessageBox(NULL,"亲，你竟然输给了电脑，回家洗洗睡吧！%>_<%","五子棋游戏",MB_OK);
		if(Winner==2)
			MessageBox(NULL,"亲，你太厉害了，你竟然可以战胜电脑！\^◇^/","五子棋游戏",MB_OK);
	}
}

void save()//保存残局
{
	int i,j;
	char str[4];
	FILE *fp=fopen("data.txt","w");//打开文件，把status[i][j]、type、flag、count写入data.txt文件
	if(fp==NULL)
	{
		printf("保存残局失败");
	}
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			fputc(status[i][j]+'0',fp);
	fputc(type+'0',fp);
	fputc(flag+'0',fp);
	itoa(count,str,10);//将整数转换成字符串，并给出进制数
	fputs(str,fp);
	fclose(fp);
}

void Continue()
{
	int i, j;
	char str[4];
	FILE *fp=fopen("data.txt","r");//打开文件读出相应数据
	if(fp==NULL)
	{
		printf("恢复残局失败......");
	}
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			status[i][j]=fgetc(fp)-'0';
    type=fgetc(fp)-'0';
	flag=fgetc(fp)-'0';
	char ch=fgetc(fp);
	i=0;
	while(ch!=EOF)
    {
		str[i++]=ch;
		ch=fgetc(fp);
	}
	str[i]='\0';
	fclose(fp);
	count=atoi(str);//将字符串转换成整数
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
		{
			if(status[i][j]==1)
				WhiteChess(2*j,i);
			if(status[i][j]==2)
				BlackChess(2*j,i);
		}	
}

void ValueJudgeAttack() //进攻权值函数，确定当前位置的优先级
{
	int i1, j1;
	int k1,k2,k;
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(status[i][j])
				Value1[i][j]=0;
			if(status[i][j]==0)
			{
				k1=k2=0;
				for(i1=i,j1=j-1;j1>=0;j1--)//往左数寻找电脑棋子数
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i,j1=j+1;j1<15;j1++)//往右数寻找电脑棋子数
				{
					if(status[i1][j1]==1)
						k2++;
					else
						break;
				}
				k=k1>k2? k1:k2;
				k1=k2=0;
				for(i1=i-1,j1=j;i1>=0;i1--)//往上数寻找电脑棋子数
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i+1,j1=y;i1<15;i1++)//往下数寻找电脑棋子数
				{
					if(status[i1][j1]==1)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1? k:k1;
				k1=k2=0;
				for(i1=i-1,j1=j-1;i1>=0&&j1>=0;i1--,j1--)//往左上数寻找电脑棋子数
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i+1,j1=j+1;i1<15&&j1<15;i1++,j1++)//往右下数寻找电脑棋子数
				{
					if(status[i1][j1]==1 )
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				k1=k2=0;
				for(i1=i+1,j1=j-1;i1<15&&j1>=0;i1++,j1--)//往左下数寻找电脑棋子数
				{
					if(status[i1][j1]== 1)
						k1++;
					else
						break;
				}
				for(i1=i-1,j1=j+1;i1>0&&j1<15;i1--,j1++)//往右上数寻找电脑棋子数
				{
					if(status[i1][j1]==1)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				switch(k)                                        //k=0,Value[i][j]=3
				{                                                //k=1,Value[i][j]=5
				case 3:                                          //k=2, Value[i][j]=7
					Value1[i][j]=15;break;                       //k=3,Value[i][j]=15
				case 4:
					Value1[i][j]=25;break;                       //k=4,Value[i][j]=25
				default:
					Value1[i][j]=3+2*k;break;
				}
			}//end of if
		}//end of  second for
	}//end of  first for
}//end of the function

void ValueJudgeDefend()//防御权值函数，确定当前位置的优先级
{
	int i1, j1;
	int k1,k2,k;
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(status[i][j])
				Value2[i][j]=0;
			if(status[i][j]==0)
			{
				k1=k2=0;
				for(i1=i,j1=j-1;j1>=0;j1--)//往左数寻找玩家棋子数
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i,j1=j+1;j1<15;j1++)//往右数寻找玩家棋子数
				{
					if(status[i1][j1]==2)
						k2++;
					else
						break;
				}
				k=k1>k2? k1:k2;
				k1=k2=0;
				for(i1=i-1,j1=j;i1>=0;i1--)//往上数寻找玩家棋子数
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i+1,j1=j;i1<15;i1++)//往下数寻找玩家棋子数
				{
					if(status[i1][j1]==2)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				k1=k2=0;
				for(i1=i-1,j1=j-1;i1>=0&&j1>=0;i1--,j1--)//往左上数寻找玩家棋子数
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i+1,j1=j+1;i1<15&&j1<15;i1++,j1++)//往右下数寻找玩家棋子数
				{
					if(status[i1][j1]==2)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				k1=k2=0;
				for(i1=i+1,j1=j-1;i1<15&&j1>=0;i1++,j1--)//往左下数寻找玩家棋子数
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i-1,j1=j+1;i1>0&&j1<15;i1--,j1++)//往右上数寻找玩家棋子数
				{
					if(status[i1][j1]==2)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
			    switch(k)                                      //k=0,Value2[i][j]=2
				{                                              //k=1,Value2[i][j]=4
				case 3:                                        //k=2,Value2i][j]=6
					Value2[i][j]=10;break;                     //k=3,Value2[i][j]=10
				case 4:                                        //k=4,Value2[i][j]=20
					Value2[i][j]=20;break;
				default:
					Value2[i][j]=2+k*2;
				}
			}
		}
	}
}

void FindPosition()//找到最有价值的位置
{
	int k1=0, k2=0;
	int i, j, max=0;
	for( i=0;i<15;i++)
		for( j=0;j<15;j++)
		{
			if(max<=Value1[i][j])
			{
				max=Value1[i][j];
				k1=i;
				k2=j;
			}
		}
	for( i=0;i<15;i++)
		for(j=0;j<15;j++)
		{
			if(max<=Value2[i][j])
			{
				max=Value2[i][j];
				k1=i;
				k2=j;
			}
		}
	x=2*k2;  //将找到的位置传给光标
	y=k1;
}

void MantoMan()  //人人模式
{
	while(1)//当有人获胜，跳出循环，结束游戏
		{
			getto(36,13);   //输出当前下棋方
			showplayer();
			getto(x,y);   //光标跳到棋盘中央
			switch(getch())
			{
			case 72:         //光标上移
				{
					if(y>0)
					y-=1;
					getto(x,y);
				}break;
			case 80:       //光标下移
				{
					if(y<14)
					y+=1;
					getto(x,y);
				}break;
			case 75:      //光标左移
				{
					if(x>=2)
					x-=2;
					getto(x,y);
				}break;
			case 77:     //光标右移
				{
					if(x<28)
					x+=2;
					getto(x,y);
				}break;
			case 'A':case 'a':  //光标移到行首
				{
					x=0;
					getto(x,y);
				}break;
			case 'D':case 'd':  //光标移到行尾
				{
					x=28;
					getto(x,y);
				}break;
			case 'W':case 'w':  //光标移到列首
				{
					y=0;
					getto(x,y);
				}break;
			case 'S':case 's':  //光标移到列尾
				{
					y=14;
					getto(x,y);
				}break;
			case 'b':case 'B':  //悔棋
				{
					int message=MessageBox(NULL,"是否确定悔棋？","友情提示",MB_OKCANCEL);
		        	if(IDCANCEL==message)
					     break;
			        if(IDOK==message)
					   Back();//调用悔棋函数
				}break;  
			case 13:    //enter键，在当前光标位置落棋
				{
					if(count%2==flag)     //flag为0时，白棋先下；flag为1时，黑棋先下
					{				
						if(status[y][x/2]==0)
						{
							WhiteChess(x,y);
							getto(x,y);
							status[y][x/2]=1;//改变该位置的状态值为1
							count++;
							Winner=ResultCheck(y,x/2,1);
						}
					}
					else
					{
						if(status[y][x/2]==0)
						{
							BlackChess(x,y);
							getto(x,y);
							status[y][x/2]=2;//改变该位置的状态值为2
							count++;
							Winner=ResultCheck(y,x/2,2);
						}
					}			    
				}break;
			case 'r':case 'R':   //所有状态变量重新“初始化”
				{
					int message=MessageBox(NULL,"是否重新开始？","友情提示",MB_OKCANCEL);
			        if(IDCANCEL==message)
					     break;
			        if(IDOK==message)
					{
					for(int i=0;i<15;i++)//棋盘状态全为空
						for(int j=0;j<15;j++)
							status[i][j]=0;
					flag=-1;
					type=0;
					count=0;
					Winner=0;
					getto(0,0);
					system("cls");
					ChessBord();
					ShowChessBoard();
					ShowMenu();
					getto(36,3);//光标移至菜单选项
					GameStart();
					}
				}break;
			case 'e':case 'E':case 27://提前终止比赛
				{
					int message=MessageBox(NULL,"是否保存？","友情提示",MB_YESNOCANCEL);
					if(IDYES==message)
					{
						save();
						MessageBox(NULL,"恭喜你，已成功保存！","友情提示",MB_OK);
						getto(36,15);
					    exit(0);
					}
					if(IDCANCEL==message)
						MessageBox(NULL,"继续游戏","友情提示",MB_OK);	
					if(IDNO==message)
					{
						MessageBox(NULL,"没有保存，成功退出","友情提示",MB_OK);									
					    getto(36,15);
					    exit(0);
					}
				};break;
			default:
				break;
				
			}
		if(count>=225)
				break;
		if(Winner)
			break;
		}//while结束，下棋结果已出来
	}

void MantoComputer1()//人机模式，电脑先下
{
	    x=14,y=7;
	    WhiteChess(x,y);   //电脑先下，且第一子落在棋盘中央
		getto(x,y);
		status[y][x/2]=1;
		count++;
		while(1)
		{
			getto(36,13);
			showplayer();
			getto(x,y);
			switch(getch())
			{
			case 72:         //↑光标上移
				{
					if(y>0)
					y-=1;
					getto(x,y);
				}break;
			case 80:            //↓光标下移
				{
					if(y<14)
					y+=1;
					getto(x,y);
				}break;
			case 75:              //光标左移
				{
					if(x>=2)
					x-=2;
					getto(x,y);
				}break;
			case 77:    //光标右移
				{
					if(x<28)
					x+=2;
					getto(x,y);
				}break;
			case 'A':case 'a':  //光标移到行首
				{
					x=0;
					getto(x,y);
				}break;
			case 'D':case 'd':  //光标移到行尾
				{
					x=28;
					getto(x,y);
				}break;
			case 'W':case 'w':  //光标移到列首
				{
					y=0;
					getto(x,y);
				}break;
			case 'S':case 's':  //光标移到列尾
				{
					y=14;
					getto(x,y);
				}break;
			case 'b':case 'B':  //悔棋
				{
					if(count<=1)
						continue;
					int message=MessageBox(NULL,"是否确定悔棋？","友情提示",MB_OKCANCEL);
		        	if(IDCANCEL==message)
					     break;
			        if(IDOK==message)
					{
						Back();   //调用悔棋函数
					    Back1();   //调用悔棋函数
					}
				}break;  
			case 13:   //enter键，在当前光标位置落棋
				{
					if(count%2!=flag)  //flag为0玩家后下，且下完后电脑接着下
					{				
						if(status[y][x/2]==0)
						{
							BlackChess(x,y);
							getto(x,y);
							status[y][x/2]=2;//改变该位置的状态值为2
							count++;
							Winner=ResultCheck(y,x/2,2);
							if(Winner==2)
								break;
							ValueJudgeAttack();
							ValueJudgeDefend();
							FindPosition();
							if(status[y][x/2]==0)
							{
							WhiteChess(x,y);
							getto(x,y);
							status[y][x/2]=1;//改变该位置的状态值为1
							count++;
							Winner=ResultCheck(y,x/2,1);
							}
						}
					}				    
				}break;
			case 'r':case 'R':   //所有状态变量重新“初始化”
				{
					int message=MessageBox(NULL,"是否重新开始？","友情提示",MB_OKCANCEL);
					if(IDCANCEL==message)
						break;
					if(IDOK==message)
					{
					for(int i=0;i<15;i++)//棋盘状态全为空
						for(int j=0;j<15;j++)
							status[i][j]=0;
					flag=-1;
					type=0;
					count=0;
					Winner=0;
					getto(0,0);
					system("cls");
					ChessBord();
					ShowChessBoard();
					ShowMenu();
					getto(36,3);//光标移至棋盘中央
					GameStart();
					}
				}break;
			case 'e':case 'E':case 27://提前终止比赛
				{
					int message=MessageBox(NULL,"是否保存？","友情提示",MB_YESNOCANCEL);
					if(IDYES==message)
					{
						save();
						MessageBox(NULL,"恭喜你，已成功保存！","友情提示",MB_OK);
						getto(36,15);
					    exit(0);
					}
					if(IDCANCEL==message)
						MessageBox(NULL,"继续游戏","友情提示",MB_OK);	
					if(IDNO==message)
					{
						MessageBox(NULL,"没有保存，成功退出","友情提示",MB_OK);									
					    getto(36,15);
					    exit(0);
					}
				}break;
			default:
				break;
				
			}
		if(count>=225)
				break;
		if(Winner)
			break;
		}//while结束，下棋结果已出来
	}

void MantoComputer2()//人机模式，玩家先下
{
	x=14,y=7;
	while(1)
	{
	getto(36,13);
	showplayer();
	getto(x,y);
	switch(getch())
	{  
	case 72:      //光标上移
		{
			if(y>0)
			y-=1;
			getto(x,y);
		}break;
	case 80:    //光标下移
		{
			if(y<14)
			y+=1;
			getto(x,y);
		}break;
	case 75:   //光标左移
		{
			if(x>=2)
			x-=2;
			getto(x,y);
		}break;
	case 77:   //光标右移
		{ 
			if(x<28)
			x+=2;
			getto(x,y);
		}break;
	case 'A':case 'a':  //光标移到行首
		{
			x=0;
			getto(x,y);
		}break;
	case 'D':case 'd':  //光标移到行尾
		{
			x=28;
			getto(x,y);
		}break;
	case 'W':case 'w':  //光标移到列首
		{
			y=0;
			getto(x,y);
		}break;
	case 'S':case 's':  //光标移到列尾
		{
			y=14;
			getto(x,y);
		}break;
	case 'b':case 'B': //悔棋
		{
			int message=MessageBox(NULL,"是否确定悔棋？","友情提示",MB_OKCANCEL);
		        if(IDCANCEL==message)
					 break;
			    if(IDOK==message)
				{
					Back();   //调用悔棋函数
					Back1();   //调用悔棋函数
				}
		}break;  
	case 13:   //enter键，在当前光标位置落棋
		{
			if(count%2!=flag)    //flag为1玩家先下，且下完后电脑再下
			{				
				if(status[y][x/2]==0)
				{
					BlackChess(x,y);
					getto(x,y);
					status[y][x/2]=2;//改变该位置的状态值为2
					count++;
					Winner=ResultCheck(y,x/2,2);
					if(Winner==2)
						break;
					ValueJudgeAttack();
					ValueJudgeDefend();
					FindPosition();
					if(status[y][x/2]==0)
					{
					WhiteChess(x,y);
					getto(x,y);
					status[y][x/2]=1;//改变该位置的状态值为1
					count++;
					Winner=ResultCheck(y,x/2,1);
					}
				}
			}				    
		}break;
	case 'r':case 'R':  //所有状态变量重新“初始化”
		{
			int message=MessageBox(NULL,"是否重新开始？","友情提示！",MB_OKCANCEL);
			if(IDCANCEL==message)
					break;
			if(IDOK==message)
			{
			for(int i=0;i<15;i++)//棋盘状态全为空
				for(int j=0;j<15;j++)
					status[i][j]=0;
			flag=-1;
			type=0;
			count=0;
			Winner=0;
			getto(0,0);
			system("cls");
			ChessBord();
			ShowChessBoard();
			ShowMenu();
			getto(36,3);//光标移至棋盘中央
			GameStart();
			}
		}break;
	case 'e':case 'E':case 27://提前终止比赛
		{
			int message=MessageBox(NULL,"是否保存？","友情提示",MB_YESNOCANCEL);
			if(IDYES==message)
			{
				save();
				MessageBox(NULL,"恭喜你，已成功保存！","友情提示",MB_OK);
				getto(36,15);
				exit(0);
			}
			if(IDCANCEL==message)
				MessageBox(NULL,"继续游戏","友情提示",MB_OK);	
			if(IDNO==message)
			{
				MessageBox(NULL,"没有保存，成功退出","友情提示",MB_OK);									
				getto(36,15);
				exit(0);
			}
		};break;
	default:
		break;
		
	}
	if(count>=225)
		break;
	if(Winner)
	break;
	}//while结束，下棋结果已出来
}

void GameStart()//下棋函数
{
	x=14,y=7;
	getto(x,y);
	if(type==0)
	    MantoMan();	//人人模式	
	else
	{
		if(flag==0)
	        MantoComputer1();//电脑先手
		if(flag==1)
		    MantoComputer2();//玩家先手
	}
	ShowResult();  //显示游戏结果
}

int main()
{
	FILE *fp=fopen("data.txt","r");//定义一个文件指针指向数据保存文件
	ChessBord();//绘制棋盘
	system("cls");//实现清屏
	ShowChessBoard();//输出棋盘
	char ch=fgetc(fp);
	fclose(fp);
	if(ch!=EOF) //判断文件是否为空，若非空则表明data.txt文件里有数据
	{
		int message=MessageBox(NULL,"检测到您上次五子棋还没有下完，是否继续？","友情提示",MB_OKCANCEL);
		if(IDCANCEL==message)
		{
			fp=fopen("data.txt","w");//若用户取消恢复残局，则对原数据文件进行改写覆盖，避免多次提醒用户恢复残局
	        fclose(fp);
		}
		if(IDOK==message)
		{
			Continue();//调用恢复残局函数
			ShowMenu();//输出菜单
			x=14,y=7;
			getto(14,7);
			if(type==0)   //根据对原数据的判断，恢复游戏现场，即游戏模式、先后手问题
			{
				MantoMan();
				ShowResult();  //显示游戏结果
			}
			if(type==1&&(count%2==flag))
			{
				MantoComputer1();
				ShowResult();  //显示游戏结果
			}
			if(type==1&&(count%2!=flag))
			{
				MantoComputer2();
				ShowResult();  //显示游戏结果
			}
			fp=fopen("data.txt","w");//恢复残局后应及时对对原数据文件进行改写覆盖，避免多次提醒用户恢复残局
	        fclose(fp);
		}
	}
	if(!Winner)
	{
	ShowMenu();//输出菜单
	getto(36,3);
    GameStart();//开始游戏*/
	}
	return 0;	
}
