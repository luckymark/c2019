//  just put save.txt and load.txt in the same direction of warehouse.cpp is ok .
//  it doesn't matter if you don't create the two txt , my program take it in to consideration 

#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

struct Item{
	int amount,id;
	char name[10];
	Item *next;
	Item(int i,int n,char *s): id(i),amount(n),next(NULL) {
		strcpy(name,s);
	}
	void print(){
		printf("the name of the %d th item : %s , and the amount is %d\n",id,name,amount);
		if (next) next->print();
		else printf("we have these %d items above in total\n",id);
	}
	
}*head=NULL;

void modify(Item* &o,char* s,int amount,int sigma){  // sigma=1 is in_warehouse and sigma=-1 is out_warehouse
	if (!o && sigma==1){                       //  the first item so the id=1
		o=new Item(1,amount,s);
		printf("Add successfully !\n");
		return ;
	}
	if (!o && sigma==-1){
		printf("ERROR! we don't have such item named '%s'\n",s);
		return;
	}
	if ( strcmp(s,o->name) ==0 ){
		if (sigma==1){
			o->amount+=amount;
			printf("Add successfully !\n");
			return ;
		}
		if (sigma==-1 && amount >  o->amount ){
			printf("ERROR! we have this item but we don't have enough, we only have %d\n",o->amount);
			return ;
		}
		if (sigma==-1 && amount <= o->amount ){
			o->amount-=amount;
			printf("Delete successfully !\n");
		}
		if (o->amount==0){  // exactly out this item with no remain so attach the next to the ahead and delete this pointer 
			Item* p=o;
			o=o->next;
			delete(p);  // to save memory
			return ;
		} 
		return ;
	}
	if ( !o->next ) {   
		if (sigma==-1) {
			printf("ERROR! we don't have such item named '%s'\n",s);
		}
		else {    // is not the first item so the id is o->id + 1
			o->next=new Item(o->id+1,amount,s);
			printf("Add successfully !\n");
		}
		return ;
	}
	modify(o->next,s,amount,sigma);
	return ;
}

void print_instruction(){
	printf("please choose your requirment ,just input the number \n");
	printf("1: Show the inventory\n");
	printf("2: put something in storage\n");
	printf("3：take out something from storage\n");
	printf("4: save and end\n");
}
void print(){                                            //  op==1
	if( !head ) printf("We have no storage at present \n");
	else head->print();
	system("pause");
}

char read_name[10];
int read_amount;
void add(){                                              //  op==2
	printf("please imput the name , the amount\n");
	scanf("%s%d",read_name,&read_amount);
	modify(head,read_name,read_amount,1);
	system("pause");
}
void delet(){                                            //  op==3
	printf("please imput the name , the amount\n");
	scanf("%s%d",read_name,&read_amount);
	modify(head,read_name,read_amount,-1);
	system("pause");
}
void save(){                                             //   op==4
	FILE *fp = fopen("save.txt","w");	
	Item *o=head;
	while(o){
		fprintf(fp,"%s %d\n",o->name,o->amount);
		o=o->next;
	}
	fclose(fp);
	printf("save successfully !\n press any key to END THE PROGRAM ");
}
void load(){
	FILE *fp = fopen("load.txt","r");
	while(fp && fscanf(fp,"%s%d",read_name,&read_amount)==2){
		modify(head,read_name,read_amount,1);
	}
	system("cls");
	printf("Program Start !\n");	
	if (fp) printf(" Load successfully !") ;       // different output defends on whether we have load.txt
	fclose(fp);
	system("pause");
}
int main(){
	load();
	system("cls");
	print_instruction();
	int op;                         //  op is short for "operation" 
	while ( scanf("%d",&op) ){
		system("cls");
		if (op==1) print();
		else if (op==2) add();
		else if (op==3) delet();
		else if (op==4) {
			save(); break;
		}
		system("cls");
		print_instruction();
	} 
	return 0; 
} 

 
