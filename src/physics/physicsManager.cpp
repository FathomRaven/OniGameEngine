#include "PhysicsManager.hpp"

using namespace oni;

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

void PhysicsManager::SetLayerCollisionMask(std::string layer, std::string flag)
{
    if(layer == flag)
        printf("Error: Layer mask set to be collide with itself");
    
    mLayerMasks[colliderLayers[layer]][colliderLayers[flag]] = true;
    mLayerMasks[colliderLayers[flag]][colliderLayers[layer]] = true;
}

unsigned long PhysicsManager::RegisterEntity(PhysEntity* entity, std::string layer)
{
    mCollisionLayers[colliderLayers[layer]].push_back(entity);
    mLastID++;
    return mLastID;
}

void PhysicsManager::UnregisterEntity(unsigned long id)
{
    bool found = false;
    for (int i = 0; i < (int)colliderLayers.size() && !found; i++)
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
    for (int i = 0; i < (int)colliderLayers.size() && !found; i++)
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
    colliderLayers = Settings::Instance()->collisionLayers;
    
    mLastID = 0;

    for (size_t i = 0; i < colliderLayers.size(); i++)
    {
        mCollisionLayers.push_back({});
    }
    
    for (int i = 0; i < (int)colliderLayers.size(); i++)
    {
        mLayerMasks.push_back({});
        for (int j = 0; j < (int)colliderLayers.size(); j++)
        {
            mLayerMasks[i].push_back(false);
        }
        
    }
    
}

PhysicsManager::~PhysicsManager()
{
    for (unsigned int i = 0; i < colliderLayers.size(); i++)
    {
        mCollisionLayers[i].clear();
    }

    for (unsigned int i = 0; i < colliderLayers.size(); i++)
    {
        mLayerMasks[i].clear();
    }
}

void PhysicsManager::Update()
{
    for (unsigned int i = 0; i < colliderLayers.size(); i++)
    {
        for (unsigned int j = 0; j < colliderLayers.size(); j++)
        {
            // printf(mLayerMasks[i][j] == true && i <= j ? "true\n" : "");

            if(mLayerMasks[i][j] == true && i <= j)
            {
                for(unsigned int k = 0; k < mCollisionLayers[i].size(); k++)
                {
                    for (unsigned int l = 0; l < mCollisionLayers[j].size(); l++)
                    {
                        mCollisionLayers[i][k]->CheckCollision(mCollisionLayers[j][l]);
                        // printf(mCollisionLayers[i][k]->CheckCollision(mCollisionLayers[j][l]) ? "true" : "");
                    }
                }
            }
        }
    }
}