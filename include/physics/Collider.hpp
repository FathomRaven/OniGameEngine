/*
Collider Class

Base class for box and circle colliders
*/
#pragma once
#include "Texture.hpp"
#include "Settings.hpp"

namespace oni
{
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
    protected:
        ColliderType mType;
        Texture* mDebugTexture;

        void SetDebugTexture(Texture* texture);
    };
}