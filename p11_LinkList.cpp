/*
没太多好说的，一个单链表。
*/
#include<iostream>
#include<conio.h>
using namespace std;
struct Node {
	int value,num;
	Node* next;
}head;
Node* first = &head;
int v, k = 0,n;
void printNode() {
	Node* nn= first;
	while (1) {
		cout <<nn->value << ' ';
		if (nn->next == NULL)break;
		else nn = nn->next;
		}
}
void reverseNode() {
	int j = 1;
	Node* pre;
	Node* root;
	Node* will;
	pre = NULL;
	root = first;
	will = first->next;
	while (root) {
		will= root->next;
		root->next = pre;
		root->num = n - (j++) + 1;
		pre = root;
		root = will;
	}
	
	first = pre;
}
int findfive() {
	Node* nn = first;
	while (nn->value!=5) {
		nn = nn->next;
	}
	return nn->num;
}
int find2five() {
	Node* nn = first;
	int k = 0;
	while (1) {
		if (nn->value == 5)k++;
		if (k == 2)break;
		nn = nn->next;
	}
	return nn->num;
}
int main() {
	
	char c;
	cout << "请输入您想输入的节点个数" << endl;
	cin >> n;
	cout << "请输入每一个节点的值:" << endl;
	for (int i = 0; i < n - 1; i++) {
		cin >> first->value;
		first->num = i + 1;
		first->next = new Node();
		first = first->next;
	}
	first->next = NULL;
	first->num = n;
	cin >> first->value;
	first = &head;
	char f;
	while (1) {
		cout << "请输入您想进行的操作" << endl << "1.遍历所有的链表的值\n"
			<< "2.将链表中所有的节点反序\n" << "3.在链表中查询第一个等于5的值，并且返回序号，否则返回-1\n"
			<< "4.查找下一个值为5的节点，返回值同上\n\n" << "如果想要退出程序，请按0\n";
		v = getch();
		if (v == '1') {
			system("cls");
			printNode();
			f = getch();
			system("cls");
			continue;
		}
		if (v == '2') {
			system("cls"); 
			reverseNode();
			cout << "您的链表已经反序了";
			f = getch();
			system("cls");
			continue;
		}
		if (v == '3') {
			system("cls");
			cout << "值为5的第一个节点的序号为: " << findfive();
			f = getch();
			system("cls");
			continue;
		}
		if (v == '4') {
			system("cls");
			cout << "值为5的第二个节点的序号为; " << find2five();
			f = getch();
			system("cls");
			continue;
		}
		if (v == '0') {
			system("cls");
			break;
		}
	}
	
		k = 0;
		cout << "感谢您对本程序的使用，谢谢";
		return 0;
}