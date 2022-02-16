/*
Physics Entity class

Has colliders, can be circle or box
If you want something to have collision, it needs this class
*/

#pragma once
#include <vector>
#include "Collider.hpp"

class PhysEntity : public GameEntity
{   
public:
    PhysEntity();
    virtual ~PhysEntity();

    virtual void Render();
    //Check if colliding with another physics entity
    bool CheckCollision(PhysEntity* other);

    virtual void Hit(PhysEntity* other, int collliderIndex = 0);
    //Clear collider hits

    unsigned long GetID();
    void SetID(unsigned long ID);
    //Check through all colliders
    bool fullCheck = false;
protected:
    //ID of entity
    unsigned long mID;

    std::vector<Collider*> mColliders;
    //The broad phase collider
    Collider* mBroadPhaseCollider;

    void AddCollider(Collider* collider, Vector2 localPos = VEC2_ZERO);

    virtual bool IgnoreCollisions();
};