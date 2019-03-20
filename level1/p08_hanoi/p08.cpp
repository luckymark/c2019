#include <iostream>

using namespace std;

const int n = 10; //height of Hanoi
int step = 0;

int move(int, char, char, char);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	//for (int i = 2; i <= n; i++)
	//	step = step * 2 + 1;
	move(n, 'A', 'C', 'B');
	cout << "Total step: " << step << endl;	
}

int move(int plate, char from, char to, char empty)
{
	step++;
	if (plate == 1)
	{
		cout << plate << " from " << from << " to " << to << endl;
		return 0;
	}
	move (plate - 1, from, empty, to);
	cout << plate << " from " << from << " to " << to << endl;
	move (plate - 1, empty, to, from);
	return 0;
}
