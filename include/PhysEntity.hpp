#pragma once
#include <vector>
#include "Collider.hpp"

class PhysEntity : public GameEntity
{   
public:
    PhysEntity();
    virtual ~PhysEntity();

    virtual void Render();

    bool CheckCollision(PhysEntity* other);

    virtual void Hit(PhysEntity* other);

    void ClearHits();

    unsigned long GetID();
    bool GetColliderHit(int index);

    bool fullCheck = false;
protected:

    unsigned long mID;

    std::vector<Collider*> mColliders;

    Collider* mBroadPhaseCollider;

    void AddCollider(Collider* collider, Vector2 localPos = VEC2_ZERO);

    virtual bool IgnoreCollisions();
};