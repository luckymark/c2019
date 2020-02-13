#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#pragma warning(disable : 4996)//在VS里fopen没法直接使用，必须关掉警告
typedef struct
{
	char name[100];
	int number;
}things;

const int size = sizeof(things);
things goods[100];

void menu();
void show_all();
void getin();
void remove();


int main()
{
	char ch[100];
	while (1)
	{
		menu();
		gets_s(ch);
		switch (ch[0])
		{
		case '1':show_all(); break;
		case '2':getin(); break;
		case '3':remove(); break;
		case '4':printf("Thank you for usage!"); system("pause"); exit(0);
		default:printf("Wrong input.Please input your order again."); system("pause"); break;
		}
		system("pause");
	}
}
void menu()
{
	system("cls");
	printf("\t1:Show all things in the warehouse.\n");
	printf("\t2:Add things into the warehouse.\n");
	printf("\t3:Remove things from the warehouse.\n");
	printf("\t4:Exit this program.\n");
	printf("\tPlease input the number of order:");
	return;
}

void show_all()
{
	FILE *fp;
	int i=0, n = 0;
	if ((fp = fopen("1.txt", "ab+")) == NULL)
	{
		printf("Error!Can't open the file!");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&goods[n], size, 1, fp))
		{
			n++;
		}
	}
	fclose(fp);
	for (i = 0; i < n; i++)
	{
		printf("Name:%s\tNumber:%d\n", goods[i].name, goods[i].number);
	}
	return;
}

void getin()
{
	FILE *fp;
	int i = 0, n = 0;
	char new_name[100];
	int new_number;
	if ((fp = fopen("1.txt", "ab+")) == NULL)
	{
		printf("Error!Can't open the file!");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&goods[n], size, 1, fp))
		{
			n++;
		}
	}
	fclose(fp);
	if ((fp = fopen("1.txt", "wb+")) == NULL)
	{
		printf("ERROR!Can't open the FILE.");
		return;
	}

	printf("Input the name:");
	gets_s(new_name);
	printf("Input the number:");
	scanf_s("%d", &new_number);
	for (i = 0; i < n; i++)
	{
		if (strcmp(goods[i].name, new_name) == 0)
		{
			goods[i].number += new_number;
			for (i = 0; i < n; i++)
			{
				fwrite(&goods[i], size, 1, fp);
			}
			fclose(fp);
			return;
		}
	}
	strcpy(goods[n].name, new_name);
	goods[n].number = new_number;
	n++;
	for (i = 0; i < n; i++)
	{
		fwrite(&goods[i], size, 1, fp);
	}
	fclose(fp);
}

void remove()
{
	FILE *fp;
	int i = 0, n = 0;
	char new_name[100];
	int new_number;
	if ((fp = fopen("1.txt", "ab+")) == NULL)
	{
		printf("Error!Can't open the file!");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&goods[n], size, 1, fp))
		{
			n++;
		}
	}
	fclose(fp);
	if ((fp = fopen("1.txt", "wb+")) == NULL)
	{
		printf("ERROR!Can't open the FILE.");
		return;
	}

	printf("Input the name:");
	gets_s(new_name);
	printf("Input the number:");
	scanf_s("%d", &new_number);
	for (i = 0; i < n; i++)
	{
		if (strcmp(goods[i].name, new_name) == 0)
		{
			if (goods[i].number >= new_number)
			{
				goods[i].number -= new_number;
				for (i = 0; i < n; i++)
				{
					fwrite(&goods[i], size, 1, fp);
				}
				fclose(fp);
				return;
			}
			else
			{
				break;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		fwrite(&goods[i], size, 1, fp);
	}
	fclose(fp);
	return;
	printf("Wrong!Please act again!");
	
}

