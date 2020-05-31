#pragma once
#include <iostream>
using namespace std;

class Board
{
	int size;
	char** board;

public:

	void Print();
	bool Win();

	Board(int);
	~Board();
	
	friend class Computer;
	friend class Person;
};