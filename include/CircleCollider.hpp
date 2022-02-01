#pragma once
#include "Collider.hpp"

class CircleCollider : public Collider
{
public:
    CircleCollider(float radius, bool broadPhase = false);
    ~CircleCollider();

    Vector2 GetFurthestPoint() override;
private:
    float mRadius;
};