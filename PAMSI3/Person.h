#pragma once
#include "Player.h"
#include "Menu.h"
#include <iostream>
using namespace std;

class Person :
    public Player
{
    char id;

public:

    void Move(Menu*, Board* board) override;
    Person(char, char);
    ~Person();
};