/*
Circle Collider class
*/

#pragma once
#include "Collider.hpp"

namespace oni
{
    class CircleCollider : public Collider
    {
    public:
        CircleCollider(float radius, bool broadPhase = false);
        ~CircleCollider();

        //@brief Get the furthest point of the circle 
        Vector2 GetFurthestPoint() override;

        float GetRadius();
    private:
        //Radius of the circle
        float mRadius;
    }; 
}