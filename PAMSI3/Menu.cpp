#include "Menu.h"
#include <iostream>
#include <conio.h>
using namespace std;

constexpr auto MAX_SIZE = 100;

void Menu::Init()
{
	cout << "--- Kolko i krzyzyk ---" << endl << endl;
	cout << "Podaj rozmiar planszy: ";
	this->size = GetValue(3, MAX_SIZE);
	cout << "Podaj zakres: ";
	this->scope = GetValue(3, MAX_SIZE);
}

void Menu::Move()
{
	cout << "Teraz Twoj ruch." << endl;
	cout << "Kolumna: ";
	this->posX = GetValue(1, this->size) - 1;
	cout << "Wiersz: ";
	this->posY = GetValue(1, this->size) - 1;
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
			cout << "Blad, jeszcze raz: ";
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

Menu::Menu(int s, int sc, int px, int py)
{
	this->size = s;
	this->scope = sc;
	this->posX = px;
	this->posY = py;
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