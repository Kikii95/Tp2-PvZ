#include "Projectile.h"

void Projectile::OnUpdate() {
    if (GetPosition().x > GetScene()->GetWindowWidth()) {
        Destroy(); 
    }
}

void Projectile::OnCollision(Entity* other) {
    if (other->IsTag(1)) { 
        other->Destroy(); 
        Destroy();        
    }
}