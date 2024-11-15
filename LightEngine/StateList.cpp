#include "StateList.h"

void IdleState::Start(Plant* plant) {
    }

void IdleState::Update(Plant* plant) {
    if (!plant->GetZombiesInLane().empty()) {
        plant->SetState(new ShootState());
    }
}

void ShootState::Start(Plant* plant) {
    plant->ShootProjectile();
}

void ShootState::Update(Plant* plant) {
    if (plant->GetAmmo() <= 0) {
        plant->SetState(new ReloadState());
    }
    else if (plant->GetZombiesInLane().empty()) {
        plant->SetState(new IdleState());
    }
    else {
        plant->ShootProjectile();
    }
}


void ReloadState::Start(Plant* plant) {
    plant->StartReloading();
}

void ReloadState::Update(Plant* plant) {
    if (plant->IsReloadComplete()) {
        plant->SetState(new IdleState());
    }
}
