#include "Tile.hpp"
#include "BoxCollider.hpp"
#include "PhysicsManager.hpp"

Tile::Tile()
{
    tileTexture = new Texture("basicBlock.png");
    tileTexture->Parent(this);

    AddCollider(new BoxCollider(tileTexture->ScaledDimemsions()));

    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Tile);
}

Tile::~Tile()
{
    delete tileTexture;
    tileTexture = nullptr;
}

void Tile::Hit(PhysEntity* other)
{
    printf("hit");
}

void Tile::Update()
{

}

void Tile::Render()
{
    tileTexture->Render();
    
    PhysEntity::Render();
}