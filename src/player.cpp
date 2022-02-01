#include "Player.hpp"
#include "BoxCollider.hpp"

Player::Player()
{
    playerTexture = new Texture("Simpleplayer.png");
    playerTexture->Parent(this);

    AddCollider(new BoxCollider(playerTexture->ScaledDimemsions()));
}

Player::~Player()
{
    delete playerTexture;
    playerTexture = nullptr;
}

void Player::Update()
{

}

void Player::Render()
{
    playerTexture->Render();
    
    PhysEntity::Render();
}