#pragma once
#include "Entity.h"

class Projectile : public Entity {
public:
    Projectile(float radius, const sf::Color& color) : Entity(radius, color) {}

    void OnUpdate() override;

    void OnCollision(Entity* other) override;
};
