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

char Board::Win()
{
	char* signs = new char[this->scope];
	char result;
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			//sprawdzanie poziomo w prawo
			if (!(j + this->scope > this->size))
				for (int k = 0; k < this->scope; k++)
					signs[k] = this->board[i][j + k];
			result = this->Check(signs);
			if (result == 'X' || result == 'O')
			{
				delete[] signs;
				return result;
			}

			//sprawdzanie pionowo w dó³
			if (!(i + this->scope > this->size))
				for (int k = 0; k < this->scope; k++)
					signs[k] = this->board[i + k][j];
			result = this->Check(signs);
			if (result == 'X' || result == 'O')
			{
				delete[] signs;
				return result;
			}

			//sprawdzanie na skos w dó³ w lewo
			if (!(i - this->scope + 1 < 0 || j + this->scope > this->size))
				for (int k = 0; k < this->scope; k++)				
					signs[k] = this->board[i - k][j + k];
			result = this->Check(signs);
			if (result == 'X' || result == 'O')
			{
				delete[] signs;
				return result;
			}

			//sprawdzanie na skos w dó³ w prawo
			if (!(i + this->scope > this->size || j + this->scope > this->size))
				for (int k = 0; k < this->scope; k++)
					signs[k] = this->board[i + k][j + k];
			result = this->Check(signs);
			if (result == 'X' || result == 'O')
			{
				delete[] signs;
				return result;
			}
		}
	}
	delete[] signs;
	return '0';
}

char Board::Check(char* signs)
{
	bool win = true;
	for (int i = 0; i < this->scope; i++)
	{
		if (signs[i] != 'X')
		{
			win = false;
			break;
		}
	}
	if (win)
		return 'X';
	win = true;
	for (int i = 0; i < this->scope; i++)
	{
		if (signs[i] != 'O')
		{
			win = false;
			break;
		}
	}
	if (win)
		return 'O';
	return '0';
}

int Board::GetSize()
{
	return this->size;
}

Board::Board(int s, int sc)
{
	this->size = s;
	this->scope = sc;
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