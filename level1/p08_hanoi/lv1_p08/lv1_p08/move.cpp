#include<stdio.h>
#include<iostream>
using namespace std;

int t = 0;
void AtoB(int x);
void BtoC(int x);
void CtoB(int x);
void BtoA(int x);
void CtoA(int x);

int AtoC(int x)
{
	if (x == 2)
	{
		cout << "A¡úB\nA¡úC\nB¡úC" << endl;
		t = t + 3;
	}
	else
	{
		AtoB(x - 1);
		cout <<  "A¡úC" << endl;
		BtoC(x - 1);
		t++;
	}
	return t;
}

void AtoB(int x)
{
	if (x == 2)
	{
		cout << "A¡úC\nA¡úB\nC¡úB" << endl;
		t = t + 3;
	}
	else
	{
		AtoC(x - 1);
		cout << "A¡úB" << endl;
		CtoB(x - 1);
		t++;
	}
	return;
}

void BtoC(int x)
{
	if (x == 2)
	{
		cout << "B¡úA\nB¡úC\nA¡úC" << endl;
		t = t + 3;
	}
	else
	{
		BtoA(x - 1);
		cout << "B¡úC" << endl;
		AtoC(x - 1);
		t++;
	}
	return;
}

void CtoB(int x)
{
	if (x == 2)
	{
		cout << "C¡úA\nC¡úB\nA¡úB" << endl;
		t = t + 3;
	}
	else
	{
		CtoA(x - 1);
		cout <<  "C¡úB" <<endl;
		AtoB(x - 1);
		t++;
	}
	return;
}

void BtoA(int x)
{
	if (x == 2)
	{
		cout << "B¡úC\nB¡úA\nC¡úA" << endl;
		t = t + 3;
	}
	else
	{
		BtoC(x - 1);
		cout << "B¡úA" << endl;
		CtoA(x - 1);
		t++;
	}
	return;
}

void CtoA(int x)
{
	if (x == 2)
	{
		cout << "C¡úB\nC¡úA\nB¡úA" << endl;
		t = t + 3;
	}
	else
	{
		CtoB(x - 1);
		cout << "C¡úA" << endl;
		BtoA(x - 1);
		t++;
	}
	return;
}