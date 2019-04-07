#include"head.h"
void scan()
{
	int k=1;
	freopen("map.txt","r",stdin);
	for(int i=1;i<=MAPLE_X;i++)
	{
		for(int j=1;j<=MAPLE_Y;j++)
		{
			cin>>map[i][j].zt;
			if(map[i][j].zt==2)
			{
				players.x=i;
				players.y=j;
				map[i][j].zt=0;
			}
			else if(map[i][j].zt==4)
			{
				box[k].x=i;
				box[k].y=j;
				map[i][j].zt=0;
				k++;
			}
		}
	}
	fclose(stdin);
}
void print()
{
	int box_j=0;
	system("cls");
	for(int i=1;i<=MAPLE_X;i++)
	{
		for(int j=1;j<=MAPLE_Y;j++)
		{
			box_j=0;
			if(players.x==i&&players.y==j)
			{
				cout<<"Äã";
				continue;
			}
			for(int k=1;k<=NUM;k++)
			{
				if(box[k].x==i&&box[k].y==j)
				{
					cout<<"Ïä";
					box_j=1;
					break;
				}
			}
			if(box_j==1)continue;
			else if(map[i][j].zt==0)cout<<"  ";
			else if(map[i][j].zt==1)cout<<"Ç½";
			else if(map[i][j].zt==3)cout<<"µã";
		}
		cout<<endl;
	}
}
int judge(char temp)
{
	object temp_re;
	int enter_point=0;
	int t=0;
	for(int i=1;i<=NUM;i++)
	{
		if(map[box[i].x][box[i].y].zt==3)
		enter_point++;
	}
	if(enter_point==NUM)return 3;
	re=change(temp,players);
	temp_re=change(temp,re);
	for(int i=1;i<=NUM;i++)
	{
		if(re.x==box[i].x&&re.y==box[i].y)
		{
			for(int j=1;j<=NUM;j++)
			{
				if(temp_re.x==box[j].x&&temp_re.y==box[j].y)return 0;
			}
			t++;
		}
	}
	if(t==0)
	{
		if(map[re.x][re.y].zt==1)return 0;
		else if(map[re.x][re.y].zt==0||map[re.x][re.y].zt==3)return 1;
	}
	else if(t==1)
	{
		if(map[re.x][re.y].zt==0||map[re.x][re.y].zt==3)return 2;
	}
}
object change(char temp,object before)
{
	object change_temp=before;
	if(temp=='w'||temp=='W')change_temp.x--;
	else if(temp=='s'||temp=='S')change_temp.x++;
	else if(temp=='a'||temp=='A')change_temp.y--;
	else if(temp=='d'||temp=='D')change_temp.y++;
	return change_temp;
}
int grab(object temp)
{
	for(int i=1;i<=NUM;i++)
	{
		if(box[i].x==temp.x&&box[i].y==temp.y)return i;
	}
	return 0;
}
void push_move(char temp)
{
	int being_pushed=grab(re);
	box[being_pushed]=change(temp,box[being_pushed]);
	players=change(temp,players);
}
