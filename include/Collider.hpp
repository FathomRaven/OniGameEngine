/*
Collider Class

Base class for box and circle colliders
*/
#pragma once
#include "Texture.hpp"

class Collider : public GameEntity
{
public:
    //Type of collider
    enum class ColliderType 
    {
        Box,
        Circle
    };
    
    Collider(ColliderType type);
    virtual ~Collider();
    //Get the furthest point
    virtual Vector2 GetFurthestPoint() = 0;
    //Get the type of collider
    ColliderType GetType();

    virtual void Render();
    //If hit or not
    bool cHit = false;
protected:
    ColliderType mType;
    //Set to true to render colliders
    static const bool DEBUG_COLLIDERS = false;
    Texture* mDebugTexture;

    void SetDebugTexture(Texture* texture);
};