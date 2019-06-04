#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"printchange.h"
#include"get_goal.h"
#pragma warning(disable : 4996)
int main() {
	int x = 0, y = 0;//position of people
	int n_goal = 0, n_achieve = 0, goal[5][2] = { 0 };
	char f;//control direction
	int step = 0;
	FILE *pf = fopen("D:/C2019/c2019/level1/p10_pushBoxes/pushBoxes/map.txt", "r");
	FILE *pf_grade = fopen("D:/C2019/c2019/level1/p10_pushBoxes/pushBoxes/grade.txt", "w+");
	if (pf == NULL)printf_s("error");
	if (pf_grade == NULL)printf_s("error");
	char map[HEIGHT][WIDTH] = { "" };
	char map_temp[HEIGHT][WIDTH] = { "" };
next:
	n_goal = get_goal(pf, goal) - 1;//get goal and position of people
	if (n_goal == 0) {
		system("cls");
		printf("恭喜通关");
		goto end;
	}
	for (int i = 0; i < HEIGHT; i++) {
		fgets(map[i], WIDTH + 1, pf);
	}
	start:
	for (int i = 0; i < HEIGHT; i++) {
		for (int k = 0; k <= WIDTH; k++)map_temp[i][k] = map[i][k];
	}//temporary map update
	system("cls");
	printf("%s", map_temp[0]);//print map
	printf("\n--------按r键重新开始---------");//print instruction
	x = goal[0][0]; y = goal[0][1];//initialize position of people
	while (f = getch()) {
		if (f == 'r') {
			step = 0;
			goto start;
		}
		f = getch();
		switch (f) {
		case 80://down
			if ((map_temp[y + 1][x] == 'B'/*Box*/ && (map_temp[y + 2][x] == ' ' || map_temp[y + 2][x] == '!'))
				|| (map_temp[y + 1][x] == ' ' || map_temp[y + 1][x] == '!')) {
				printchange(map_temp, x, y, 80, goal);
				y++;
				step++;
			} break;
		case 72://up
			if ((map_temp[y - 1][x] == 'B'/*Box*/&&(map_temp[y - 2][x] == ' '|| map_temp[y - 2][x] == '!'))
			|| (map_temp[y - 1][x] == ' '|| map_temp[y - 1][x] == '!')) {
				printchange(map_temp, x, y, 72, goal);
				y--;
				step++;
			} break;
		case 75://left
			if ((map_temp[y][x - 1] == 'B'/*Box*/&&(map_temp[y][x - 2] == ' '|| map_temp[y][x - 2] == '!'))
			|| (map_temp[y][x - 1] == ' '|| map_temp[y][x - 1] == '!')) {
				printchange(map_temp, x, y, 75, goal);
				x--;
				step++;
			} break;
		case 77://right
			if ((map_temp[y][x + 1] == 'B'/*Box*/&&(map_temp[y][x + 2] == ' '|| map_temp[y][x + 2] == '!'))
			|| (map_temp[y][x + 1] == ' '|| map_temp[y][x + 1] == '!')) {
				printchange(map_temp, x, y, 77, goal);
				x++;
				step++;
			} break;
		}
		for (int i = 1; i <= n_goal; i++) {
			if (map_temp[goal[i][1]][goal[i][0]] == 'B')n_achieve++;
		}
		if (n_achieve == n_goal) {
			system("cls");
			printf("Success!---共用%d步\n是否进入下一关？(Y/N)", step);
			fprintf(pf_grade, "%d ", step);
			step = 0; n_achieve = 0;
			if (getch() == 'Y'|| getch() == 'y')goto next;
			else if(getch() == 'N' || getch() == 'n')break;
		}
		else n_achieve = 0;
	}
end:
	fclose(pf);
	fclose(pf_grade);
	return 0;
}