#include <stdio.h>

void ChangePosition(int _res, char _from, char _trans, char _to)
{
	if (_res == 1)
	{
		printf("No.%d moved from %c to %c\n", _res, _from, _to);
		return;
	}
	ChangePosition(_res - 1, _from, _to, _trans);
	printf("No.%d moved from %c to %c\n", _res, _from, _to);
	ChangePosition(_res - 1, _trans, _from, _to);
}

int main()
{
	int n;
	scanf("%d", &n);
	ChangePosition(n, 'A', 'B', 'C');
	printf("Done\n");
	return 0;
}
