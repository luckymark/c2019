#include"head.h"
void cls()
{
	system("cls");
}
int getdata(good *a)
{
	int i=0,num;
	char type[TYPEN];
	FILE *data=fopen("data.in","r");
	while(fscanf(data,"%s %d",&type,&num)==2)
	{
		a[i].type[0]='\0';
		strcat(a[i].type,type);
		a[i].num=num;
		++i;
	}
	fclose(data);
	return i;
}
int getchoice()
{
	int i;
	cls();
	printf("Please input instruction:\n");
	printf("  1 Display goods\n");
	printf("  2 In house\n");
	printf("  3 Out house\n");
	printf("  0 Exit program\n");
	scanf("%d",&i);
	return i;
}
void disphouse(good *a,int n)
{
	int i;
	cls();
	printf("No. type number\n");
	for(i=0;i<n;++i)
	{
		printf("%2d  %4s %4d\n",i+1,a[i].type,a[i].num);
	}
}
void inhouse(good *a,int *p)
{
	printf("Please input type and number:");
	scanf("%s %d",a[*p].type,&a[*p].num);
	++*p;
}
void outhouse(good *a,int *p)
{
	int i;
	disphouse(a,*p);
	printf("Please input the good(No.) that you want to delete:");
	scanf("%d",&i);
	while(i<*p)
	{
		a[i-1].type[0]='\0';
		strcat(a[i-1].type,a[i].type);
		a[i-1].num=a[i].num;
		++i;
	}
	--*p;
}
void savedata(good *a,int n)
{
	int i;
	FILE *data=fopen("data.in","w");
	for(i=0;i<n;++i)
	{
		fprintf(data,"%s %d\n",a[i].type,a[i].num);
	}
	fclose(data);
}
