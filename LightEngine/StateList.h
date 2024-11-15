#pragma once
#include "State.h"
#include "Plant.h"

class Plant; 

class IdleState : public State {
public:
    void Start(Plant* plant) override;
    void Update(Plant* plant) override;
};

class ShootState : public State {
public:
    void Start(Plant* plant) override;
    void Update(Plant* plant) override;
};

class ReloadState : public State {
public:
    void Start(Plant* plant) override;
    void Update(Plant* plant) override;
};