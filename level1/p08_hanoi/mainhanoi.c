#include "hanoi.h"
long long count=0;
int main(int argc, char *argv[]) 
{
	hanoi(64,'A','B','C');
	printf("�ܹ�ִ����%lld��",count);
	return 0;
}
