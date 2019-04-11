#include "LinkedList.h"

int main()
{
	int testArray[] = { 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9 };
	Linked_listStruct list(testArray, 18);

	list.push_back(10);
	list.push_back(5);
	cout << list << endl;

	cout << "The inversed list is: ";
	list.inverse();
	cout << list << endl << endl;

	cout << "Find the first 5: " << list.findValue(5) << endl;
	cout << "Find the third 5: " << list.findValue(5, 3);
}

