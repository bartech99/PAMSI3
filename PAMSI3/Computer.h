#pragma once
#include "Board.h"
#include "Player.h"
#include "Menu.h"
#include <iostream>
using namespace std;

class Computer :
    public Player
{
    void Make(char**);
    int Minimax(char**, int, bool);

public:

    void Move(Menu*, Board*) override;
    Computer(char);
    ~Computer();
};