#pragma once
#include "Entity.h"

class Plant : public Entity
{
public:
	Plant(float radius, const sf::Color& color) : Entity(radius, color){}
	
	void OnCollision(Entity* other) override;

};

