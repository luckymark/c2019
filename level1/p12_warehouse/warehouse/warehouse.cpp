#include"search.h"
#include"new.h"
int main() {
	FILE* pf;
	char order, model_temp[5] = "\0";
	int data_temp = 0;
	pf = fopen("D:\\C2019\\c2019\\level1\\p12_warehouse\\warehouse\\menu.txt", "r+");
	if (pf == NULL)printf("error");
	list L = (list)malloc(sizeof(linkedlist));
	strcpy(L->model, "head");
	L->data = 0;
	L->next = NULL;
	list l_ = L;
	char c = '\0';
	while(1) {
		int k = fscanf(pf, "%4s %d", model_temp, &l_->data);
		if (k = -1)break;
		list L_temp = (list)malloc(sizeof(linkedlist));
		l_->next = L_temp;
		strcpy(l_->model, model_temp);
		L_temp->data = data_temp;
		L_temp->next = NULL;
		l_ = L_temp;
		c = fgetc(pf);
	} 
	system("cls");
	printf("请输入操作对应的序号:\n(1)显示存货列表\n(2)入库\n(3)出库\n(4)退出程序\n");
	while (order = getch()) {
		system("cls");
		printf("请输入操作对应的序号:\n(1)显示存货列表\n(2)入库\n(3)出库\n(4)退出程序\n");
		switch (order) {
		case 49: {
			system("cls");
			l_ = L;
			while (l_->next != NULL) {
				printf("%s:%d\n", l_->model, l_->data);
				l_ = l_->next;
			}
			printf("按m键返回菜单");
			break;
		}
		case 50: {
			system("cls");
			printf("请输入货物型号(例:A001):");
			scanf("%s", model_temp);
			l_ = search(L, model_temp);
			if (l_ == NULL) {
				printf("无货物%s，是否添加为新品？(Y/N)", model_temp);
				order = getch();
				if (order == 'Y' || order == 'y') {
					l_ = creatnode(L, model_temp);
					printf("\n请输入货物数量:");
					scanf("%d", &data_temp);
					l_->data = data_temp;
					printf("%s:%d\n按m键返回菜单", l_->model, l_->data);
				}
				else printf("按m键返回菜单");
			}
			else {
				printf("请输入货物%s入库的数量:", model_temp);
				scanf("%d", &data_temp);
				l_->data += data_temp;
				printf("按m键返回菜单");
			}
			break;
		}		
		case 51: {
			system("cls");
			printf("请输入货物型号(例:A001):");
			scanf("%s", model_temp);
			l_ = search(L, model_temp);
			if (l_ == NULL) {
				printf("无货物%s,按m键返回菜单", model_temp);
			}
			else {
				printf("请输入货物%s出库的数量:", model_temp);
				scanf("%d", &data_temp);
				l_->data -= data_temp;
				printf("\n按m键返回菜单");
			}
			break;
		}
		case 52:goto end; break;
		case 'm': break;
		}
	}
end:
	rewind(pf);
	l_ = L;
	while (l_->next != NULL) {
		fprintf(pf, "%s %010d\n", l_->model, l_->data);
		l_ = l_->next;
	}
	fclose(pf);
	free(pf);
	return 0;
}