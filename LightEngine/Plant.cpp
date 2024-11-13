#include "Plant.h"

#include <iostream>

void Plant::OnCollision(Entity* other) {
    if (other) {
        std::cout << "PlantEntity::OnCollision with another entity" << std::endl;
        
    }
    else {
        std::cout << "PlantEntity::OnCollision with nullptr" << std::endl;
    }
}

