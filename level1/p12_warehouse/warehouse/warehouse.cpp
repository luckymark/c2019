#include<stdio.h>
#include<conio.h>
#include<windows.h>
#pragma warning (disable : 4996)
int main() {
	FILE *pf, *pf_temp;
	char order;
	char info[500];
	char model[4], model_temp[4];
	pf = fopen("D:\\C2019\\c2019\\level1\\p12_warehouse\\warehouse\\menu.txt", "r+");
	if (pf == NULL)printf("error");
start:
	system("cls");
	printf("请输入操作对应的序号:\n(1)显示存货列表\n(2)入库\n(3)出库\n(4)退出程序\n");
	while (order = getch()) {
		switch (order) {
		case 49: {
			system("cls");
			printf("按m回到主菜单\n");
			do {
				fscanf(pf, "%s", &info);
				printf("%s\n", info);
			} while (!feof(pf));
			break;
		}
		case 50: {
			system("cls");
			printf("请输入货物型号:");
			scanf("%s", model);
			do {
				char c;
				do {
					c = fgetc(pf);
				} while (c != '#');
				pf_temp = pf;
				fread(model_temp, sizeof(char), 3, pf_temp);
			} while (model_temp[0] == model[0] && model_temp[1] == model[1] && model_temp[2] == model[2]);
			
			break;
		}
		case 52:goto end; break;
		case 'm':goto start; break;
		}
	}
end:
	fclose(pf);
	return 0;
}