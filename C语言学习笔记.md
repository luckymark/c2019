#### 获取程序运行时间——clock()函数
利用clock函数获取程序到调用该函数占用cpu的时间
然后除去头文件ctime中所定义的时间单位即可获得程序运行时间。

####素数筛法

#### 获取键盘状态
`maze题所需`
>在windows.h库中，可以调用函数`GetAsyncKeyState(VK_LSHIFT)`对键盘进行检测，`VK_LSHIFT`为虚拟健值，`GetAsyncKeyState()`的返回值表示两个内容，一个是最高位bit的值，代表这个键是否被按下，一个是最低位bit的值，代表在上次调用GetAsyncKeyState()后，这个键是否被按下。
>在检测键盘按下时，应该使用`if(GetAsyncKeyState(VK_LSHIFT)&0x8000)`

#### std::cout输出颜色的修改
在cout后加颜色的关键字即可修改颜色，一次修改会影响后续的输出，所以在用到的时候如果需要不同颜色需要每次输出都加关键字
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
> SHORT X;
> SHORT Y;
>}COORD, *PCOORD;
>```
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
#### 文件的读写操作
>reinterpret_cast函数，强制转换，用法：`reinterpret_cast(<char* >)`强制转换为字符类型

#### Class类的操作注意
1、`private` 关键字表示该关键字后面的变量及函数仅仅其内部才能调用及修改，所以在外部进行修改的时候需要利用Class中public的函数进行改变；
2、`public`中的函数、变量是对外的API，可以在外面进行调用；
3、在调用函数或变量的时候，使用"->"，而不是"."；
