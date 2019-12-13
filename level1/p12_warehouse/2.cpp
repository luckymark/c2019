#include <stdio.h>
#include <io.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

struct student
{
	char no[10];  // ѧ��
	char name[50]; // ����
	float score[3];      // ����
	float math;
	float eng;
};
struct data
{
	int count;   // ��ǰѧ��������ѧ���ĸ���
	struct student stu[MAX]; // ѧ������
}dd;

// ��ʾ���˵�
void menu()
{
	system("cls");//���� 
	printf("\n\n\n");
	printf("\t\t\t  *******************************\n");
	printf("\t\t\t                              \n");
	printf("\t\t\t     �ֿ����ϵͳ       \n");
	printf("\t\t\t                             \n");
	printf("\t\t\t    [1]   ��ʾ����б�      \n");
	printf("\t\t\t    [2]   ���        \n");
	printf("\t\t\t    [3]   ����         \n");
	printf("\t\t\t    [0]   �˳�����                 \n");
	printf("\t\t\t                             \n");
}

// �ȴ��û����س���ص����˵�
void to_menu()
{
	char c1, c2;
	printf("\n\n\n���س����������˵�...");
	scanf("%c%c", &c1, &c2);//��һ���ַ������ϴε�ȷ�ϻس��� 
	menu();
}

// ��ʾ����б�
void view_data()
{
	int i;
	printf("����\t����\t����\t����");
	printf("\n-------------------------------------------------------------------\n");
	for (i = 0; i < dd.count; i++)
		printf("%s\t%s\t%-7.1f\t%-7.1f\n", dd.stu[i].no, dd.stu[i].name, dd.stu[i].math, dd.stu[i].eng);
	printf("\n-------------------------------------------------------------------\n");
}


// �����ݴӽṹ�����鱣�浽�ļ���
void save_data()
{
	FILE* fp;//�ļ�ָ�� 
	int i, k;
	k = dd.count; //��ʵkû��ʲôʵ�ʵ����壬ֱ����fwrite��ʹ��&dd.count�Ϳ����ˡ�
	fp = fopen("D:\\data.txt", "w");//�ļ��洢λ�ã���ǰ�ļ��� 
	fwrite(&k, sizeof(int), 1, fp);
	for (i = 0; i < dd.count; i++)
		fwrite(&dd.stu[i], sizeof(struct student), 1, fp);
	fclose(fp);
}

// ���
void add_data()
{
	int b;
	int k = dd.count;
	while (k < MAX)
	{
		printf("��������ţ�");  scanf("%s", dd.stu[k].no);
		printf("������������ƣ�");  scanf("%s", dd.stu[k].name);
		printf("���������������");  scanf("%f", &dd.stu[k].math);
		printf("��������ﵥ�ۣ�");  scanf("%f", &dd.stu[k].eng);

		dd.count++; //��Ҫ��ǰ��0�����������С�
		k = dd.count;
		printf("\n\n������ӻ�����Ϣ[1-yes 0-no]:");
		scanf("%d", &b);
		if (b == 0) break;
	}
	save_data();
}

// �����ݴ��ļ������ṹ��������
void read_data()
{
	FILE* fp;
	int i, k;

	k = 0;
	if ((fp = fopen("D:\\data.txt", "r")) == NULL) // ����ļ�������
	{
		dd.count = 0;
	}
	else
	{
		fread(&k, sizeof(int), 1, fp);
		dd.count = k;
		for (i = 0; i < k; i++)
		{
			fread(&dd.stu[i], sizeof(struct student), 1, fp);
		}
		fclose(fp);
	}
}

// ����
void delete_data()
{
	int i, k;
	char no[10];
	printf("\n��������������:");
	scanf("%s", no);
	k = -1;
	for (i = 0; i < dd.count; i++)
	{
		if (strcmp(dd.stu[i].no, no) == 0)
		{
			k = i;
			break;
		}
	}
	if (k == -1)
	{
		printf("\n\nû���ҵ��û���(����-%s)!", no);
	}
	else
	{
		//��û��дɾ���Ĳ�����
		for (i = k; i < dd.count - 1; i++)    //�����������ǰ��һλ
			dd.stu[i] = dd.stu[i + 1];
		memset(&dd.stu[dd.count - 1], 0, sizeof(struct student));  //��dd.stu[dd.count-1]������0
		dd.count--;

		save_data();
		printf("\n\n����(����-%s)��¼�ɹ�!", no);
	}
}

// ������
int main()
{
	int fun;
	dd.count = 0;
	read_data();
	menu();
	while (1)
	{
		printf("�����빦�ܺ�[0-3]:");//���ﲻ��Ҫʲô&fun��
		scanf("%d", &fun);
		switch (fun)
		{
		case 1: view_data(); break;        // �鿴����ѧ����Ϣ 
		case 2: add_data(); break;       // ����ѧ����¼  
		case 3: delete_data(); break;      // ɾ��ѧ����¼
		case 0: break;                   // �˳�
		}
		if (fun == 0) break;
		to_menu();
	}

	return 0;
}

