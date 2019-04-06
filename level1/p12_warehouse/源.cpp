#include"myhead.h"
goods good[100];
int main(int argc, char** argv) 
{
	int does = 0, all = 0;;
	freopen("data.txt", "r", stdin);
	all=scan();
	fclose(stdin);
	/*for(;does!=4;)
	{*/
		system("cls");
		print();
		in();
		cin >> does;
		/*if (does == 1)in();
		else if (does == 2)all=create(all);
		else if (does == 3)all=my_remove(all);
		else if (does == 4)break;*/
	//}
	freopen("data.txt", "w", stdout);
	save();
	fclose(stdout);
	return 0;
}
