#include"ai.h"
void ai(int *m,int *n,char map[15][15][4],int a[][15])
{
	int i,j;
	int sum1,sum2,summax=-100000;
	int b[15][15];
	same_to_a(a,b);
	for(i=0;i<=14;i++)
	{
		for(j=0;j<=14;j++)
		{
			if(b[i][j]!=0||cut(i,j,b))
			    ;
            else
            {
            	b[i][j]=2;
   				generate_1(b,1);  //搜索极小值位置放黑棋人 
   				sum2=sumscore_2(b,2);
   				sum1=sumscore_2(b,1);
		    	if((sum2-sum1)>summax)
	    		{
                    summax=sum2-sum1;
 	    		    *m=i;
  			 	    *n=j;
   				}                           //找到得分最大的i,j  
   				same_to_a(a,b);//回到初始棋盘状态 
			}
       }
    }
    a[*m][*n]=2;
	sprintf(map[*m][*n],"●");
}
void search_1(int *m,int *n,char map[15][15][4],int a[][15])
{
	while(a[*m][*n]==1)
	{
		*m=*m+1;
	}
    if(a[*m][*n]==0)
    {
    	sprintf(map[*m][*n],"●");
	    a[*m][*n]=2;
	}
	else if(a[*m][*n]==2)
	{
		*m=*m-1;
		while(a[*m][*n]==1)
	    {
		    *m=*m-1;
	    }
	    if(a[*m][*n]==0)
    	{
	        sprintf(map[*m][*n],"●");
		    a[*m][*n]=2;
	    }
	}
}
void search_2(int *m,int *n,char map[15][15][4],int a[][15])
{
	while(a[*m][*n]==1)
	{
		*n=*n+1;
	}
    if(a[*m][*n]==0)
    {
    	sprintf(map[*m][*n],"●");
	    a[*m][*n]=2;
	}
	else if(a[*m][*n]==2)
	{
		*n=*n-1;
		while(a[*m][*n]==1)
	    {
		    *n=*n-1;
	    }
	    if(a[*m][*n]==0)
    	{
	        sprintf(map[*m][*n],"●");
		    a[*m][*n]=2;
	    }
	}
}
void search_3(int *m,int *n,char map[15][15][4],int a[][15])
{
	while(a[*m][*n]==1)
	{
		*m=*m+1;
		*n=*n+1; 
	}
    if(a[*m][*n]==0)
    {
    	sprintf(map[*m][*n],"●");
	    a[*m][*n]=2;
	}
	else if(a[*m][*n]==2)
	{
		*m=*m-1;
		*n=*n-1;
		while(a[*m][*n]==1)
	    {
		    *m=*m-1;
		    *n=*n-1;
	    }
	    if(a[*m][*n]==0)
    	{
	        sprintf(map[*m][*n],"●");
		    a[*m][*n]=2;
	    }
	}
}
void search_4(int *m,int *n,char map[15][15][4],int a[][15])
{
	while(a[*m][*n]==1)
	{
		*m=*m-1;
		*n=*n+1;
	}
    if(a[*m][*n]==0)
    {
    	sprintf(map[*m][*n],"●");
	    a[*m][*n]=2;
	}
	else if(a[*m][*n]==2)
	{
		*m=*m+1;
		*n=*n-1;
		while(a[*m][*n]==1)
	    {
		    *m=*m+1;
		    *n=*n-1;
	    }
	    if(a[*m][*n]==0)
    	{
	        sprintf(map[*m][*n],"●");
		    a[*m][*n]=2;
	    }
	}
}
int generate_1(int b[][15],int side)  //搜索价值极大值位置生成黑棋子（人） 
{
    int i,j,min,sum1,sum2,x,y;
	min=100000;
	for(i=0;i<=14;i++)
	{
		for(j=0;j<=14;j++)
		{
		    if(b[i][j]!=0)
				 ;
	        else
			{
       			b[i][j]=1;
 				sum1=sumscore_1(b,1);
 				sum2=sumscore_1(b,2);
			    if((sum2-sum1)<min)
		    	{
 			   	    min=sum2-sum1;
 			   	    x=i;
       	    		y=j;
    			}
    			b[i][j]=0;
			}
         } 
    }
    b[x][y]=side;
    return min;
} 
int generate_2(int b[][15],int side)  //搜索价值极大值位置生成白棋子（电脑） 
{
    int i,j,max,sum1,sum2,x,y;
	max=-100000;
	for(i=0;i<=14;i++)
	{
		for(j=0;j<=14;j++)
		{
		    if(b[i][j]!=0)
				 ;
	        else
			{
				b[i][j]=2;                     //模拟下子 
    			sum2=sumscore_2(b,2);
    			sum1=sumscore_2(b,1);
			    if((sum2-sum1)>max)
		    	{
 			   	    max=sum2-sum1;
 			   	    x=i;
       	    		y=j;
    			}
    			b[i][j]=0;
			}
         } 
    }
    b[x][y]=side;
    return max;
} 
int sumscore_1(int a[][15],int side) //轮到人下 
{
	int i,j,s,s1;
	s=0;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			if(a[i][j]!=side)
			    ;
            else
            {
            	s1=score_1(i,j,a,side);
            	s=s+s1;
			}
		}
	}
	return s;
}
int sumscore_2(int a[][15],int side) //轮到电脑下 
{
	int i,j,s,s2;
	s=0;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			if(a[i][j]!=side)
			    ;
            else
            {
            	s2=score_2(i,j,a,side);
            	s=s+s2;
			}
		}
	}
	return s;
}
int score_2(int m,int n,int a[][15],int side)  //轮到电脑下时的打分side:1是黑棋人 2是白棋电脑  自己的优先下 
{
	int sum=0;
	int lo5,do5,tdo5,lo4,do4,lo3,do3,lo2,do2,lo1,do1,lt5,dt5,tdt5,lt4,dt4,lt3,dt3,lt2,dt2,lt1,dt1;
	lo5=live(m,n,a,5,1);
	do5=dead(m,n,a,5,1);
	tdo5=twodead(m,n,a,5,1);
	lo4=live(m,n,a,4,1);
	do4=dead(m,n,a,4,1);
	lo3=live(m,n,a,3,1);
	do3=dead(m,n,a,3,1);
	lo2=live(m,n,a,2,1);
	do2=dead(m,n,a,2,1);
	lo1=live(m,n,a,1,1);
	do1=dead(m,n,a,1,1);
	lt5=live(m,n,a,5,2);
	dt5=dead(m,n,a,5,2);
	tdt5=twodead(m,n,a,5,2);
	lt4=live(m,n,a,4,2);
	dt4=dead(m,n,a,4,2);
	lt3=live(m,n,a,3,2);
	dt3=dead(m,n,a,3,2);
	lt2=live(m,n,a,2,2);
	dt2=dead(m,n,a,2,2);
	lt1=live(m,n,a,1,2);
	dt1=dead(m,n,a,1,2);
	if(side==2)
	    sum=lt5*30000+dt5*30000+tdt5*30000+lt4*9000+dt4*3000+lt3*1500+dt3*70+lt2*10+dt2*5+lt1*2+dt1*1;
	if(side==1)
	    sum=lo5*20000+do5*20000+tdo5*20000+lo4*6000+do4*2000+lo3*900+do3*50+lo2*5+do2*3+lo1*3+do1*1;
	return sum;     
} 
int score_1(int m,int n,int a[][15],int side)  //人下时的打分side:1是黑棋人 2是白棋电脑 
{
	int sum=0;
	int lo5,do5,tdo5,lo4,do4,lo3,do3,lo2,do2,lo1,do1,lt5,dt5,tdt5,lt4,dt4,lt3,dt3,lt2,dt2,lt1,dt1;
	lo5=live(m,n,a,5,1);
	do5=dead(m,n,a,5,1);
	tdo5=twodead(m,n,a,5,1);
	lo4=live(m,n,a,4,1);
	do4=dead(m,n,a,4,1);
	lo3=live(m,n,a,3,1);
	do3=dead(m,n,a,3,1);
	lo2=live(m,n,a,2,1);
	do2=dead(m,n,a,2,1);
	lo1=live(m,n,a,1,1);
	do1=dead(m,n,a,1,1);
	lt5=live(m,n,a,5,2);
	dt5=dead(m,n,a,5,2);
	tdt5=twodead(m,n,a,5,2);
	lt4=live(m,n,a,4,2);
	dt4=dead(m,n,a,4,2);
	lt3=live(m,n,a,3,2);
	dt3=dead(m,n,a,3,2);
	lt2=live(m,n,a,2,2);
	dt2=dead(m,n,a,2,2);
	lt1=live(m,n,a,1,2);
	dt1=dead(m,n,a,1,2);
	if(side==1)
	    sum=lo5*30000+do5*30000+tdo5*30000+lo4*9000+do4*3000+lo3*1500+do3*70+lo2*10+do2*5+lo1*2+do1*1;
	if(side==2)
	    sum=lt5*20000+dt5*20000+tdt5*20000+lt4*6000+dt4*2000+lt3*900+dt3*50+lt2*5+dt2*3+lt1*3+dt1*1;
	return sum;     
} 
int live(int m,int n,int a[][15],int count,int side)
{
	int i,j,p,s=0;
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(m-j-1<0||a[m-j-1][n]!=0||a[m-j+count][n]!=0)
			    break;
		    if(a[m-j+i][n]==side&&m-j+i<=14)
		        p++; 
		}
		if(p==count)
		    s++;               //竖 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(n-j-1<0||a[m][n-j-1]!=0||a[m][n-j+count]!=0)
			    break;
		    if(a[m][n-j+i]==side&&n-j+i<=14)
		        p++;
		}
		if(p==count)
		    s++;             //横 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(m-j-1<0||n-j-1<0||a[m-j-1][n-j-1]!=0||a[m-j+count][n-j+count]!=0)
			    break;
		    if(a[m-j+i][n-j+i]==side&&m-j+i<=14&&n-j+i<=14)
		        p++; 
		}
		if(p==count)
		    s++;             //左上到右下斜 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
		    if(m-j-1<0||n+j+1>14||a[m-j-1][n+j+1]!=0||a[m-j+count][n+j-count]!=0)
			    break;
		    if(a[m-j+i][n+j-i]==side&&m-j+i<=14&&n+j-i>=0)
		        p++; 
		}
		if(p==count)
		    s++;              //左下到右上斜 
	}
	return s;
}
int dead(int m,int n,int a[][15],int count,int side)
{
    int i,j,p,s=0;
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(m-j-1<0||(a[m-j-1][n]==0&&a[m-j+count][n]==0)||(a[m-j-1][n]!=0&&a[m-j+count][n]!=0))
			    break;
		    if(a[m-j+i][n]==side&&m-j+i<=14)
		        p++; 
		}
		if(p==count)
		    s++;               //竖 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(n-j-1<0||(a[m][n-j-1]==0&&a[m][n-j+count]==0)||(a[m][n-j-1]!=0&&a[m][n-j+count]!=0))
			    break;
		    if(a[m][n-j+i]==side&&n-j+i<=14)
		        p++;
		}
		if(p==count)
		    s++;             //横 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(m-j-1<0||n-j-1<0||(a[m-j-1][n-j-1]==0&&a[m-j+count][n-j+count]==0)||(a[m-j-1][n-j-1]!=0&&a[m-j+count][n-j+count]!=0))
			    break;
		    if(a[m-j+i][n-j+i]==side&&m-j+i<=14&&n-j+i<=14)
		        p++; 
		}
		if(p==count)
		    s++;             //左上到右下斜 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
		    if(m-j-1<0||n+j+1>14||(a[m-j-1][n+j+1]==0&&a[m-j+count][n+j-count]==0)||(a[m-j-1][n+j+1]!=0&&a[m-j+count][n+j-count]!=0))
			    break;
		    if(a[m-j+i][n+j-i]==side&&m-j+i<=14&&n+j-i>=0)
		        p++; 
		}
		if(p==count)
		    s++;              //左下到右上斜 
	}
	return s;
}
int twodead(int m,int n,int a[][15],int count,int side) 
{
	int i,j,p,s=0;
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(m-j-1<0||a[m-j-1][n]==0||a[m-j+count][n]==0)
			    break;
		    if(a[m-j+i][n]==side&&m-j+i<=14)
		        p++; 
		}
		if(p==count)
		    s++;               //竖 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(n-j-1<0||a[m][n-j-1]==0||a[m][n-j+count]==0)
			    break;
		    if(a[m][n-j+i]==side&&n-j+i<=14)
		        p++;
		}
		if(p==count)
		    s++;             //横 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(m-j-1<0||n-j-1<0||a[m-j-1][n-j-1]==0||a[m-j+count][n-j+count]==0)
			    break;
		    if(a[m-j+i][n-j+i]==side&&m-j+i<=14&&n-j+i<=14)
		        p++; 
		}
		if(p==count)
		    s++;             //左上到右下斜 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
		    if(m-j-1<0||n+j+1>14||a[m-j-1][n+j+1]==0||a[m-j+count][n+j-count]==0)
			    break;
		    if(a[m-j+i][n+j-i]==side&&m-j+i<=14&&n+j-i>=0)
		        p++; 
		}
		if(p==count)
		    s++;              //左下到右上斜 
	}
	return s;
}
int cut(int x,int y,int b[][15])
{
	int s=0,i,j;
	for(i=-2;i<=2;i++)
	{
		for(j=-2;j<=2;j++)
		{
		    if(b[x+i][y+j]==0)
		        s++;
		}
	}
	if(s==25)
 		return 1;
	else
	    return 0;
}
void same_to_a(int a[][15],int b[][15])
{
	int i,j;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			b[i][j]=a[i][j];
		}
	} 
}
