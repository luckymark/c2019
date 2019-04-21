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
