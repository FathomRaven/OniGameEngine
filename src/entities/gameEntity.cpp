/*
Game entity class, from which all textures are from
*/
#include "GameEntity.hpp"

using namespace oni;

GameEntity::GameEntity(float x, float y)
{
    mPos.x = x;
    mPos.y = y;

    mRotation = 0.0f;

    mActive = true;

    mParent = nullptr;

    mScale = VEC2_ONE;
}

GameEntity::~GameEntity()
{
    mParent = nullptr;
}

void GameEntity::Pos(Vector2 pos)
{
    mPos = pos;
}

Vector2 GameEntity::Pos(SPACE space)
{
    if (space == local || mParent == nullptr)
        return mPos;

    GameEntity* parent = mParent;
    Vector2 finalPos = mPos, parentScale = VEC2_ZERO;

    do
    {
        parentScale = parent->Scale(local);
        finalPos = RotateVector(Vector2(finalPos.x * parentScale.x, finalPos.y * parentScale.y), parent->Rotation(local));
        finalPos += parent->Pos(local);

        parent = parent->Parent();
    } while (parent);
    
    return finalPos;
}

void GameEntity::Rotation(float r)
{
    mRotation = r;
    //Ensures rotation is not above or under 360
    if(mRotation > 360.0f)
        mRotation -= 360.0f;

    if(mRotation < 0.0f)
        mRotation += 360.0f;
}

float GameEntity::Rotation(SPACE space)
{
    if(space == local || mParent == nullptr)
        return mRotation;

    return mParent->Rotation(world) + mRotation;
}

void GameEntity::Scale(Vector2 scale)
{
    mScale = scale;
}

Vector2 GameEntity::Scale(SPACE space)
{
    if(space == local || mParent == nullptr)
        return mScale;

    Vector2 scale = mParent->Scale(world);
    scale.x *= mScale.x;
    scale.y *= mScale.y;

    return scale;
}


void GameEntity::Active(bool active)
{
    mActive = active;
}

bool GameEntity::Active()
{
    return mActive;
}

void GameEntity::Parent(GameEntity* parent) 
{
    if(parent == nullptr)
    {
        mPos = Pos(world);
        mRotation = Rotation(world);
        mScale = Scale(world);
    }
    else
    {
        if(mParent != nullptr)
            Parent(nullptr);

        Vector2 parentScale = parent->Scale(world);

        mPos = RotateVector(Pos(world) - parent->Pos(world), -parent->Rotation(world));
        mPos.x /= parentScale.x;
        mPos.y /= parentScale.y;

        mRotation -= parent->Rotation(world);

        mScale = Vector2(mScale.x / parentScale.x, mScale.y / parentScale.y);
    }

    
    mParent = parent;
}

GameEntity* GameEntity::Parent()
{
    return mParent;
}

void GameEntity::Translate(Vector2 vec)
{
    mPos += vec;
}

void GameEntity::Rotate(float amount)
{
    mRotation += amount;
}

void GameEntity::Update()
{
}

void GameEntity::Render()
{
}