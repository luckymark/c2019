# C语言学习笔记

# 记录你学习过程中的所见所思！酸甜苦辣！

# 看什么看！ 赶紧填坑啊！
---
- 使用`conio.h`里的`getch()`函数可以不显示字符地从键盘输入字符
- 每个方向键对应两个字符，第一个为224，代码参考如下：
```c
#include<stdio.h>
#include<conio.h>
void indir()  //input direction
{
  while(getch()!=224);  //in case of other unexpected characters
  switch(getch())
  {
    case 72:{}break;  //up
    case 75:{}break;  //left
    case 77:{}break;  //right
    case 80:{}break;  //down
    default:printf("Error!\n"); //for warning messages
  }
}
```
> For it's application, please [click here](https://github.com/Fyy10/c2019/tree/master/level1/p09_maze).
- 关于中文字，每个中文字对应两个字符，可以使用字符串存储和输出中文字
```c
#include<stdio.h>
#include<string.h>
int main()
{
  char chinese[3];  //2 char for 1 Chinese character and 1 for '\0'
  sprintf(chinese,"哈");
  printf("%s\n",chinese);
  return 0;
}
```
> For it's application, please [click here](https://github.com/Fyy10/ENIAC/blob/master/ChineseTest.cpp).
- 实际上，一个中文字也可以用整型变量(跟char相同只是占用两个字节)存储，输出则采用宽字符输出`wprintf()`
