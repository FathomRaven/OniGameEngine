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

    virtual void Render();
protected:
    ColliderType mType;

    static const bool DEBUG_COLLIDERS = true;
    Texture* mDebugTexture;

    void SetDebugTexture(Texture* texture);
};