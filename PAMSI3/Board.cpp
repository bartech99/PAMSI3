#include "Board.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Board::Print()
{
	system("cls");
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
			cout << this->board[i][j] << " ";
		cout << endl;
	}
}

void Board::MoveX()
{
}

void Board::MoveO()
{
}

Board::Board(int s)
{
	this->size = s;
	this->board = new int* [s];
	for (int i = 0; i < s; i++)
	{
		this->board[i] = new int[s];
		for (int j = 0; j < s; j++)
			this->board[i][j] = 0;
	}
}

Board::~Board()
{
	for (int i = 0; i < this->size; i++)
		delete[] this->board[i];
	delete[] this->board;
}