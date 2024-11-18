#include "ProjectileHolder.h"
#include <iostream>

ProjectileHolder::ProjectileHolder() 
{
	damage = 0; // For now all towers deal the 
	speed = 0;
	TextureName = "";
}

ProjectileHolder::ProjectileHolder(float damage, float speed, const std::string& textureFile)
	: damage(damage), speed(speed), TextureName(textureFile) 
{
	bullets.clear();
}

void ProjectileHolder::update(float elapsedTime) 
{
	for (auto& bullet : bullets) {
		bullet.update(elapsedTime);
	}
	clearInactive();
}

void ProjectileHolder::draw(RenderWindow& window) 
{
	for (const auto& bullet : bullets) 
	{
		if (bullet.isActive()) 
		{
			window.draw(bullet.getSprite());
		}
	}
}

void ProjectileHolder::shoot(sf::Vector2f spawn, Enemy* target, const std::string& texturePath, float damage, float maxRange)
{
	TheBullet.Spawn(damage, 600, texturePath, spawn, target, maxRange); // Here is where the bullet speed can be changed 
	bullets.push_back(TheBullet);
}

void ProjectileHolder::clearInactive()
{
	size_t initialSize = bullets.size();
	bullets.erase(remove_if(bullets.begin(), bullets.end(),
		[](const Projectile& bullet) { return !bullet.isActive(); }),
		bullets.end());


}

std::vector<Projectile>& ProjectileHolder::getProjectiles() 
{
	return bullets;
}

void ProjectileHolder::Reset()
{
	bullets.clear();

}