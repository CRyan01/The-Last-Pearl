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
		std::cout << "\n Current money= " << money<<" Current cost= "<<cost;
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