#include<stdio.h>
struct student
{
	char name[10];
	char num[14];
	unsigned int age;
};
struct course
{
	char name[10];
	char teacher[10];
	int num;
	struct student costudent[100];
};
struct sclass
{
	char headteacher[10];
	struct student clsstudent[30];
};
struct college
{
	struct course allcourse[20];
	struct sclass allclass[15];
};
struct school
{
	//struct student stu[10000];
	struct college allcollege[20];
};
int main()
{
	int i,j;
	struct student stu[30];
	for(i=0;i<30;++i)
	{
		stu[i].name[0]='a';
		stu[i].num[0]='b';
		stu[i].age=18;
	}
	for(i=0;i<30;++i)
	{
		printf("name:%s\n",stu[i].name);
		printf("schoolnumber:%s\n",stu[i].num);
		printf("age:%d\n",stu[i].age);
	}
	return 0;
}
