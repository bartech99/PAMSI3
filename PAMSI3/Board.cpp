#include "Board.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Board::Print()
{
	cout << "  ";
	for (int i = 1; i <= this->size; i++)
		cout << "   " << i;
	cout << endl;
	for (int i = 1; i <= this->size; i++)
	{
		cout << "   ";
		for (int j = 0; j < this->size; j++)
			cout << "+---";
		cout << "+" << endl;
		cout << " " << i << " ";
		for (int j = 0; j < this->size; j++)
		{
			cout << "| ";
			if (this->board[i - 1][j] == '0')
				cout << " ";
			else
				cout << this->board[i - 1][j];
			cout << " ";
		}
		cout << "|" << endl;
	}
	cout << "   ";
	for (int i = 0; i < this->size; i++)
		cout << "+---";
	cout << "+" << endl;
}

bool Board::Win()
{
	return false;
}

Board::Board(int s)
{
	this->size = s;
	this->board = new char* [s];
	for (int i = 0; i < s; i++)
	{
		this->board[i] = new char[s];
		for (int j = 0; j < s; j++)
			this->board[i][j] = '0';
	}
}

Board::~Board()
{
	for (int i = 0; i < this->size; i++)
		delete[] this->board[i];
	delete[] this->board;
}