#include "Board.h"
#include "Computer.h"
#include "Menu.h"
#include "Person.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main()
{
	Board* board;
	Menu* menu;

	Player* player1;
	Player* player2;

	Computer* comp;
	Person* p1;
	Person* p2;

	int moves;
	bool win;

	while (true)
	{
		menu = new Menu();

		menu->Init();
		moves = menu->GetSize() * menu->GetSize();

		//ustawienie wskaznika polimorficznego
		if (menu->GetMode()) //czlowiek vs czlowiek
		{
			p1 = new Person('X', 'A');
			p2 = new Person('O', 'B');
			player1 = p1;
			player2 = p2;
		}
		else //czlowiek vs komputer
		{
			p1 = new Person('X', 'A');
			comp = new Computer('O');
			player1 = p1;
			player2 = comp;
		}

		board = new Board(menu->GetSize());
		system("cls");
		
		//petla przeprowadzajaca gre
		while (true)
		{
			//gracz 1
			win = board->Win();
			if (moves && !win)
				player1->Move(menu, board);
			else
				break;
			moves--;
			
			//gracz 2
			win = board->Win();
			if (moves && !win)
				player2->Move(menu, board);
			else
				break;
			moves--;
		}

		//sprawdzenie czy nie ma remisu
		system("cls");
		board->Print();
		cout << endl;
		if (!moves && !win)
			cout << "Remis!" << endl << endl;
		
		if (menu->Repeat())
		{
			delete board;
			delete player1;
			delete player2;
			delete menu;
			system("cls");
		}
		else
			return 0;
	}
}