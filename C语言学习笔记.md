#### 获取程序运行时间——clock()函数
利用clock函数获取程序到调用该函数占用cpu的时间
然后除去头文件ctime中所定义的时间单位即可获得程序运行时间。

####素数筛法

#### 获取键盘状态
`maze题所需`
>在windows.h库中，可以调用函数`GetAsyncKeyState(VK_LSHIFT)`对键盘进行检测，`VK_LSHIFT`为虚拟健值，`GetAsyncKeyState()`的返回值表示两个内容，一个是最高位bit的值，代表这个键是否被按下，一个是最低位bit的值，代表在上次调用GetAsyncKeyState()后，这个键是否被按下。
>在检测键盘按下时，应该使用`if(GetAsyncKeyState(VK_LSHIFT)&0x8000)`