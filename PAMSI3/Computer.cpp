#include "Computer.h"
#include <iostream>
using namespace std;

void Computer::Move(Menu* menu, Board* board)
{
	system("cls");
	this->Make(board->board);
	board->board[this->y][this->x] = this->sign;
	board->Print();
	cout << endl;
	menu->Move(x + 1, y + 1);
	PressAnyKey();
}

void Computer::Make(char** board)
{
}

int Computer::Minimax(char**, int, bool)
{
	return 0;
}

Computer::Computer(char s) :
	Player(s)
{
}

Computer::~Computer()
{
}