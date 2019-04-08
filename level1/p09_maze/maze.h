#ifndef _maze_H
#define _maze_H
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define Length 29
#define Height 29

char map[Height][Length];
struct Location
{
    int Y;
    int X;
} loc1;

int move(char map[][Length], struct Location *loc1, int X, int Y);
void printmap(char map[][Length]);

#endif