#include "Plant.h"
#include "StateList.h"
#include "PvZScene.h"
#include "Projectile.h"

Plant::Plant(float radius, const sf::Color& color)
    : Entity(radius, color), mCurrentState(new IdleState()), mAmmo(3), mReloading(false), PvZScene&(scene){
    if (mCurrentState) {
        mCurrentState->Start(this); 
    }
}




Plant::~Plant() {
    delete mCurrentState;
}

void Plant::SetState(State* state) {
    delete mCurrentState;
    mCurrentState = state;
    mCurrentState->Start(this);
}

void Plant::ShootProjectile() {
        auto projectile = GetScene()->CreateEntity<Projectile>(10.f, sf::Color::Yellow);

        projectile->SetPosition(this->GetPosition().x + 20.f, this->GetPosition().y);

        projectile->SetDirection(1.f, 0.f, 300.f); }


void Plant::StartReloading() {
    mReloading = true;
    }

bool Plant::IsReloadComplete() const {
    return !mReloading; }

const std::vector<Zombie*>& Plant::GetZombiesInLane() const {
    return scene.GetZombiesInRow(mRow);
}


void Plant::RemoveZombieFromLane(Zombie* zombie) {
    mZombiesInLane.erase(std::remove(mZombiesInLane.begin(), mZombiesInLane.end(), zombie), mZombiesInLane.end());
}
