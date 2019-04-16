#include"warehouse.h"
struct goods 
{
	char a[5];
	int num;
}g[N];
FILE *fp;
int main()
{
	int i;
	fp=fopen("data.txt","r+");
	if(fp==NULL)
	  printf("Cann't open file!\n");
	else
	{
		printf("Please input the types and numbers:\n");
		for(i=0;i<N;i++)
	    {
		    fscanf(fp,"%s%d",g[i].a,&g[i].num);
	    }
	}
	int n;               //ÐòºÅ
	int t;               //ÊýÁ¿ 
	printf("Display:1\nIn:2\nOut:3\nQuit:4\n");
	fclose(fp);
	scanf("%d",&n);
	while(n!=4)
	{
		switch(n)
		{
		    case 1:{display();
			    break;
		    }
		    case 2:{in();
		    	break;
		    }
		    case 3:{out();
		    	break;
		    }
		    case 4:{quit();
		    	break;
		    }
		    default:
			    break;
	    }
	    scanf("%d",&n);
	}
	changefile();
	return 0;
}
void changefile()
{
	int i;
	fp=fopen("data.txt","w");
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%s %d\n",g[i].a,g[i].num);
	}
	fclose(fp);
}
