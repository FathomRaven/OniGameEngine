#include "PhysEntity.hpp"
#include "PhysicsHelper.hpp"
#include "PhysicsManager.hpp"

using namespace oni;

PhysEntity::PhysEntity()
{
    mBroadPhaseCollider = nullptr;
    mID = 0;
}

PhysEntity::~PhysEntity()
{
    for (int i = 0; i < (int)mColliders.size(); i++)
    {
        delete mColliders[i];
        mColliders[i] = nullptr;
    }
    
    mColliders.clear();

    if(mBroadPhaseCollider)
    {
        delete mBroadPhaseCollider;
        mBroadPhaseCollider = nullptr;
    }

    if(mID != 0)
    {
        PhysicsManager::Instance()->UnregisterEntity(mID);
    }
}
//Set and get mID
unsigned long PhysEntity::GetID()
{
    return mID;
}

void PhysEntity::SetID(unsigned long ID)
{
    mID = ID;
}

bool PhysEntity::CheckCollision(PhysEntity* other)
{
    if(IgnoreCollisions() || other->IgnoreCollisions())
        return false;
    //Check to see if broadPhase colliders are colliding. If so, move on to narrow check
    bool narrowPhaseCheck = false;
    if(mBroadPhaseCollider && other->mBroadPhaseCollider)
    {
        narrowPhaseCheck = ColliderColliderCheck(mBroadPhaseCollider, other->mBroadPhaseCollider);
    }
    else
    {
        narrowPhaseCheck = true;
    }
    bool returnValue = false;
    if(narrowPhaseCheck)
    {
        for (int i = 0; i < (int)mColliders.size(); i++)
        {
            for (int j = 0; j < (int)other->mColliders.size(); j++)
            {
                if(ColliderColliderCheck(mColliders[i], other->mColliders[j]))
                {
                    if(!fullCheck && !other->fullCheck)
                    {
                        Hit(other);
                        other->Hit(this);
                        return true;
                    }

                    Hit(other, i);
                    other->Hit(this, j);

                    returnValue = true;
                }
            }
        }
    }
    if(!fullCheck)
        return false;
    
    return returnValue;
}

void PhysEntity::Hit(PhysEntity* other, int collliderIndex)
{
}

bool PhysEntity::IgnoreCollisions()
{
    return false;
}

void PhysEntity::AddCollider(Collider* collider, Vector2 localPos)
{
    collider->Parent(this);
    collider->Pos(localPos);
    mColliders.push_back(collider);
    //If there isn't a circle collider, set broadphase collider
    if(mColliders.size() > 1 || mColliders[0]->GetType() != Collider::ColliderType::Circle)
    {
        float furthestDist = mColliders[0]->GetFurthestPoint().Magnitude();
        float dist = 0.0f;
        for (int i = 0; i < (int)mColliders.size(); i++)
        {
            dist = mColliders[i]->GetFurthestPoint().Magnitude();
            if(dist > furthestDist)
            {
                furthestDist = dist;
            }
        }
        
        delete mBroadPhaseCollider;
        mBroadPhaseCollider = new CircleCollider(furthestDist, true);
        mBroadPhaseCollider->Parent(this);
        mBroadPhaseCollider->Pos(VEC2_ZERO);
    }
}

void PhysEntity::Render()
{
    for (int i = 0; i < (int)mColliders.size(); i++)
    {
        mColliders[i]->Render();
    }

    if(mBroadPhaseCollider)
        mBroadPhaseCollider->Render();
}