#ifndef _PB_H
#define _PB_H
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define Length 5
#define Height 5

char map[Height][Length];
struct Location
{
    int Y;
    int X;
};

int move(char map[][Length], struct Location *loc1, int X, int Y, struct Location *loc2);
void printmap(char map[][Length]);

#endif