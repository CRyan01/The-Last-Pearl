#include "ProjectileHolder.h"
#include <iostream>;

ProjectileHolder::ProjectileHolder()
{
	
	TextureName = "";


}
ProjectileHolder::ProjectileHolder(float damage, float speed, std::string textureFile)
{
	bullets.clear();
	this->damage = damage;
	this->speed = speed;
	TextureName = textureFile;
}
void ProjectileHolder::update(float seconds)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets.at(i).update(seconds);
	}
}
void ProjectileHolder::draw(RenderWindow& window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		std::cout << "\n TestPrinting";
		window.draw(bullets.at(i).getSprite());
	}
}
void ProjectileHolder::shoot(Vector2f Target,Vector2f Spawn)
{

	
	TheBullet.Spawn(damage, speed, TextureName,Target,Spawn);
	bullets.push_back(TheBullet);
}