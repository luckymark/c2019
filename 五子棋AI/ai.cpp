#include"ai.h"
void ai(int *m,int *n,char map[15][15][4],int a[][15])
{
	int i,j,four,live3,x,y;
	int sum1,sum2,summax=-30000;
	four=win(m,n,a,4,1);  //4连
	/*live3=live(*m,*n,a,3,1);
    if(live3)
	{
		switch(live3)
		{
			case 1:{search_1(m,n,map,a);  //找、堵放 
				break;
			}
			case 2:{search_2(m,n,map,a);
				break;
			}
			case 3:{search_3(m,n,map,a);
				break;
			}
			case 4:{search_4(m,n,map,a);
				break;
			}
			default:
				break;
		}
	}
	else */if(four)
    {
    	switch(four)
        {
			case 1:{search_1(m,n,map,a);
				break;
			}
			case 2:{search_2(m,n,map,a);
				break;
			}
			case 3:{search_3(m,n,map,a);
				break;
			}
			case 4:{search_4(m,n,map,a);
				break;
			}
			default:
				break;
        }
    }
	else
	{
		generate_2(m,n,map,a,2);
		sprintf(map[*m][*n],"●");
	} 
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
int generate_1(int *m,int *n,char map[15][15][4],int a[][15],int side)  //搜索价值极大值位置生成黑棋子（人） 
{
    int i,j,max,s1,s2;
    s1=0;
    s2=0;
	max=-10000;
	for(i=0;i<=14;i++)
	{
		for(j=0;j<=14;j++)
		{
		    if(a[i][j]!=0)
				 break;
	        else
			{
				a[i][j]=2;                     //模拟下子 
    			s2=score_1(i,j,a,2);
       			a[i][j]=1;
 				s1=score_1(i,j,a,1);
			    if((s2+s1)>max)
		    	{
 			   	    max=s2+s1;
 			   	    *m=i;
       	    		*n=j;
    			}
    			a[i][j]=0;
			}
         } 
    }
    a[*m][*n]=side;
    return max;
} 
int generate_2(int *m,int *n,char map[15][15][4],int a[][15],int side)  //搜索价值极大值位置生成白棋子（电脑） 
{
    int i,j,max,s1,s2;
    s1=0;
    s2=0;
	max=-10000;
	for(i=0;i<=14;i++)
	{
		for(j=0;j<=14;j++)
		{
		    if(a[i][j]!=0)
				 break;
	        else
			{
				a[i][j]=2;                     //模拟下子 
    			s2=score_2(i,j,a,2);
       			a[i][j]=1;
 				s1=score_2(i,j,a,1);
			    if((s2+s1)>max)
		    	{
 			   	    max=s2+s1;
 			   	    *m=i;
       	    		*n=j;
    			}
    			a[i][j]=0;
			}
         } 
    }
    a[*m][*n]=side;
    return max;
} 
int score_2(int m,int n,int a[][15],int side)  //打分side:1是黑棋人 2是白棋电脑 
{
 	if(side==2)
 	{
		if(live(m,n,a,5,2))
	        return 30000;
		else if(dead(m,n,a,5,2))
            return 30000;
        else if(live(m,n,a,4,2)) 
	        return 9000;
        else if(dead(m,n,a,4,2))  
	    	 return 3000;
	    else if(live(m,n,a,3,2))
	    	 return 1500;
		else if(dead(m,n,a,3,2))    
	    	 return 70;
		else if(live(m,n,a,2,2)) 
	    	 return 10; 
		else if(dead(m,n,a,2,2)) 
	    	 return 5;
		else if(live(m,n,a,1,2))  
	    	 return 3; 
    	else if(dead(m,n,a,1,2))
        	 return 1;
	 }
     else if(side==1)
     {
     	if(live(m,n,a,5,1))
	    	 return 20000;
    	else if(dead(m,n,a,5,1))
        	 return 20000;
    	else if(live(m,n,a,4,1)) 
	    	 return 6000;
		else if(dead(m,n,a,4,1))  
	    	 return 2000;
		else if(live(m,n,a,3,1))
	    	 return 900;
	    else if(dead(m,n,a,3,1))    
	    	 return 50;
		else if(live(m,n,a,2,1)) 
	    	 return 5; 
		else if(dead(m,n,a,2,1)) 
	    	 return 3;
		else if(live(m,n,a,1,1))  
	    	 return 2; 
    	else if(dead(m,n,a,1,1))
        	 return 1;
	 }
	return 0;     
} 
int score_1(int m,int n,int a[][15],int side)  //打分side:1是黑棋人 2是白棋电脑 
{
 	if(side==1)
 	{
		if(live(m,n,a,5,1))
	        return 30000;
		else if(dead(m,n,a,5,1))
            return 30000;
        else if(live(m,n,a,4,1)) 
	        return 9000;
        else if(dead(m,n,a,4,1))  
	    	 return 2000;
	    else if(live(m,n,a,3,1))
	    	 return 900;
		else if(dead(m,n,a,3,1))    
	    	 return 70;
		else if(live(m,n,a,2,1)) 
	    	 return 10; 
		else if(dead(m,n,a,2,1)) 
	    	 return 5;
		else if(live(m,n,a,1,1))  
	    	 return 3;
    	else if(dead(m,n,a,1,1))
        	 return 1;
	 }
     else if(side==2)
     {
     	if(live(m,n,a,5,2))
	    	 return 20000;
    	else if(dead(m,n,a,5,2))
        	 return 20000;
    	else if(live(m,n,a,4,2)) 
	    	 return 6000;
		else if(dead(m,n,a,4,2))  
	    	 return 2000;
		else if(live(m,n,a,3,2))
	    	 return 900;
	    else if(dead(m,n,a,3,2))    
	    	 return 50;
		else if(live(m,n,a,2,2)) 
	    	 return 5; 
		else if(dead(m,n,a,2,2)) 
	    	 return 3;
		else if(live(m,n,a,1,2))  
	    	 return 2; 
    	else if(dead(m,n,a,1,2))
        	 return 1;
	 }
	return 0;     
} 
int live(int m,int n,int a[][15],int count,int side)
{
	int i,j,p;
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
		    return 1;               //竖 
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
		    return 2;             //横 
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
		    return 3;             //左上到右下斜 
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
		    return 4;              //左下到右上斜 
	}
	return 0;
}
int dead(int m,int n,int a[][15],int count,int side)
{
    int i,j,p;
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
		    return 1;               //竖 
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
		    return 2;             //横 
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
		    return 3;             //左上到右下斜 
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
		    return 4;              //左下到右上斜 
	}
	return 0;
}
