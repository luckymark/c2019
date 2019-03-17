# C语言学习笔记

# 记录你学习过程中的所见所思！酸甜苦辣！

# 看什么看！ 赶紧填坑啊！ 

system("cls")清屏命令

_getch()函数能读取键盘输入并不显示在屏幕上，用来做控制台游戏特别好2333

rand() % (x+1)+y     生成范围为[y,y+x)的随机数   （里面为元素个数）y为左端

用^运算符可以实现两个变量的交换，不用创建新的中间变量

在引用其他文件定义的变量时使用extern关键字来声明变量，如果不加的话会重复定义导致编译错误

memset函数   memset(*s,n,m) 将s中的m个字节设置为n

sort函数  头文件algorithm   将数组排序，不设置排序函数的话是从小到大   sort(start,end)

复制a数组中的K个元素到b memcpy(b,a,sizeof(int)*k)   其中int可改为double

const void*   可以通过强制类型转化变成任意类型的指针。

当一个未初始化赋值的时候(至少是vc 下未初始化的内存)默认是0xCCCCCCCC;，他在内存就默认保存为-858993460

while(int c=cin.get())!=EOF)就可以读入每个输入了，将EOF改为0或-1等等就可以判断是否输入结束了    while(cin>>a>>b>>c&&a!=-1)

find函数:  a.find(b，c)   从a中的第c个字符查找b（c可以不要），头文件是string  和它一起的还有一个string::npos  是一个常数，如果没有找到的话find函数返回这个常数，如果找到了函数返回查到的第一个位置（位置指的是查到的b第一个字符在a中的位置，跟数组差不多）

tolower ，toupper函数：    tolower()即可。 前者将大写转化为小写，后者转化为大写。 需要用循环来一个字符串里所有的字母全部转化   头文件是cctype

getline(cin,a) 可以直接读取一整行

a.length()能测string的长度