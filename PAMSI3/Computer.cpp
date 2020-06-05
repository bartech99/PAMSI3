#include "Computer.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Computer::Move(Menu* menu, Board* board)
{
	system("cls");
	this->Make(board);
	board->board[this->y][this->x] = this->sign;
	board->Print();
	cout << endl;
	menu->Move(x + 1, y + 1);
	PressAnyKey();
}

void Computer::Make(Board* board)
{
	int best = INF;
	this->x = -1; //kolumna
	this->y = -1; //wiersz
	int depth = this->Depth(board);
	int move;

	for (int i = 0; i < board->GetSize(); i++)
	{
		for (int j = 0; j < board->GetSize(); j++)
		{
			if (board->board[i][j] == '0')
			{
				board->board[i][j] = 'X';
				move = this->Minimax(board, depth, true, -INF, INF);
				board->board[i][j] = '0';
				if (move < best)
				{
					best = move;
					this->x = j;
					this->y = i;
				}
			}
		}
	}
	board->board[this->y][this->x] = 'O';
}

int Computer::Depth(Board* board)
{
	if (board->GetSize() == 3) 
		return 9;
	else if (board->GetSize() >= 4 && board->GetSize() < 7) 
		return (9 - board->GetSize() + 1);
	else if (board->GetSize() >= 7 && board->GetSize() < 10) 
		return 3;
	else 
		return 2;
}

int Computer::Minimax(Board* board, int depth, bool check, int a, int b)
{
	char result = board->Win();

	if (result == 'X')
		return -10;

	if (result == 'O')
		return 10;

	if (depth == 0)
		return '0';

	if (check)
	{
		int best = -INF;
		for (int i = 0; i < board->GetSize(); i++) 
		{
			for (int j = 0; j < board->GetSize(); j++) 
			{
				if (board->board[i][j] == '0') 
				{

					board->board[i][j] = 'O';
					int score = this->Minimax(board, depth - 1, !check, a, b);
					board->board[i][j] = '0';

					best = max(score, best);
					a = max(a, score);
					if (b <= a) break;

				}
			}
		}
		return best;
	}
	else 
	{
		int best = INF;

		for (int i = 0; i < board->GetSize(); i++) 
		{
			for (int j = 0; j < board->GetSize(); j++) 
			{
				if (board->board[i][j] == '0') 
				{
					board->board[i][j] = 'X';
					int score = this->Minimax(board, depth - 1, !check, a, b);
					board->board[i][j] = '0';

					best = min(score, best);
					a = min(a, score);
					if (b <= a) break;
				}
			}
		}
		return best;
	}
}

Computer::Computer(char s) :
	Player(s)
{
}

Computer::~Computer()
{
}