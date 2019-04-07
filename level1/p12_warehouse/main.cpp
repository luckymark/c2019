#include"myhead.h"
goods good[1000];
int main(int argc, char** argv) 
{
	int does = 0, all = 0; 
	all=scan();
	while(1)
	{
		system("cls");
		my_print(all);
		cin >> does;
		if (does == 1)in();
		else if (does == 2)all=create(all);
		else if (does == 3)all=my_remove(all);
		else if (does == 4)break;
	}
	save(all);
	return 0;
}
