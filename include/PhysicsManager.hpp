#pragma once 

#include "PhysEntity.hpp"
#include <bitset>

class PhysicsManager
{
public:

    enum class CollisionLayers
    {
        Friendly = 0,
        Tile,
        UI,
        Mouse,
        //-------------------------------------
        MaxLayers
    };

    enum class CollisionFlags
    {
        None = 0x00,
        Friendly = 0x01,
        Tile = 0x02,
        UI = 0x04,
        Mouse = 0x08
    };

    static PhysicsManager* Instance();
    static void Release();

    void SetLayerCollisionMask(CollisionLayers layer, CollisionFlags flags);

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