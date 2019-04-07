#include"head.h"
point map[MAPLE_X+1][MAPLE_Y+1];
object players;
object box[NUM+1];
object re;
int main(int argc, char** argv) 
{
	int being_pushed_box;
	scan();
	int pd;
	char temp;
	object re;
	while(1)
	{
		print();
		temp=getch();
		pd=judge(temp);
		if(pd==1)players=change(temp,players);
		else if(pd==2)push_move(temp);
		else if(pd==3)break;
	}
	cout<<"ÄãÓ®ÁË"<<endl;
	return 0;
}
