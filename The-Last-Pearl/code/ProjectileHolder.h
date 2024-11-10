#pragma once

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Projectile.h"
#include <vector>
#include <string>
using namespace sf;

// By Conor Ryan
class ProjectileHolder {
public:
	ProjectileHolder();
	ProjectileHolder(float damage, float speed,  std::string textureFile);
	void update(float seconds);
	void draw(RenderWindow& window);
	void shoot(Vector2f Target,Vector2f Spawn);

private:
	std::vector<Projectile> bullets;
	float damage;
	float speed;
	std::string TextureName;
	Projectile TheBullet;
};