#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define MAXN 10000

char Message[11][50] = { "please input the type of goods\n","please input the quantity of goods\n","invalid input,please try again",\
"Please choose:\n","1:Display the inventory list\n","2:Inbound\n","3:Outbound\n","4:Exit\n","done\n","No goods\n","input any key to continue\n" };
char FileName_1[10] = "list.txt", FileName_2[10] = "list.swp";

struct goods
{
	int Quantity;
	char Type[50];
}Goods[MAXN + 5];

int TypeNum, OutNum;

void Refresh()
{
	while (1)
	{
		if (_kbhit())
		{
			_getch();
			break;
		}
	}
}

void ReadFromFile()
{
	FILE *fp;
	fp = fopen(FileName_1, "at+");
	fscanf(fp, "%d", &TypeNum);
	for (int i = 0; i < TypeNum; ++i)
		fscanf(fp, "%s%d", Goods[i].Type, &Goods[i].Quantity);
	fclose(fp);
}

void PrintToFile()
{
	FILE *fp;
	fp = fopen(FileName_2, "w");
	fprintf(fp, "%d\n", TypeNum - OutNum);
	for (int i = 0; i < TypeNum; ++i)
	{
		if (Goods[i].Quantity > 0)
			fprintf(fp, "%s %d\n", Goods[i].Type, Goods[i].Quantity);
	}
	fclose(fp);
	remove(FileName_1);
	rename(FileName_2, FileName_1);
}

void DisplayList()
{
	if (TypeNum == 0)
		printf("%s", Message[9]);
	for (int i = 0; i < TypeNum; ++i)
	{
		if (Goods[i].Quantity > 0)
			printf("%s:%d\n", Goods[i].Type, Goods[i].Quantity);
	}
	printf("%s", Message[10]);
}

void Inbound()
{
	int _num;
	char _type[50];
	system("cls");
	printf("%s", Message[0]);
	scanf("%s", _type);
	printf("%s", Message[1]);
	scanf("%d", &_num);
	for (int i = 0; i < TypeNum; ++i)
	{
		if (strcmp(Goods[i].Type, _type) == 0)
		{
			Goods[i].Quantity += _num;
			return;
		}
	}
	strcpy(Goods[TypeNum].Type, _type);
	Goods[TypeNum].Quantity = _num;
	TypeNum++;
	printf("%s", Message[8]);
	printf("%s", Message[10]);
}


void Outbound()
{
	int _num;
	char _type[50];
	system("cls");
	printf("%s", Message[0]);
	scanf("%s", _type);
	printf("%s", Message[1]);
	scanf("%d", &_num);
	for (int i = 0; i < TypeNum; ++i)
	{
		if (strcmp(Goods[i].Type, _type) == 0 && Goods[i].Quantity >= _num)
		{
			Goods[i].Quantity -= _num;
			if (Goods[i].Quantity == 0)OutNum++;
			printf("%s", Message[8]);
			printf("%s", Message[10]);
			return;
		}
	}
	printf("%s", Message[2]);
	printf("%s", Message[10]);
}

void Menu()
{
	unsigned char ch;
	do
	{
		system("cls");
		printf("%s", Message[3]);
		printf("%s", Message[4]);
		printf("%s", Message[5]);
		printf("%s", Message[6]);
		printf("%s", Message[7]);
		while (1)
		{
			if (_kbhit())
			{
				ch = _getch();
				switch (ch)
				{
				case '1':
					DisplayList();
					break;
				case '2':
					Inbound();
					break;
				case '3':
					Outbound();
					break;
				case '4':
					PrintToFile();
					return;
				default:
					printf("%s", Message[2]);
				}
				Refresh();
				break;
			}
		}
	} while (1);
}

int main()
{
	ReadFromFile();
	Menu();
	return 0;
}
