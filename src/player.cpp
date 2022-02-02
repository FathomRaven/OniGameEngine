#include "Player.hpp"
#include "BoxCollider.hpp"
#include "PhysicsManager.hpp"

Player::Player()
{
    playerTexture = new Texture("Simpleplayer.png");
    playerTexture->Parent(this);

    AddCollider(new BoxCollider(playerTexture->ScaledDimemsions()));

    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);
}

Player::~Player()
{
    delete playerTexture;
    playerTexture = nullptr;
}

void Player::Hit(PhysEntity* other)
{
    printf("hit");
}

void Player::Update()
{

}

void Player::Render()
{
    playerTexture->Render();
    
    PhysEntity::Render();
}