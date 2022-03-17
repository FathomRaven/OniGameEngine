/*
Physics Entity class

Has colliders, can be circle or box
If you want something to have collision, it needs this class
*/

#pragma once
#include <vector>
#include "Collider.hpp"

namespace oni
{
    class PhysEntity : public GameEntity
    {   
    public:
        PhysEntity();
        virtual ~PhysEntity();

        virtual void Render();

        /**
         * @brief Return if two PhysicsEntity are colliding
         * @param other The other PhysEntity 
        */
        bool CheckCollision(PhysEntity* other);

        /**
         * @brief A function called whenever a PhysicsEntity collides with another PhysicsEntity
         * @param other The PhysicsEntity responsible for the collision
         * @param colliderIndex The collider that was hit
        */
        virtual void Hit(PhysEntity* other, int collliderIndex = 0);

        //@brief Returns the ID of the PhysicsEntity
        unsigned long GetID();

        //@brief PhysicsEntity ID setter
        void SetID(unsigned long ID);

        //Set to true to find out which collider was collided with in the Hit() function
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
}