#pragma once
#include <iostream>
using namespace std;

/*
 * Klasa ta zajmuje sie obsluga uzytkownika
 * Wyswietla stosowne komunikaty i pobiera potrzebne wartosci
 */

class Menu
{
	int size;
	int scope;
	int posX, posY;
	bool mode;

public:

	void Init();
	void Move();
	void Move(int, int);
	bool Repeat();

	int GetSize();
	int GetScope();
	int GetPosX();
	int GetPosY();
	bool GetMode();

	Menu(int = 3, int = 3, int = 0, int = 0, bool = false);
	~Menu();
};

void PressAnyKey();
int GetValue(int, int);