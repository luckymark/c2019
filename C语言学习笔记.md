#### 获取程序运行时间——clock()函数
利用clock函数获取程序到调用该函数占用cpu的时间
然后除去头文件ctime中所定义的时间单位即可获得程序运行时间。

#### 素数筛法

#### 获取键盘状态
`maze题所需`
>在windows.h库中，可以调用函数`GetAsyncKeyState(VK_LSHIFT)`对键盘进行检测，`VK_LSHIFT`为虚拟健值，`GetAsyncKeyState()`的返回值表示两个内容，一个是最高位bit的值，代表这个键是否被按下，一个是最低位bit的值，代表在上次调用GetAsyncKeyState()后，这个键是否被按下。
>在检测键盘按下时，应该使用`if(GetAsyncKeyState(VK_LSHIFT)&0x8000)`

#### 迷宫的生成——Kruskal | Prim
参考：https://indienova.com/u/cocolate/blogread/1493
Keuskal算法是图论中常用的最小生成树算法，而在迷宫的生成中，可以先把迷宫设置为不可走的状态，然后过道与过道之间相连边
一开始每个点（过道）的并查集根为它自己，然后每次随机抽出一条边，检查其两端是否在一个并查集中，否则对该边进行操作（把墙打通）
>一开始每个点将自己作为单独的一棵树。
>1、从V中随机选出一条边v
>2、判断v两端的e1，e2是否属于一棵生成树
>>是，无动作
>>否，绘制e1,v,e2并合并树
>
>3、从V中删除v
>4、当V不为空，则返回 1. ，V为空则完成
>prim算法操作类似

#### maze题的过程
迷宫，首先肯定是要有地图，地图的生成最开始想到的方式的dfs随机运行，但是这样无法保证一定有通路并且地图的画风可能会很迷
查找了相关资料有一种利用Kruskal生成迷宫的算法，其主要就是随机生成最小生成树，然后利用并查集来查看两个点之间的连通性
但是在C++中没有java，python等语言中的库文件使用，导致利用该算法比较麻烦
>1、在二维中表示两个格子的连通性需要另外一种方法，表示连通性的边一般来说是u->v等，但是一个格子精确的位置需要两个参数，这时就需要二维变一维，利用格子的遍历顺序来进行加边，遍历格子的同时，在另外一个和map同样大小的数组中保存其顺序，以便于后面的加边操作
><center> ` tmp_map[i][j] = point_set.size(); ` </center>
>2、在C++中没有可以直接删除元素的STL可以使用，那么删除边的时候，考虑在vector中，将随机选取的边每次都和最后一个元素交换，同时用一个整数表示其位置
>``` 
>void vector_swap(int x){
	pos--;
	swap(edges[x],edges[pos]);
}
>```

重复的清除屏幕及打印的过程屏幕会闪烁，考虑局部刷新，利用SetConsoleCursorPosition函数来进行光标的跳转，输出空格然后下一个位置输出player的位置即可

将所有的函数利用，组装起来即可，核心是game()函数，首先清空屏幕，然后打印地图及player，再利用while函数检测在到达出口的时候结束，在循环体中接收玩家输入的字符，然后进行对应的操作即可

#### std::cout输出颜色的修改
在cout后加颜色的关键字即可修改颜色，一次修改会影响后续的输出，所以在用到的时候如果需要不同颜色需要每次输出都加关键字
PS：需要先使用了system命令后才会显示颜色
>|code                              |  color            |
  | :-------------------------:| :---------------:|
  |"\033[30m"                   |  Black   |
  |"\033[32m"                   |  Green |
  |"\033[33m"                   | Yellow |
  |"\033[34m"                   |  Blue |
  |"\033[35m"                   |  Magenta |
  |"\033[36m"                   |  Cyan |
  |"\033[37m"                   |  White |
  |"\033[1m\033[30m"     |  Bold Black |
  |"\033[1m\033[31m"     | Bold Red |
  |"\033[1m\033[32m"     | Bold Green |
  |"\033[1m\033[33m"     |  Bold Yellow |
  |"\033[1m\033[34m"     | Bold Blue |
  |"\033[1m\033[35m"     | Bold Magenta |
  |"\033[1m\033[36m"     |  Bold Cyan |
  |"\033[1m\033[37m"     |  Bold White |

#### windows.h头文件中的部分API的使用
>###### SetConsoleCursorPosition
>SetConsoleCursorPosition是windows.h的一个函数，其使用需要传入句柄HOUT及一个COORD坐标
>COORD结构声明为
>```
>typedef struct _COORD {
  SHORT X;
  SHORT Y;
} COORD, *PCOORD;
```
>使用SetConsoleCursorPosition函数后，可以将控制台光标移动到X,Y位置，X对应行，Y对应为列
>使用时可以自定义函数以方便调用
>```
>void gotoxy(int posx,int posy){
>    COORD ccur;
>    HANDLE hout;
>    ccur.X = posx;
>    ccur.Y = posy;
>    hout = GetStdHandle(STD_OUTPUT_HANDLE);
>    SetConsoleCursorPosition(hout,ccur);
>}
>```
#### 文件的读写操作 —— fstream类
>>reinterpret_cast函数，强制转换，用法：`reinterpret_cast(<char* >)`强制转换为字符类型
>
>fstream类中提供了`fstream`、`ifstream`、`ofstream`关键字对文件进行处理
>其中对文件的读写除了read及write之外还可以使用类似于`<iosteam>`中的流操作
>与cin和cout相同，文件对程序输入或者程序输出的时候，输入可以忽略掉空格及一些制表符
>而在输出的时候可以输出回车，空格等
>pushBoxes中对文件的输入输出示范


#### Class类的操作注意
1、`private` 关键字表示该关键字后面的变量及函数仅仅其内部才能调用及修改，所以在外部进行修改的时候需要利用Class中public的函数进行改变；
2、`public`中的函数、变量是对外的API，可以在外面进行调用；
3、在调用函数或变量的时候，使用"->"，而不是"."；

>#### Date 2019/3/2
>1、重构maze代码
>2、对pushBoxes的完善
