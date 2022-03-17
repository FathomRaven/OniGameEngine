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
        //The collision layers
        std::map<std::string, int> colliderLayers;

        //@brief Return the PhysicsManager instance
        static PhysicsManager* Instance();
        
        //@brief Release the PhysicsManager instance
        static void Release();

        /**
         * @brief Designate two collision layers to collide with each other
         * @param layer First collision layer in the mask
         * @param flag Second collision layer in the mask 
        */
        void SetLayerCollisionMask(std::string layer, std::string flag);

        /**
         * @brief Register a PhysicsEntity in a collider layer
         * @param entity PhysicsEntity to be registered 
         * @param layer Name of the layer for the entity to be registered in
         * @return The ID of the newly registed entity 
        */
        unsigned long RegisterEntity(PhysEntity* entity, std::string layer);
        
        /**
         * @brief Unregister a PhysicsEntity from its layer
         * @param id The ID of the PhysicsEntity
        */
        void UnregisterEntity(unsigned long id);

        //TODO: Replace this function. Ideally, should switch over to using a struct for layers
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