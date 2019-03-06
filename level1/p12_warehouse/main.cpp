#include<windows.h>
#include<iostream>
#include<cstring>
#include<conio.h>
#include<cstdio>
#include<vector>

#include"display.h"
#include"key.h"
#define BAR 40
#define RUNNING 1
#define bufLim 3000

std::string information = "<<<<<<<<<<<<<<<<<Warehouse>>>>>>>>>>>>>>  Type 'help' for commands\n";
std::string helpMessage = "add [itemName] [number]          ----Add something\nremove [itemName] [number]       ----Remove something in the list\nls                               ----View the list\nexit                             ----Exit the warehouse\n";

int itemCnt = 0;

struct item
{
	std::string name;
	int number;
};

std::vector<item> list;

int findItem(std::string name)
{
	for (int s = 0; s < list.size(); s++)
		if (name == list[s].name)
			return s;
	return -1;
}

void add()
{
	item tmp;
	std::cin >> tmp.name >> tmp.number;
	int pos = findItem(tmp.name);
	if (~pos)
	{
		list[pos].number += tmp.number;
	}
	else
	{
		list.push_back(tmp);
		itemCnt++;
	}
	//std::cout << "Added " << tmp.number << tmp.name << "(s)\n";
}

void remove()
{
	std::string str;
	int num;
	std::cin >> str >> num;
	int id = findItem(str);
	if (id == -1)
		std::cout << "No such item\n";
	else if (list[id].number < num)
		std::cout << "Not enough quantity for removing\n";
	else
		list[id].number -= num;
}

void displayList()
{
	for (int s = 0; s < list.size(); s++)
	{
		if (list[s].number != 0)
		{
			std::cout << list[s].name << " " << list[s].number << "\n";
		}
	}
}

void loadFile()
{
	FILE *fp = fopen("list.txt", "r+");
	item tmp;
	int total;
	fscanf(fp, "%d", &total);
	for (int s = 0; s < total; s++)
	{
		char ch[bufLim];
		fscanf(fp, "%s", ch);
		tmp.name = "";
		for (int s = 0; s < strlen(ch); s++)
			tmp.name += ch[s];
		fscanf(fp, "%d", &tmp.number);
		list.push_back(tmp);
		itemCnt++;
	}
	fclose(fp);
}

void saveFile()
{
	FILE *p = fopen("list.txt", "r+");
	fprintf(p, "%d\n", itemCnt);
	for (int s = 0; s < list.size(); s++)
	{
		char ch[100] = {'\0'};
		for (int t = 0; t < list[s].name.length(); t++)
			ch[t] = list[s].name[t];
		fprintf(p, "%s %d\n", ch, list[s].number);
	}
	fclose(p);
}

void run()
{
	loadFile();
	std::cout << information;
	std::string opt;
	while (RUNNING)
	{
		saveFile();
		std::cin >> opt;
		if (opt == "help")
		{
			std::cout << helpMessage;
		}
		else if (opt == "ls")
		{
			displayList();
		}
		else if (opt == "add")
		{
			add();
		}
		else if (opt == "remove")
		{
			remove();
		}
		else if (opt == "exit")
		{
			return;
		}
	}
}

int main()
{
	run();
}
