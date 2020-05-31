#include "Person.h"
#include <iostream>
using namespace std;

void Person::Move(Menu* menu, Board* board)
{
	system("cls");
	board->Print();
	cout << endl << "Teraz ruch gracza " << this->id << endl << endl;
	while (true)
	{
		menu->Move();
		this->x = menu->GetPosX();
		this->y = menu->GetPosY();

		if (board->board[this->y][this->x] == '0')
		{
			board->board[this->y][this->x] = this->sign;
			break;
		}
		else
		{
			system("cls");
			board->Print();
			cout << endl << "Pole zajete! Wybierz jeszcze raz." << endl;
		}
	}
}

Person::Person(char s, char ID) :
	Player(s)
{
	this->id = ID;
}

Person::~Person()
{
}