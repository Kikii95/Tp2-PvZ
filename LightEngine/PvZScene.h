#pragma once

#include "Scene.h"
#include "Zombie.h"
#include "Plant.h"
#include <vector>

const int NUM_ROWS = 3;             
const int ROW_HEIGHT = 240;       
const int ROW_Y_POSITIONS[NUM_ROWS] = { 120, 360, 600 }; 

class PvZScene : public Scene {
public:
    void Initialize() override;
    void HandleInput(const sf::Event& event) override;
    void Update() override;

private:
    std::vector<Zombie*> zombies[NUM_ROWS];
    std::vector<Plant*> plants[NUM_ROWS];  

    Zombie* pZombieSelected;              
    Plant* pPlantSelected;                

    int GetRowFromMousePosition(int mouseY) const; 
};
