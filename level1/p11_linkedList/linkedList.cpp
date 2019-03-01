#include<iostream>
#include<cstdio>
#include<ctime>

class linknode{
private:
    int value;
    linknode *nextnode;
    
public:
    void SetNextNode(linknode *p){
    	nextnode = p;
    }
    
    void init(int x){
    	value = x;
    	nextnode = NULL;
    }
    
    linknode *next(){
    	return nextnode;
	}
	
	int get_value(){
		return value;
	}
    
};

class linklist{
	
private:
    linknode *begin_node;
    int size;
    int search_pos;
    int last_search;
	    
public:
    void insert(int value){
    	linknode* now = new linknode;
    	now->init(value);
    	if(begin_node == NULL) begin_node = now;
    	else{
    		linknode* p = begin_node;
    		for(int i = 1;i<size;i++){
    			p = p->next();
			}
			p->SetNextNode(now);
		}
		size++;
    }
    
    int search(int x){
    	if(x != last_search) search_pos = -1;
    	last_search = x;
    	linknode* p = begin_node;
    	for(int i = 0;i<size;i++){
    		if(p->get_value() == x&&i>search_pos){
    			search_pos = i;
    			return i;
			}
			p = p->next();
		}
		if(p == NULL){
			search_pos =-1;
			return -1;
		}
	}
    
    linknode* back(linknode* fa){
    	linknode* p = fa->next();
    	if(fa->next() == NULL) return fa;
    	linknode* res = back(p);
    	p->SetNextNode(fa);
    	return res;
	}
    
    void change(){
    	linknode* last = back(begin_node);
    	begin_node->SetNextNode(NULL);
    	begin_node = last;
    	search_pos = -1;
	}
    
    int length(){
    	return size;
	}
    
    void init(){
    	begin_node = NULL;
    	size = 0;
    	search_pos = 0;
	}
	
	void show(){
		linknode* p = begin_node;
		for(int i = 0;i<size;i++){
			std::cout<<p->get_value()<<" ";
			p = p->next();
		}
		std::cout<<std::endl;
	}
};

linklist t;

int a,n;

void init(){
	std::cout<<"please input n(It is the total of your number):";
	std::cin>>n;
	for(int i = 1;i<=n;i++){
		std::cin>>a;
		t.insert(a);
	}
}

int main(){
	t.init();
	init();
	std::cout<<"the numbers are:"<<std::endl;
	t.show();
	t.change();
	std::cout<<"after change,the numbers are:"<<std::endl;
	t.show();
	std::cout<<"the pos of 5 is:"<<std::endl;
	std::cout<<t.search(5)<<std::endl;
	std::cout<<"the pos of next 5 is:"<<std::endl;
	std::cout<<t.search(5)<<std::endl;
	return 0;
}