#include "PhysicsManager.hpp"

PhysicsManager* PhysicsManager::instanceM = nullptr;

PhysicsManager* PhysicsManager::Instance()
{
    if (instanceM == nullptr)
    instanceM = new PhysicsManager();
    
    return instanceM;
}

void PhysicsManager::Release()
{
    delete instanceM;
    instanceM = nullptr;
}

void PhysicsManager::SetLayerCollisionMask(CollisionLayers layer, CollisionFlags flags)
{
    mLayerMasks[static_cast<unsigned int>(layer)] = std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)>(static_cast<unsigned int>(flags));
}

unsigned long PhysicsManager::RegisterEntity(PhysEntity* entity, CollisionLayers layer)
{
    mCollisionLayers[static_cast<unsigned int>(layer)].push_back(entity);

    mLastID++;
    return mLastID;
}

void PhysicsManager::UnregisterEntity(unsigned long id)
{
    bool found = false;
    for (int i = 0; i < (int)static_cast<unsigned int>(CollisionLayers::MaxLayers) && !found; i++)
    {
        for (int j = 0; j < (int)mCollisionLayers[i].size() && !found; j++)
        {
            if(mCollisionLayers[i][j]->GetID() == id)
            {
                mCollisionLayers[i].erase(mCollisionLayers[i].begin() + j);
                found = true;
            }
        }
    }
}

int PhysicsManager::GetEntityLayer(unsigned long id)
{
    bool found = false;
    for (int i = 0; i < (int)static_cast<unsigned int>(CollisionLayers::MaxLayers) && !found; i++)
    {
        for (int j = 0; j < (int)mCollisionLayers[i].size() && !found; j++)
        {
            if(mCollisionLayers[i][j]->GetID() == id)
            {
                found = true;
                return i;
            }
        }
    }

    return 0;
}

PhysicsManager::PhysicsManager()
{
    mLastID = 0;

    for (unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); i++)
    {
        mLayerMasks[i] = std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)>(static_cast<unsigned int>(CollisionFlags::None));
    }
    
}

PhysicsManager::~PhysicsManager()
{
    for (unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); i++)
    {
        mCollisionLayers[i].clear();
    }
}

void PhysicsManager::Update()
{
    for (unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); i++)
    {
        for (unsigned int j = 0; j < static_cast<unsigned int>(CollisionLayers::MaxLayers); j++)
        {
            if(mLayerMasks[i].test(j) && i <= j)
            {
                for(unsigned int k = 0; k < mCollisionLayers[i].size(); k++)
                {
                    for (unsigned int l = 0; l < mCollisionLayers[j].size(); l++)
                    {
                        mCollisionLayers[i][k]->CheckCollision(mCollisionLayers[j][l]);
                    }
                }
            }
        }
    }
}