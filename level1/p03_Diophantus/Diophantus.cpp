#include<stdio.h>
int main()
{
	int nf=5,ns; //nf:age of Diophantus		ns:age of his son
	while((nf/6+nf/12+nf/7+5+ns+4)!=nf||nf%12!=0||nf%7!=0)
	{
		++nf;
		ns=nf/2;
	}
	printf("Diophantus\' age is %d.\n",nf-4);
	return 0;
}
