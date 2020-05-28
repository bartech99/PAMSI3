#pragma once
#include <iostream>
using namespace std;

class Menu
{
	int size;
	int scope;
	int posX, posY;

public:

	void Init();
	void Move();
	bool Repeat();

	int GetSize();
	int GetScope();
	int GetPosX();
	int GetPosY();

	Menu(int = 3, int = 3, int = 0, int = 0);
};

void PressAnyKey();
int GetValue(int, int);