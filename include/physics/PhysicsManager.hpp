/*
Singleton PhysicsManager class

Handles the collision interaction between two entities

From this point onward, I dunno much about the code here as it's based from online. Bad practice, I know, but I also kinda don't care
I should care
*/

#pragma once 

#include "PhysEntity.hpp"
#include <bitset>

namespace oni
{
    class PhysicsManager
    {
    public:
        std::map<std::string, int> colliderLayers;

        //Singleton Stuff
        static PhysicsManager* Instance();
        static void Release();
        //Set collision mask between a layer and a flag
        void SetLayerCollisionMask(std::string layer, std::string flag);
        //Register Entity
        unsigned long RegisterEntity(PhysEntity* entity, std::string layer);
        void UnregisterEntity(unsigned long id);

        int GetEntityLayer(unsigned long id);

        void Update();
    private:
        static PhysicsManager* instanceM;
        std::vector<std::vector<PhysEntity*>> mCollisionLayers;
        // std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)> mLayerMasks[static_cast<unsigned int>(CollisionLayers::MaxLayers)];
        std::vector<std::vector<bool>> mLayerMasks;

        unsigned long mLastID;

        PhysicsManager();
        ~PhysicsManager();
    };

    // inline PhysicsManager::CollisionFlags operator|(PhysicsManager::CollisionFlags a, PhysicsManager::CollisionFlags b)
    // {
    //     return static_cast<PhysicsManager::CollisionFlags>(static_cast<unsigned int>(a) | static_cast<unsigned int>(b));
    // }

    // inline PhysicsManager::CollisionFlags operator &(PhysicsManager::CollisionFlags a, PhysicsManager::CollisionFlags b)
    // {
    //     return static_cast<PhysicsManager::CollisionFlags>(static_cast<unsigned int>(a) & static_cast<unsigned int>(b));
    // }
}