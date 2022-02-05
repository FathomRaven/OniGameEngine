#pragma once
#include "Texture.hpp"

class Collider : public GameEntity
{
public:
    enum class ColliderType 
    {
        Box,
        Circle
    };
    
    Collider(ColliderType type);
    virtual ~Collider();

    virtual Vector2 GetFurthestPoint() = 0;

    ColliderType GetType();

    virtual void Render();
    bool cHit = false;
protected:
    ColliderType mType;

    static const bool DEBUG_COLLIDERS = false;
    Texture* mDebugTexture;

    void SetDebugTexture(Texture* texture);
};