#include<cstdio>
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<windows.h>

#define W 160
#define H 40

void Gotoxy(int posx,int posy);
int dirx[4] = {-1,0,1,0};
int diry[4] = {0,-1,0,1};
int start_w,start_h,pos; 
int grades[10];
std::string Menu[6] = {"Welcome to PushBoxes Game!","You can use WASD to move.","Press [ 1 ] to start game.","Press [ 2 ] to chose level.",
                       "Press [ 3 ] to see previous grade.","Press [ 4 ] to exit game"};
std::string EditHelper[8] = {"Ohhhhhhhhh,you find it!","This place can edit maps.","Press the level number you want to edit to press.",
                            "Remember to keep boxes number and targets number is equality!","You can use [ + ] and [ - ] to contral blocks."
							"Press [ B ] to put a Box,and press [ T ] to put a target.","And you can also press [ P ] to chose player's pos.",
							"If you want to restore,press [ R ]","Press [ ESC ] to return."};
std::string ErrorInfor[2] = {"The map data is wrong.","It would return after 3 seconds..."};
std::string Congratulation[3] = {" ","Press N to Next level.","Press [ ESC ] to return menu."};
std::string con[2] = {"You use "," step solve this level."};

/*<---------------------------------自定义变量结束 --------------------------------->*/ 

//声明一个Box类，用于箱子的移动等操作 							
class Box{                              
private:
    int x,y;    
public:
    void Init(int posx,int posy){
    	x = posx;
    	y = posy;
    }
    
    int X(){
    	return x;
    }
    
    int Y(){
    	return y;
    }
    
    void Change(int posx,int posy){
    	x = posx;
    	y = posy;
    }
};

//声明一个player类，用于玩家的移动，及对外输出坐标位置 
class Player{                         
private:
    int x,y;
public:
    void init(int posx,int posy){
    	x = posx;
    	y = posy;
    }
    
    //玩家移动 	
    bool Moveto(int toX,int toY,int w,int h){             
    	if(toX<0||toX>h||toY<0||toY>w) return false;
    	Gotoxy(x,y);
    	std::cout<<" ";
    	x = toX;
    	y = toY;
    	Gotoxy(x,y);
    	std::cout<<"\033[1m\033[31m"<<"@";
    	return true;
    }
    
    int X(){
    	return x;
    }
    
    int Y(){
    	return y;
    }
    
    //在控制台上显示 
    void Show(int h){                             
        Gotoxy(x,y);
	    std::cout<<"\033[1m\033[31m"<<"@"<<std::endl;
	    Gotoxy(h + 1,0);
	}
};

//声明一个MazeMap类，用于游戏的主要操作，玩家的移动及箱子的判断等 
class MazeMap{                                
private:
	int Map[50][50];
	int px,py;
	int BoxNum,TarNum;
	std::vector<Box> Boxes;
public:
	int w,h;
	
	//局部刷新地图在控制台的位置，edit=1的时候表示编辑模式 
	void Refresh(int posx,int posy,int edit){                
		Gotoxy(posx,posy);
		switch(Map[posx][posy]){
			case(0):
			    std::cout<<" ";
			    break;
            case(1):
                std::cout<<"\033[1m\033[32m"<<"#";
                break;
            case(2):
                std::cout<<"\033[1m\033[33m"<<"O";
                break;
            case(3):
                std::cout<<"\033[1m\033[34m"<<"X";
                break;
            case(4):
                if(edit){
				    std::cout<<"P";
                }
                break;
		}
		Gotoxy(h+1,0);
	}  
	
	//从这里开始是编辑的一些操作 
	void BreakBlock(Player *t){                                
		Map[t->X()][t->Y()] = 0;
	}
	
	void AddBlock(Player *t){
		Map[t->X()][t->Y()] = 1;
	}
	
	void SetBoxPos(Player *t){
		Map[t->X()][t->Y()] = 2;
	}
	
	void SetTarPos(Player *t){
		Map[t->X()][t->Y()] = 3;
	}
	
	void ChangePos(Player *t){
		Map[t->X()][t->Y()] = 4;
		Map[px][py] = 0;
		Refresh(px,py,1);
		px = t->X();
		py = t->Y();
	}
	
	//设置初始位置等操作所需接口 
	void Set(int width,int higth){
		w = width;
		h = higth;
	}
	
	void preInit(int posx,int posy,int value,bool edit){
		Map[posx][posy] = value;
		if(value == 4){
			px = posy;
			py = posx;
		}
		else if(value == 2&&!edit){
			Box t;
			Map[posx][posy] = 0;
			t.Init(posx,posy);
			Boxes.push_back(t);
		}
	}
	
	void SetPlayerPos(Player* t){
		t->init(px,py);
	}
	
	//文件输出时所用 
	int Output(int posx,int posy){
		return Map[posx][posy];
	}
	
	//对箱子的移动，如果箱子移动成功返回真 
	bool MoveBox(int toX,int toY,Box* t){
		if(Map[toX][toY] == 0 || Map[toX][toY] == 3 || Map[toX][toY] == 4){
			Gotoxy(t->X(),t->Y());
			std::cout<<" ";
			Gotoxy(toX,toY);
			std::cout<<"\033[1m\033[33m"<<"O";
			Refresh(t->X(),t->Y(),0);
			t->Change(toX,toY);
			return true;
		}
		return false;
	}
	
	//玩家是否能移动的判断，如果箱子不能动或者前方是墙等，返回假，表示不能移动 
	bool canMove(int toX,int toY,int dir){
		int l = Boxes.size();
		for(int i = 0;i<l;i++){
			if(Boxes[i].X() == toX && Boxes[i].Y() == toY){
				if(MoveBox(toX + dirx[dir],toY + diry[dir],&Boxes[i])) return true;
				else return false;
			}
		}
		if(Map[toX][toY] == 0 || Map[toX][toY] == 3 || Map[toX][toY] == 4){
			return true;
		}
		else return false;
	}
	
	//检测是否所所有的箱子都在对应位置上面了 
	bool CheckAllBox(){
		int l = Boxes.size();
		for(int i = 0;i<l;i++){
			if(Map[Boxes[i].X()][Boxes[i].Y()] == 3) continue;
			else return false;
		}
		return true;
	}
	
	//显示该地图上面的箱子 
	void ShowBox(){
		int l = Boxes.size();
		for(int i = 0;i<l;i++){
			Gotoxy(Boxes[i].X(),Boxes[i].Y());
			std::cout<<"\033[1m\033[33m"<<"O";
		}
	}
	
	//打印地图 
	void Show(int edit){
		system("cls");
		for(int i = 0;i<=h;i++){
			for(int j = 0;j<=w;j++){
				if(Map[i][j] == 1) std::cout<<"\033[1m\033[32m"<<"#";
				else if(Map[i][j] == 2) std::cout<<"\033[1m\033[33m"<<"O";
				else if(Map[i][j] == 3) std::cout<<"\033[1m\033[34m"<<"X";
				else if(Map[i][j] == 4&&edit) std::cout<<"P";
				else std::cout<<" ";
			}
			std::cout<<std::endl;
		}
		ShowBox();
	}
	
	//检测编辑是否合法 
	bool Check(){
		BoxNum = TarNum = 0;
		for(int i = 0;i<=h;i++){
			for(int j = 0;j<=w;j++){
				if(Map[i][j] == 2) BoxNum++;
				else if(Map[i][j] == 3) TarNum++;
			}
		}
		if(BoxNum == TarNum) return true;
		else return false;
	}
	
	bool Clear(){
		BoxNum = TarNum = 0;
		Boxes.clear();
	}
};

MazeMap Maps[10];
Player player;

//设置控制台大小 
void preInit(){
	system("mode con cols=160 lines=40");
}

//从文件读入地图并存入到MazeMap数组，edit = 1 表示编辑模式 
void Mapinit(int edit){
	std::fstream mapfile("gamemap.dat",std::ios::in);
	std::fstream mapdata("mapdata.dat",std::ios::in);
	int w,h,t;
	for(int i = 1;i<10;i++){
		mapdata >> w >> h;
		Maps[i].Clear();
		Maps[i].Set(w,h);
		for(int j = 0;j<=h;j++){
			for(int k = 0;k<=w;k++){
				mapfile >> t;
				Maps[i].preInit(j,k,t,edit);
			}
		}
	}
	mapfile.close();
	mapdata.close();
}

//将整数转换为string类 
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

//打印信息的函数，传入字符串数组 
void PrintInformation(std::string* ss,int num){
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


//局部刷新使用，将光标移动到对应的位置 
void Gotoxy(int posx,int posy){
	COORD CUR;
	HANDLE hout;
	CUR.X = posy;
	CUR.Y = posx;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,CUR);
}

//获取玩家按下的键并返回对应的值 
int GetTabs(){
	char c = getch();
	if(c == 27) return 10;
	char s[10] = {'w','a','s','d','t','b','p','=','-','r'};
	for(int i = 0;i<10;i++){
		if(s[i] == c) return i;
	}
	return -1;
}

//将地图保存到文件中，仅仅在edit模式下使用的函数 
void SaveMaps(){
	int th,tw;
	std::fstream mapfile("gamemap.dat",std::ios::in|std::ios::out|std::ios::trunc);
	for(int i = 1;i<10;i++){
		th = Maps[i].h;
		tw = Maps[i].w;
		for(int j = 0;j<=th;j++){
			for(int k = 0;k<=tw;k++){
				mapfile << Maps[i].Output(j,k) << " ";
			}
		}
		mapfile<<std::endl;
	}
	mapfile.close();
}

//对地图进行编辑的一系列操作 
void Edit(int x){
	int Command;
	Mapinit(1);
	Maps[x].Show(1);
	Maps[x].SetPlayerPos(&player);
	player.Show(Maps[x].h);
	while(1){
		Command = GetTabs();
		if(Command == -1) continue;
		if(Command < 4){
			int tx = player.X() + dirx[Command];
			int ty = player.Y() + diry[Command];
			if(player.Moveto(tx,ty,Maps[x].w,Maps[x].h))
			{
				tx -= dirx[Command];
		        ty -= diry[Command];
			    Maps[x].Refresh(tx,ty,1);
			    Gotoxy(Maps[x].h+ 1,0);
			}
		}
		else{
			switch(Command){
				case(4):
				    Maps[x].SetTarPos(&player);
				    break;
				case(5):
				    Maps[x].SetBoxPos(&player);
				    break;
				case(6):
				    Maps[x].ChangePos(&player);
				    break;
				case(7):
				    Maps[x].AddBlock(&player);
				    break;
                case(8):
                    Maps[x].BreakBlock(&player);
                    break;
                case(10):
                    {
                  	    if(Maps[x].Check()){
                    	    SaveMaps();
                    	    Mapinit(1);
                    	    return ;
                        }
                        else{
                    	    PrintInformation(ErrorInfor,2);
                    	    Mapinit(1);
                    	    Sleep(3000);
                    	    return ;
                        }
                    }
                    break;
			}
		}
		Sleep(125);
	}
}

//地图编辑 
void MapEdit(){
	int Command;
	while(1){
		PrintInformation(EditHelper,8);
		Command = getch();
		if(Command>='0' && Command <='9'){
			Edit(Command - '0');
		}
		else if(Command == 'r'){
            system("type basemap.dat > gamemap.dat");
            std::string s[1] = "Restore Successful!";
            std::cout<<s[0]<<std::endl;
            Sleep(1000);
		}
		else if(Command == 27){
			return ;
		}
	}
}

//从文件中获取分数存入数组 
void GetGrade(){
	std::fstream file("grade.dat",std::ios::in);
	for(int i = 1;i<10;i++){
		file >> grades[i];
	}
	file.close();
}

//保存分数到文件中 
void SaveGrade(int x,int level){
	std::fstream file("grade.dat",std::ios::in|std::ios::out);
	GetGrade();
	if(grades[level] > x || grades[level] == 0){
		grades[level] = x;
	}
	for(int i = 1;i<10;i++){
		file << grades[i] << " ";
	}
	file.close();
}

//打印分数 
void PrintGrade(){
	char c;
	GetGrade();
	for(int i = 1;i<10;i++){
		std::cout<<"Your highest grade in level "<<i<<" is "<<grades[i]<<"."<<std::endl;
	}
	c = getch();
	if(c == 27) return ;
}

//游戏的主体部分，传入level表示当前玩的关卡，返回值位level+1或0
//返回level时进入下一关，否则退到菜单栏 
int GameMain(int level){
	MazeMap Tmap = Maps[level];
	Tmap.SetPlayerPos(&player);
	Tmap.Show(0);
	player.Show(Tmap.h);
	int grade = 0;
	int Command;
	while(1){
		Command = GetTabs();
		int px,py,nx,ny,t;
		if(Command == 10) return 0;
		if(Command<0||Command>3) continue;
		px = player.X();
		py = player.Y();
		nx = px + dirx[Command];
		ny = py + diry[Command];
		t = Tmap.Output(nx,ny);
		if(Tmap.canMove(nx,ny,Command)){
			player.Moveto(nx,ny,Tmap.w,Tmap.h);
			Tmap.Refresh(px,py,0);
			Gotoxy(Tmap.h + 1,0);
			grade++;
		}
		if(Tmap.CheckAllBox()){
			std::string TempString = con[0] + to_string(grade) + con[1];
			Congratulation[0] = TempString;
			PrintInformation(Congratulation,3);
			SaveGrade(grade,level);
			Command = getch();
			if(Command == 'n'){
				if(level == 9) return 0;
				else return level + 1;
			}
			else if((int)Command == 27) return 0;
		}
	}
}
//游戏菜单的部分 
void GameMenu(){
    Mapinit(0);
    memset(grades,0,sizeof(grades));
    int level = 0;
    int Command;
    while(1){
    	PrintInformation(Menu,6);
    	Command = getch();
    	switch(Command){
	    	case('1'):
				{
					level = GameMain(1);
	    		    while(1){
    		    		if(level == 0) break;
    		    		else level= GameMain(level);
    		    	}   
	    	    }
	    	    break;
            case('2'):
                {
                	system("cls");
                	std::cout<<"Please input level you want to paly:";
                	std::cin>>level;
	    		    while(1){
    		    		if(level == 0) break;
    		    		else level = GameMain(level);
    		    	}
    		    	break;
                }
           case('3'):
               {
               	    system("cls");
               	    GetGrade();
               	    PrintGrade();
               }
               break;
           case('4'):
               return ;
	    }
	    if((int)Command == 13){
    		MapEdit();
    		Mapinit(0);
    	}
    }
}

int main(){
	preInit();
	GameMenu();
	return 0;
}
