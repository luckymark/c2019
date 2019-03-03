#include<cstdio>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<vector>
#include<windows.h>

#define BeginLine 40
#define W 160
#define H 40
#define NamePos 10
#define PricePos 40
#define NumPos 70

void Gotoxy(int posx,int posy);
int start_w,start_h;
std::string Menu[5] = {"Menu for Warehouse Manage.","Press [ 1 ] to show cargo.","Press [ 2 ] to input cargo to warehouse.",
	                 "Press [ 3 ] to output cargo from warehouse.","Press [ ESC ] to exit."}; 
std::string AddMenu[3] = {"Press [ C ] to add a new carge.","Press [ A ] to increase a cargo's num.","Press [ ESC ] to return."}; 

class cargo{
public:
	std::string name;
	int id,price,num;
	
	void Show(int n){
		Gotoxy(n,BeginLine);
		std::cout<<id+1;
		Gotoxy(n,BeginLine+NamePos);
		std::cout<<name;
		Gotoxy(n,BeginLine+PricePos);
		std::cout<<price;
		Gotoxy(n,BeginLine+NumPos);
		std::cout<<num;
	}

	void init(std::string s,int i,int p,int n){
		name = s;
		id = i;
		price = p;
		num = n;
	}

	void add(int n){
		num += n;
	}
	
};

std::vector< cargo > cargoes;

void SetConlse(){
	system("mode con cols=160 lines=40");
}

std::string to_string(int x){
	std::string t,res;
	while(x!=0){
		t.push_back('0' + x%10);
		x/=10;
	};
	for(int i = t.length() - 1;i>=0;i--){
		res.push_back(t[i]);
	}
	return res;
}

void PrintInformation(std::string *ss,int num){
    system("cls");
	int maxx = 0,len;
	for(int i = 0;i<num;i++){
		len = ss[i].length();
		maxx = std::max(len,maxx);
	}
	start_w = (W - maxx) / 2;
	start_h = (H - num*2) / 2;
	for(int i = 1;i<=H;i++){
		if(i == start_h){
			for(int k = 0;k<num;k++){
				int tmp = start_w + maxx+1;
				for(int l = 1;l<=W;l++){
					if(l==start_w - 2||l==tmp + 2) std::cout<<"\033[1m\033[31m"<<"#";
					else if(l==start_w+1) std::cout<<"\033[1m\033[31m"<<ss[k],l+=ss[k].length() - 1;
					else std::cout<<" ";
				}
				std::cout<<std::endl;
				for(int l = 1;l<=W;l++){
					if(l==start_w - 2||l==tmp + 2) std::cout<<"\033[1m\033[31m"<<"#";
					else std::cout<<" ";
				}
				std::cout<<std::endl;
			}
			i+=2*num;
		}
		else if(i == start_h + 2*num + 1 || i == start_h-1){
			for(int j = 1;j<=W;j++){
				if(j>=start_w - 2&&j<=start_w + maxx + 3) std::cout<<"\033[1m\033[31m"<<"#";
				else std::cout<<" ";
			}
			std::cout<<std::endl;
		}
		else std::cout<<std::endl;	
	}
}

void PreInit(){
	cargoes.clear();
	std::fstream file("data.dat",std::ios::in);
	cargo t;
	int num,id,price,n;
	std::string name;
	file >> num;
	for(int i = 1;i<=num;i++){
        file>>name>>id>>price>>n;
        t.init(name,id,price,n);
        cargoes.push_back(t);
	}
	file.close();
}

void Gotoxy(int posx,int posy){
	COORD CUR;
	HANDLE hout;
	CUR.X = posy;
	CUR.Y = posx;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,CUR);
}

void PrintTitle(int hight){
	Gotoxy(hight,BeginLine);
	std::cout<<"Id";
	Gotoxy(hight,BeginLine+NamePos);
	std::cout<<"Name";
	Gotoxy(hight,BeginLine+PricePos);
	std::cout<<"Price";
	Gotoxy(hight,BeginLine+NumPos);
	std::cout<<"Num";
}

void PrintLine(int hight){
	Gotoxy(hight,BeginLine);
	for(int i = 1;i<=80;i++) std::cout<<"-";
}

void SaveData(){
	std::fstream file("data.dat",std::ios::out|std::ios::trunc);
	int num = cargoes.size();
	file << num << std::endl;
	for(int i = 0;i<num;i++){
		file<<cargoes[i].name<<" "<<cargoes[i].id<<" "<<cargoes[i].price<<" "<<cargoes[i].num<<std::endl;
	}
	file.close();
}

int PrintList(int page){
	system("cls");
	PreInit();
	int begin = (page - 1) * 10;
	int end = page * 10;
	char c;
	if(begin > cargoes.size() || begin < 0) return 0;
	std::string s;
	std::vector<std::string> tmp;
	PrintTitle(13);
	PrintLine(14);
	for(int i = begin;i<end&&i<cargoes.size();i++){
		cargoes[i].Show(i+15 - begin);
	}
	PrintLine(25);
	Gotoxy(26,BeginLine);
	std::cout<<"Press [ > ] to next page.Press [ < ] to privious page.Press [ ESC ] to return.";
	c = getch();
	if(c == '.') return page + 1;
	else if(c == ',') return page - 1;
	else if((int)c == 27) return 0;
	SaveData();
}

void AddCargo(){
	PreInit();
	PrintInformation(AddMenu,3);
	std::string s;
	int id,num,price;
	char c;
	c = getch();
	if(c == 'c'){
		system("cls");
		std::cout<<"Cargo's name:";
		std::cin>>s;
		std::cout<<"Cargo's price:";
		std::cin>>price;
		std::cout<<"Cargo's num:";
		std::cin>>num;
		cargo t;
		t.init(s,cargoes.size(),price,num);
		cargoes.push_back(t);
	}
	else if(c == 'a'){
		system("cls");
		std::cout<<"Cargo's name:";
		std::cin>>s;
		std::cout<<"Add Cargo's num:";
		std::cin>>num;
		for(int i = 0;i<cargoes.size();i++)
		{
			if(s == cargoes[i].name){
				cargoes[i].add(num);
			}
		}
	}
	else if((int)c == 27) return;
	SaveData();
}

void DecreaseCargo(){
	PreInit();
	system("cls");
	std::string s;
	int num;
	std::cout<<"Cargo's name:";
	std::cin>>s;
	std::cout<<"DecreaseCargo's num:";
	std::cin>>num;
	for(int i = 0;i<cargoes.size();i++){
		if(s == cargoes[i].name){
			if(cargoes[i].num - num >= 0){
				cargoes[i].add(-num);
			}
		}
	}
	SaveData();
}

int main(){
	char c;
	SetConlse();
	while(1){
		PrintInformation(Menu,5);
		c = getch();
		if(c == '1'){
			int page = 1;
			while(1){
				if(page == 0){
					break;
				}
				else if(page >= 1){
					page = PrintList(page);
				}
			}
		}
		else if(c == '2'){
			AddCargo();
		}
		else if(c == '3'){
			DecreaseCargo();
		}
		else if((int)c == 27){
			return 0;
		}

	}
}
