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
    void GetPirateGold(int Gold);
    void Reset();
    void SetLevel(int level);
    void decreaseBalance(int cost);

    int money = 1000;
    int MaxHp = 100;
    int health = MaxHp;
private:
    
    int currentLevel;
};