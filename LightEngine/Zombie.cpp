#include "Zombie.h"
#include <iostream>

void Zombie::OnCollision(Entity* other) {
    if (other) {
        std::cout << "ZombieEntity::OnCollision with another entity" << std::endl;
    }
    else {
        std::cout << "ZombieEntity::OnCollision with nullptr" << std::endl;
    }
}

