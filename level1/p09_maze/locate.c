//因为对hide()函数了解不够
//在很多地方疯狂加hide()
//但是光标就是有时候跳出来有时候不跳出来啊QAQ

#include<windows.h>

//光标定位
//根据书写习惯，实参是把行写在前，列写在后
void locate(int y, int x){
        HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(hout, coord);
}

//隐藏光标
void hide(){
        HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursor_info = {1, 0};
        SetConsoleCursorInfo(hout, &cursor_info);
}
