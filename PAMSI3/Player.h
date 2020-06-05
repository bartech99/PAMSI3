#pragma once
#include "Menu.h"
#include "Board.h"
#include <iostream>
using namespace std;

/*
 * Klasa bazowa gracza - komputer lub czlowiek
 */

class Player
{
protected:

	char sign;
	int x, y;

public:

	virtual void Move(Menu*, Board*) = 0;
	Player(char s) { this->sign = s; this->x = 0; this->y = 0; };
	~Player() {};
};