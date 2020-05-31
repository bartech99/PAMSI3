#include "Menu.h"
#include <iostream>
#include <conio.h>
using namespace std;

constexpr auto MAX_SIZE = 10;

void Menu::Init()
{
	system("cls");
	char x;
	cout << "--- Kolko i krzyzyk ---" << endl << endl;
	cout << "Podaj tryb gry:" << endl;
	cout << "singleplayer\t-s" << endl;
	cout << "multiplayer\t-m" << endl << endl;
	cout << "Twoj wybor: ";
	while (true)
	{
		if (cin >> x)
		{
			if (x == 's')
			{
				system("cls");
				cout << "--- Tryb gry gracz vs komputer ---" << endl;
				this->mode = false;
				break;
			}
			else if (x == 'm')
			{
				system("cls");
				cout << "--- Tryb gry gracz vs gracz ---" << endl;
				this->mode = true;
				break;
			}
		}
		cout << "Blad! Wpisz s lub m: ";
	}
	cout << endl << "Podaj rozmiar planszy (3-" << MAX_SIZE << "): ";
	this->size = GetValue(3, MAX_SIZE);
	cout << "Podaj zakres sprawdzania wygranej (3- " << this->size << "): ";
	this->scope = GetValue(3, this->size);
}

void Menu::Move()
{
	cout << "Kolumna: ";
	this->posX = GetValue(1, this->size) - 1;
	cout << "Wiersz: ";
	this->posY = GetValue(1, this->size) - 1;
	cout << endl;
}

void Menu::Move(int x, int y)
{
	cout << "Teraz ruch gracza B." << endl;
	this->posX = x;
	this->posY = y;
	cout << "Kolumna: " << x << ", wiersz: " << y << endl << endl;
}

bool Menu::Repeat()
{
	char x;
	cout << "Chcesz zagrac jeszcze raz? t/n: ";
	while (true)
	{
		cin >> x;
		if (x == 't')
			return true;
		else if (x == 'n')
			return false;
		else
			cout << "Blad! Jeszcze raz: ";
	}
}

int Menu::GetSize()
{
	return this->size;
}

int Menu::GetScope()
{
	return this->scope;
}

int Menu::GetPosX()
{
	return this->posX;
}

int Menu::GetPosY()
{
	return this->posY;
}

bool Menu::GetMode()
{
	return this->mode;
}

Menu::Menu(int s, int sc, int px, int py, bool m)
{
	this->size = s;
	this->scope = sc;
	this->posX = px;
	this->posY = py;
	this->mode = m;
}

Menu::~Menu()
{
}

void PressAnyKey()
{
	cout << endl << "Nacisnij dowolny przycisk, aby kontynuowac..." << endl;
	_getch();
	system("cls");
}

int GetValue(int min, int max)
{
	int x;
	while (true)
	{
		if (!(cin >> x) || x < min || x > max)
		{
			cin.clear();
			cin.sync();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cin.sync();
			cout << "Blad! Ponow: ";
		}
		else break;
	}
	return x;
}