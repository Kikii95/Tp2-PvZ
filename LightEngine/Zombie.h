#pragma once
#include "Entity.h"

class Zombie : public Entity
{
public:
	Zombie(float radius, const sf::Color& color) : Entity(radius, color) {}

	void OnCollision(Entity* other) override;

};