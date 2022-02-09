/*
Singleton PhysicsManager class

Handles the collision interaction between two entities

From this point onward, I dunno much about the code here as it's based from online. Bad practice, I know, but I also kinda don't care
I should care
*/

#pragma once 

#include "PhysEntity.hpp"
#include <bitset>

class PhysicsManager
{
public:
    //Layers
    enum class CollisionLayers
    {
        Friendly = 0,
        Stationary,
        UI,
        Mouse,
        //-------------------------------------
        MaxLayers
    };
    //Flags
    enum class CollisionFlags
    {
        None = 0x00,
        Friendly = 0x01,
        Stationary = 0x02,
        UI = 0x04,
        Mouse = 0x08
    };
    //Singleton Stuff
    static PhysicsManager* Instance();
    static void Release();
    //Set collision mask between a layer and a flag
    void SetLayerCollisionMask(CollisionLayers layer, CollisionFlags flags);
    //Register Entity
    unsigned long RegisterEntity(PhysEntity* entity, CollisionLayers layer);
    void UnregisterEntity(unsigned long id);

    void Update();

private:

    static PhysicsManager* instanceM;
    std::vector<PhysEntity*> mCollisionLayers[static_cast<unsigned int>(CollisionLayers::MaxLayers)];
    std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)> mLayerMasks[static_cast<unsigned int>(CollisionLayers::MaxLayers)];

    unsigned long mLastID;

    PhysicsManager();
    ~PhysicsManager();
};

inline PhysicsManager::CollisionFlags operator|(PhysicsManager::CollisionFlags a, PhysicsManager::CollisionFlags b)
{
    return static_cast<PhysicsManager::CollisionFlags>(static_cast<unsigned int>(a) | static_cast<unsigned int>(b));
}

inline PhysicsManager::CollisionFlags operator &(PhysicsManager::CollisionFlags a, PhysicsManager::CollisionFlags b)
{
    return static_cast<PhysicsManager::CollisionFlags>(static_cast<unsigned int>(a) & static_cast<unsigned int>(b));
}