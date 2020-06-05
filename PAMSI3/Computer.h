#pragma once
#include "Board.h"
#include "Player.h"
#include "Menu.h"
#include <iostream>
using namespace std;

constexpr auto INF = 100000;

/*
 * Klasa pochodna od klasy player
 * Wykonuje ruch komputera
 * Zawiera mechanizm sztucznej inteligencji
 */

class Computer :
    public Player
{
    void Make(Board*);
    int Depth(Board*);
    int Minimax(Board*, int, bool, int, int);

public:

    void Move(Menu*, Board*) override;
    Computer(char);
    ~Computer();
};