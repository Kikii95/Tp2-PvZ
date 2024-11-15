#include "PvZScene.h"
#include "Debug.h"
#include "Zombie.h"
#include "Plant.h"
#include <vector>

void PvZScene::Initialize() {
    pZombieSelected = nullptr;
    pPlantSelected = nullptr;

    for (int row = 0; row < NUM_ROWS; ++row) {
        zombies[row].clear();
        plants[row].clear();
        auto plant = CreateEntity<Plant>(50.f, sf::Color::Green);
        plant->SetPosition(150.f, static_cast<float>(ROW_Y_POSITIONS[row]));
        plant->SetRow(row);       
        plant->SetScene(this);    
        plants[row].push_back(plant);
    }
}

void PvZScene::HandleInput(const sf::Event& event) {
    if (event.type != sf::Event::EventType::MouseButtonPressed)
        return;

    int row = GetRowFromMousePosition(event.mouseButton.y);
    if (row == -1 || row >= NUM_ROWS) return;

    if (event.mouseButton.button == sf::Mouse::Button::Right) {
        auto pZombie = CreateEntity<Zombie>(50, sf::Color::Red);
        if (pZombie) {
            pZombie->SetPosition(event.mouseButton.x, ROW_Y_POSITIONS[row]);
            pZombie->SetDirection(-1.f, 0, 100);
            zombies[row].push_back(pZombie);
        }
    }

    if (event.mouseButton.button == sf::Mouse::Button::Left) {
        if (plants[row].empty()) {
            auto pPlant = CreateEntity<Plant>(75, sf::Color::Green);
            if (pPlant) {
                pPlant->SetPosition(150.f, static_cast<float>(ROW_Y_POSITIONS[row]));
                plants[row].push_back(pPlant);
            }
        }
    }
}

void PvZScene::Update() {
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (auto& plant : plants[row]) {
            plant->Update();
        }

        for (auto zombieIt = zombies[row].begin(); zombieIt != zombies[row].end(); ) {
            auto zombie = *zombieIt;

            for (auto plant : plants[row]) {
                if (zombie->IsColliding(plant)) {
                    plant->Destroy();
                    zombie->Destroy();
                }
            }

            if (zombie->ToDestroy()) {
                delete zombie;
                zombieIt = zombies[row].erase(zombieIt);
            }
            else {
                zombie->Update();
                ++zombieIt;
            }
        }
    }
}

const std::vector<Zombie*>& PvZScene::GetZombiesInRow(int row) const {
    return zombies[row];
}

int PvZScene::GetRowFromMousePosition(int mouseY) const {
    for (int i = 0; i < NUM_ROWS; ++i) {
        if (mouseY >= ROW_Y_POSITIONS[i] && mouseY < ROW_Y_POSITIONS[i] + ROW_HEIGHT) {
            return i;
        }
    }
    return -1;
}
