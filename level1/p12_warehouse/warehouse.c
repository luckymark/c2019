#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLTH 10
#define CAPACITY 1000

enum OPERATION {SHOWLIST= 1, PUSH, OUT, EXIT};
int inventory;

typedef struct{
	char id[MAXLTH];
	char data[MAXLTH];
	int num;
}WareHouse;

WareHouse Goods[CAPACITY];

void OpenRepository(void);
void ShowMenu(void);
void DisPlayTheGoods(void);
void InWareHouse(void);
void OutWareHouse(void);
void Close(void);

int main(void)
{
	int i;
	OpenRepository();
	ShowMenu();

	while(scanf("%d", &i)){
		switch(i){
			case SHOWLIST:
				DisPlayTheGoods();
				break;
			case PUSH:
				InWareHouse();
				break;
			case OUT:
				OutWareHouse();
				break;
			case EXIT:
				Close();
				exit(0);
				break;
			default:
				printf("Please enter the number before the operation you wanna perform:\n");
		}
	}

	return 0;
}
void OpenRepository(void)
{
	int i=0;
	FILE *fp= fopen(".\\GoodsList.txt", "r");

	while (EOF != fscanf(fp, "%s%s%d", Goods[i].id, Goods[i].data, &Goods[i].num)){
		i++;
	}

	fclose(fp);

	inventory= i;
}
void ShowMenu(void)
{
	printf("**************************************************\n");
	printf("*                                                *\n");
	printf("*           Inventory management system          *\n");
	printf("*             1.Show the repository list         *\n");
	printf("*             2.Push into repository             *\n");
	printf("*             3.Out of repository                *\n");
	printf("*             4.Exit the system                  *\n");	
	printf("*                                                *\n");
	printf("**************************************************\n");

	printf("Show your operation by the number: ");
}
void DisPlayTheGoods(void)
{
	printf("ID\tData of the production\tQuantity of goods\n");
	int i;

	for (i=0; i<inventory; i++){
		printf("%s\t%s\t\t%d\n", Goods[i].id, Goods[i].data, Goods[i].num);
	}
}
void InWareHouse(void)
{
	char id[MAXLTH];
	int num, i;

	printf("Please Enter the ID of the goods that you wanna push into the repository: ");
	scanf("%s", id);

	for (i=0; i<inventory; i++){
		if (0== strcmp(id, Goods[i].id)){
			printf("This kind of good has been existed, please enter the number of the goods you wanna push into: ");
			scanf("%d", &num);
			Goods[i].num+= num;
			printf("Warehousing success!\n");
			return;
		}
	}

	printf("The product does not exit in this warehouse. Please enter the ID, production date and quantity of the product: ");
	scanf("%s %s %d", Goods[inventory].id, Goods[inventory].data, &Goods[inventory].num);
	printf("Warehousing success!\n");
	inventory++;
}
void OutWareHouse(void)
{
	char id[MAXLTH];
	int num, i;
	printf("Please enter the ID of the goods that you wanna ship out: ");
	scanf("%s", id);

	for (i=0; i<inventory; i++){
		if (0== strcmp(id, Goods[i].id)){
			printf("There exists this goods in the warehouse, please enter the quantity of the goods you wanna ship out: ");
			scanf("%d", &num);

			if (num <= Goods[i].num){
				Goods[i].num-=num;
				printf("OutBound success!\n");
			}
			else{
				printf("Shortage of goods!\n");
			}

			return;
		}
	}

	printf("There doesn't exist such goods in the warehouse!\n");
}
void Close(void)
{
	FILE *fp= fopen(".\\GoodsList.txt", "w");
	int i;

	for (i=0; i<inventory; i++){
		fprintf(fp, "%s\t%s\t%d\n", Goods[i].id, Goods[i].data, Goods[i].num);
	}

	fclose(fp);
}