#pragma once
#include <iostream>
using namespace std;

/*
 * Klasa ta zawiera plansze do gry
 * Zajmuje sie operacjami na tej tablicy - wypisywanie planszy w konsoli,
 * sprawdzenie czy ktos wygral, itd
 */

class Board
{
	int size;
	int scope;
	char** board;

public:

	void Print();
	char Win();
	char Check(char*);
	int GetSize();

	Board(int, int);
	~Board();
	
	friend class Computer;
	friend class Person;
};