//有一个bug，有时最后一列桥不会被访问到，但无法确定是什么时候！
#define LINE 35  //迷宫的大小，我们创建正方形的迷宫，边长必须为单数
#define MAXSIZE 1000 //栈内元素的上限,必须大于桥的数量

//迷宫上点的坐标
typedef struct point{
        int x;  //行
        int y;  //列
}POINTER;
