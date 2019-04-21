#include "hanoi.h"
long long count=0;
int main(int argc, char *argv[]) 
{
	hanoi(64,'A','B','C');
	printf("总共执行了%lld步",count);
	return 0;
}
