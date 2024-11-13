// Player.h
//money and health mechanics
#pragma once
#include <iostream>
//cooments
class Player 
{
public:

    void Hit(int damage);
    bool CanBuy(int cost);
    bool GameOver();

private:
    int money = 1000;
    int MaxHp = 1000;
    int health = MaxHp;
    int currentLevel;
};