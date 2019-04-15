#include"dec.h"
int main()
{
	node *tmp,*head=NULL;
	int i;
	for(i=1;i<=10;++i)
	{
		head=addnode(head);
		(*head).val=i;
	}
	printlist(head);
	find5(head);
	head=reverse(head);
	printlist(head);
	find5(head);
	freeall(head,&head);
	return 0;
}
