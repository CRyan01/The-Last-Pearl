#include "ProjectileHolder.h"
#include <iostream>

ProjectileHolder::ProjectileHolder() 
{
	damage = 0;
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
	std::cout << "Updating projectiles in ProjectileHolder. Total projectiles: " << bullets.size() << "\n";
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

void ProjectileHolder::shoot(sf::Vector2f target, sf::Vector2f spawn, const std::string& texturePath) 
{
	TheBullet.Spawn(damage, speed, texturePath, target, spawn);
	bullets.push_back(TheBullet);
	std::cout << "Projectile added with texture " << texturePath << ". Total projectiles: " << bullets.size() << "\n";
}

void ProjectileHolder::clearInactive()
{
	size_t initialSize = bullets.size();
	bullets.erase(remove_if(bullets.begin(), bullets.end(),
		[](const Projectile& bullet) { return !bullet.isActive(); }),
		bullets.end());

	// Debug output to show number of projectiles cleared
	std::cout << "Inactive projectiles cleared. Initial count: " << initialSize
		<< ", New count: " << bullets.size() << "\n";
}

std::vector<Projectile>& ProjectileHolder::getProjectiles() 
{
	return bullets;
}