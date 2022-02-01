#pragma once
#include <vector>
#include "Collider.hpp"

class PhysEntity : public GameEntity
{   
public:
    PhysEntity();
    virtual ~PhysEntity();

    virtual void Render();

protected:

    std::vector<Collider*> mColliders;

    void AddCollider(Collider* collider, Vector2 localPos = VEC2_ZERO);

};