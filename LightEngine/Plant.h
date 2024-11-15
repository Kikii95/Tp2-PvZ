#pragma once
#include "Entity.h"
#include "State.h"
#include <vector>
#include "PvZScene.h"

class Zombie;

class Plant : public Entity {
    State* mCurrentState;
    PvZScene& scene;
    int mRow;
    int mAmmo;
    bool mReloading;

    std::vector<Zombie*> mZombiesInLane;

public:
    Plant(float radius, const sf::Color& color);
    ~Plant();

    void SetRow(int row) { mRow = row; }

    void SetState(State* state);

    void ShootProjectile();
    void StartReloading();
    bool IsReloadComplete() const;

    int GetAmmo() const { return mAmmo; }
    const std::vector<Zombie*>& GetZombiesInLane() const;

    void AddZombieToLane(Zombie* zombie) { mZombiesInLane.push_back(zombie); }
    void RemoveZombieFromLane(Zombie* zombie);
};
