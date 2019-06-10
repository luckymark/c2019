#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <string.h>
void createmap(char *a[100])
{
	strcpy(a[0],"XXXXXXXXXXXXXXXXXXXXXX");
	strcpy(a[1],"XXXXXXX   X   X       出口");
	strcpy(a[2],"XX   XX X X X X XXXXXX");
	strcpy(a[3],"X  X X  X   X X  XX");
	strcpy(a[4],"X X  X XXXXXX  X XX");
	strcpy(a[5],"X X XX       X X  X");
	strcpy(a[6],"X X   XXXXXX X XX X");
	strcpy(a[7],"X XXX XX   X X X  X");
	strcpy(a[8],"X   X XX X X X X XX");
	strcpy(a[9],"XXX X X  X X X X  X");
	strcpy(a[10],"X   X X X  X X  X X");
	strcpy(a[11],"X XXX X X X  XX   X");
	strcpy(a[12],"X XXX   X   XXXXXXX");
	strcpy(a[13],"XoXXXXXXXXXXXXXXXXX");
	strcpy(a[14],"  <-由此进入");
}