#include<iostream>

using namespace std;

const int maxLength = 10000;

struct nodeStruct {
	int value;
	nodeStruct * next;
};

struct Linked_listStruct {
	nodeStruct * head, * end;
	int length;

	bool push_back(int value)
	{
		if (length == 0)
		{
			head = end = (nodeStruct *)malloc(sizeof(nodeStruct));
		}
		else
		{
			end->next = (nodeStruct *)malloc(sizeof(nodeStruct));
			end = end->next;
		}
		end->next = NULL;
		end->value = value;
		
		length++;

		return true;
	}

	Linked_listStruct()
	{
		length = 0;
		head = NULL;
		end = NULL;
	}

	Linked_listStruct(int * array, int arrayLength)
	{
		length = 0;
		for (int i = 1; i < arrayLength; i++)
		{
			push_back(array[i]);
		}
	}

	int findValue(int valueFind)
	{
		nodeStruct * cur = head, * last = head;
		int index = 0;
		while (cur != NULL)
		{
			if (cur->value == valueFind)
			{
				return index;
			}
			index++;
			last = cur;
			cur = cur->next;
		}
		return -1;
	}

	int findValue(int valueFind, int times)
	{
		nodeStruct * cur = head, * last = head;
		int index = 0;
		while (cur != NULL)
		{
			if (cur->value == valueFind)
			{
				times--;
				if (times == 0)
				{
					return index;
				}
			}
			index++;
			last = cur;
			cur = cur->next;
		}
		return -1;
	}
	
	bool erase(nodeStruct * delNode)
	{
		nodeStruct * cur = head, * last = head;
		while (cur != delNode)
		{
			last = cur;
			cur = last->next;
			if (cur == NULL)
			{
				return false;
			}
		}
		last->next = cur->next;
		free(cur);
		length--;
		return true;
	}

	bool erase(int delValue) //delete the first delValue in the linked_list
	{
		nodeStruct * cur = head, * last = head;
		while (cur->value != delValue)
		{
			last = cur;
			cur = last->next;
			if (cur == NULL)
			{
				return false;
			}
		}
		last->next = cur->next;
		free(cur);
		length--;
		return true;
	}

	bool clear()
	{
		nodeStruct * cur = head, * last = head;
		while (cur != NULL)
		{
			free(last);
			last = cur;
			cur = cur->next; 
		}
		free(last);
		head = end = NULL;
		length = 0;
	}

	int inverse()
	{
		/*int valueArray[maxLength];
		nodeStruct * cur = head;
		int arrayLength = 0;
		while (cur != NULL)
		{
			valueArray[arrayLength] = cur->value;
			arrayLength++;
			cur = cur->next;
		}
		Linked_listStruct inveseLinkedList;
		for (int i = 1; i <= arrayLength; i++)
		{
			inveseLinkedList.push_back(valueArray[length - i]);
		}*/

		nodeStruct *cur = head->next, *next, *last = head;
		while (last != end)
		{
			next = cur->next;
			cur->next = last;
			last = cur;
			cur = next;
		}

		end = head;
		end->next = NULL;
		head = last;

		return 0;
	}
};

ostream& operator << (ostream& out, Linked_listStruct list)
{
	nodeStruct * cur = list.head, *last = list.head;
	int index = 0;
	while (cur != NULL)
	{
		if (cur != list.head)
			out << " ";
		out << cur->value;
		last = cur;
		cur = cur->next;
	}
	return out;
}
