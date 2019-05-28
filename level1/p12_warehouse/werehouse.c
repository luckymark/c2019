#include<stdio.h>
#define N 20
#define PRESS_ANYKEY printf("请输入任意键继续……");getchar();getchar();
#include<string.h>
struct repertory {
	char id[10],name[10],list[10],production[10];
	int num;
} per[N];
void menu() {
	printf("\t\t***************************************\n");
	printf("\t\t*          库存信息管理系统           *\n");
	printf("\t\t*              1、新建                *\n");
	printf("\t\t*              2、查询                *\n");
	printf("\t\t*              3、修删                *\n");
	printf("\t\t*          4、售出或进货              *\n");
	printf("\t\t*              5、退出                *\n");
	printf("\t\t***************************************\n");
}
void add_menu() {
	printf("\t\t<<<<<<<<<<<<<<新建>>>>>>>>>>>>>>>\n");
	printf("\t\t         1、新建信息库           \n");
	printf("\t\t         2、添加商品             \n");
	printf("\t\t         3、返回                 \n");
	printf("\t\t<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>\n");
}
void seek_menu() {
	printf("\t\t<<<<<<<<<<<<<<查看>>>>>>>>>>>>>>>\n");
	printf("\t\t         1、查看信息库           \n");
	printf("\t\t         2、查找商品号           \n");
	printf("\t\t         3、返回                 \n");
	printf("\t\t<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
}
void change_menu() {
	printf("\t\t<<<<<<<<<<<<修改或删除>>>>>>>>>>>>\n");
	printf("\t\t         1、修改商品信息          \n");
	printf("\t\t         2、删除商品信息          \n");
	printf("\t\t         3、返回                  \n");
	printf("\t\t<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
}
void jinchu_menu() {
	printf("\t\t<<<<<<<<<<<<进货或出售>>>>>>>>>>>>\n");
	printf("\t\t         1、出售                  \n");
	printf("\t\t         2、进货                  \n");
	printf("\t\t         3、返回                  \n");
	printf("\t\t<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
}
char load();
void save(char m);
void add();
void charu();
void print();
void seek();
void change();
void del();
void jinchu();
char load() {
	int m=0;
	FILE *fp;
	if((fp = fopen("mchar","r"))==NULL) {
		fclose(fp);
	} else {
		m = fgetc(fp);
		if(m<=0) {
			fclose(fp);
		} else {
			return (m);
			fclose(fp);

		}
	}
}
void save(char m) {
	FILE*fp;
	if((fp = fopen("mchar","w"))==NULL) {
		m=0;
		fputc(m,fp);
		fclose(fp);
	} else {
		fputc(m,fp);
		fclose(fp);
		fp=fopen("repertory_list","w");
		fwrite(per,sizeof(struct repertory),m,fp);
		fclose(fp);
	}
}
void add() {
	char m = load();
	int i,n,count=0;
	char M;
	printf("请输入你需要增加的数量:");
	scanf("%d",&n);
	for(i=m; i<(m+n); i++) {
		count++;
		printf("请输入第%d个商品信息",count);
		printf("商品号：");
		scanf("%s",&per[i].id);
		printf("商品名称:");
		scanf("%s",&per[i].name);
		printf("商品类别:");
		scanf("%s",&per[i].list);
		printf("商品数量:");
		scanf("%d",&per[i].num);
		printf("产地:");
		scanf("%s",&per[i].production);
	}
	M=n+m;
	save(M);
}
void charu() {
	char m=load();
	int i;
	i = m;
	printf("商品号：");
	scanf("%s",&per[i].id);
	printf("商品名称:");
	scanf("%s",&per[i].name);
	printf("商品类别:");
	scanf("%s",&per[i].list);
	printf("商品数量:");
	scanf("%d",&per[i].num);
	printf("产地:");
	scanf("%s",&per[i].production);
	m = m+1;
	save(m);
}
void print() {
	char m=load();
	int i;
	if(m>0) {
		printf("编号\t名称\t类别\t数量\t产地\t提醒\n");
		for(i=0; i<m; i++) {
			printf("%s\t%s\t%s\t%d\t%s\t",per[i].id,per[i].name,per[i].list,per[i].num,per[i].production);
			if(per[i].num < 3) {
				printf("数量太少\n");
			} else {
				printf("\n");
			}
		}
	} else
		printf("库存没有商品\n");
}
void seek() {
	char j[5],m=load();
	int i;
	printf("请输入要查询的名称：");
	scanf("%s",&j);
	if(m<=0)
		printf("当前数据库没有商品信息\n");
	else
		for(i=0; i<m; i++) {
			if(strcmp(j,per[i].name)==0) {
				printf("编号\t名称\t类别\t数量\t产地\n");
				printf("%s\t%s\t%s\t%d\t%s\t\n", per[i].id,per[i].name,per[i].list,per[i].num,per[i].production);
			}
		}
}
void change() {
	char m =load();
	char c[10];
	int c1;
	int i,j=0;
	if(m<=0)
		printf("当前数据库没有数据");
	else
		printf("请输入需要修改商品编号");
	scanf("%s",&c);
	for(i=0; i<m; i++) {
		if(strcmp(per[i].id,c)==0) {
			printf("查找到的商品信息如下\n");
			printf("编号\t名称\t类别\t数量\t产地\n");
			printf("%s\t%s\t%s\t%d\t%s\t\n", per[i].id,per[i].name,per[i].list,per[i].num,per[i].production);
			printf("如果某项信息不想改动可以直接输入-");
			printf("把这件商品的名称改为：");
			scanf("%s",&c);
			if (strcmp(c, "-"))
				strcpy(per[i].name, c);
			printf("把这件商品的商品类别改为：");
			scanf("%s", &c);
			if (strcmp(c, "-"))
				strcpy(per[i].list, c);
			printf("把这件商品的数量改为：");
			scanf("%d", &c1);
			if (strcmp(c, "-"))
				per[i].num=c1;
			printf("把这件商品的产地改为：");
			scanf("%s", &c);
			if (strcmp(c, "-"))
				strcpy(per[i].production, c);
			save(m);
			break;
		} else
			j++;
	}
	if(j>0)
		printf("找不到该商品");
}
void del() {
	char num[5],m=load();
	int i,k;
	if(m<0)
		printf("当前数据库没有商品信息");
	else
		printf("请输入删除的商品编号:");
	scanf("%s",&num);
	for(i=0; i<m; i++)
		if(strcmp(per[i].id,num)==0) {
			for(k=i; k<m-1; k++) {
				per[k]=per[k+1];
			}
			m--;
			save(m);
			printf("数据已删除");
			break;
		}
}
void jinchu() {
	char na[5],m=load();
	int yu1,i,j,k;
	jinchu_menu();
	printf("请输入序号：");
	scanf("%d", &i);
	switch(i) {
		case 1: {
			if(m<=0)
				printf("\t\t该信息库为空!!!\n");
			else
				printf("请输入要定的商品号:");
			scanf("%s",&na);
			for(j=0; j<m; j++) {
				if(strcmp(na,per[j].id)==0) {
					printf("已找到商品，请输入要售出的商品数量：");
					scanf("%d",&yu1);
					if(yu1 <= 0) {
						printf("输入的数量有误");
					} else if(per[i].num>=yu1) {
						per[i].num = per[i].num - yu1;
						printf("\t\t出售成功\n");
						save(m);
					} else {
						printf("商品数量不足");
					}
					break;
				} else
					k++;

			}
			printf("商品不存在\n");
			break;
		}
		case 2: {
			if(m<=0) {
				printf("\t\t该信息库为空!!!\n");
			}
			printf("请输入要定的商品号:");
			scanf("%s", &na);
			for(j=0; j<m; j++) {
				if(strcmp(na,per[j].id)==0) {
					printf("已找到商品，请输入要进货商品数量：");
					scanf("%d",&yu1);
					if(yu1 <= 0) {
						printf("输入的数量有误");
					} else
						per[i].num = per[i].num + yu1;
					printf("\t\t进货成功\n");
					save(m);
					break;
				} else
					printf("商品不存在\n");
				break;
			}
		}
	}
}

void main() {
	int i;
	char m=0;
	FILE *fp;
	m=load();
	if(m>0) {
		fp=fopen("repertory_list","r");
		fread(per,sizeof(struct repertory),m,fp);
		fclose(fp);
	}
	do {
		m = load();
		menu();
		printf("请选择你需要操作的序号：");
		scanf("%d",&i);
		switch(i) {
			case 1:
				add_menu();
				printf("请选择你需要操作的序号：");
				scanf("%d",&i);
				switch(i) {
					case 1:
						add();
						continue;
					case 2:
						charu();
						print();
						PRESS_ANYKEY
						continue;
					case 3:
						break;
				}
				continue;
			case 2:
				seek_menu();
				printf("请选择你需要操作的序号：");
				scanf("%d",&i);
				switch(i) {
					case 1:
						print();
						PRESS_ANYKEY
						continue;
					case 2:
						seek();
					case 3:
						break;
				}
				continue;
			case 3:
				change_menu();
				printf("请选择你需要操作的序号：");
				scanf("%d",&i);
				switch(i) {
					case 1:
						change();
						print();
						PRESS_ANYKEY
						continue;
					case 2:
						del();
						print();
						continue;
					case 3:
						break;
				}
				continue;
			case 4:
				jinchu();
				continue;
			case 5:
				printf("BYE BYE!\n");
				PRESS_ANYKEY
		}
		break;
	} while(1);
}

