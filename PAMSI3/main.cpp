#include "Board.h"
#include "Menu.h"
#include <iostream>
using namespace std;

int main()
{
	Board* board;
	Menu* menu = new Menu();

	while (true)
	{
		menu->Init();
		board = new Board(menu->GetSize());
		board->Print();

		//tu cala gra

		delete board;
		if (!menu->Repeat())
			return 0;
	}
}