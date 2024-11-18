// Player.cpp
// John Hannon k00281825
//this is the cpp file for player
//the perpose of this file is to manage the players health, money and posibly score.
#include "Player.h"
#include "TextureHolder.h"

void Player::Hit(int damage)
{
	health -= damage;
	

}

bool Player::CanBuy(int cost)
{
	if (cost < money)
	{
		money -= cost;
		return true;
	}
	else 
	{
		return false;
	}
}

bool Player::GameOver()
{
	if (health <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Player::GetPirateGold(int Gold)
{

	money += Gold;

}

void Player::SetLevel(int level)
{
	switch (level)
	{
	case 1:
		 money = 1000;
		 MaxHp = 100;
		 health = MaxHp;
		break;
	case 2:
		money = 800;
		MaxHp = 100;
		health = MaxHp;
		break;
	case 3:
		money = 1500;
		MaxHp = 50;
		health = MaxHp;
		break;
	default:
		std::cout << "\nHow did we get here";
	}


}