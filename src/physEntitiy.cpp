#include "PhysEntity.hpp"

PhysEntity::PhysEntity()
{

}

PhysEntity::~PhysEntity()
{
    for (int i = 0; i < (int)mColliders.size(); i++)
    {
        delete mColliders[i];
        mColliders[i] = nullptr;
    }
    
    mColliders.clear();
}

void PhysEntity::AddCollider(Collider* collider, Vector2 localPos)
{
    collider->Parent(this);
    collider->Pos(localPos);
    mColliders.push_back(collider);
}

void PhysEntity::Render()
{
    for (int i = 0; i < (int)mColliders.size(); i++)
    {
        mColliders[i]->Render();
    }
}