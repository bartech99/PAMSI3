#pragma once
#include <iostream>
using namespace std;

class Board
{
	int size;
	int** board;

public:

	void Print();
	void MoveX();
	void MoveO();

	Board(int);
	~Board();
};