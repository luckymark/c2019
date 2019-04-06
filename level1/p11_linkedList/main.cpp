#include"myhead.cpp"
int main()
{
	int times=0;
	node* head=NULL;
	head=make(head);
	cout<<head->num;
	print(head);
	head=reverse(head);
	cout<<"链表已经反序"<<endl;
	print(head);
	cout<<"请输入您需要查找第几个5"<<endl;
	cin>>times;
	if(find(head,5,times)!=-1)cout<<find(head,5,times);
	else cout<<"链表中没有第"<<times<<"个5"<<endl; 
	return 0;
}
