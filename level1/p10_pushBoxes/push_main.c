#include "push.h"
int main() {
	printf("set the difficulty of the game:\n");
	puts("1:easy  2:normal 3:hard 4:hell");
	
	int n;
	scanf("%d",&n);
	system("cls");
	int mark=maze(n);
	while(mark!=0){
		system("cls");
//		printf("%d\n",mark); 
		printf("set the difficulty of the game:\n");
		puts("1:easy  2:normal 3:hard 4:hell");
		scanf("%d",&n);
		system("cls");
		mark=maze(n);
	}
	return 0;
}
