#pragma once
#include "Player.h"
#include "Menu.h"
#include <iostream>
using namespace std;

/*
 * Klasa pochodna od klasy player
 * Wykonuje ruch gracza
 */

class Person :
    public Player
{
    char id;

public:

    void Move(Menu*, Board* board) override;
    Person(char, char);
    ~Person();
};