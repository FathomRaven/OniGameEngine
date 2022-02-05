#include "Player.hpp"
#include "BoxCollider.hpp"
#include "PhysicsManager.hpp"

Player::Player()
{
    mInputMgr = InputManager::Instance();
    
    playerTexture = new Texture("Simpleplayer.png");
    playerTexture->Parent(this);

    AddCollider(new BoxCollider(playerTexture->ScaledDimemsions()));

    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);
}

Player::~Player()
{
    delete playerTexture;
    playerTexture = nullptr;

    mInputMgr = nullptr;
}

void Player::Hit(PhysEntity* other)
{
    printf("hit");
}

void Player::Update()
{
    if(mInputMgr->KeyDown(SDL_SCANCODE_UP))
        Translate(Vector2(0.0f, -5.0f));
    if(mInputMgr->KeyDown(SDL_SCANCODE_DOWN))
        Translate(Vector2(0.0f, 5.0f));
    if(mInputMgr->KeyDown(SDL_SCANCODE_LEFT))
        Translate(Vector2(-5.0f, 0.0f));
    if(mInputMgr->KeyDown(SDL_SCANCODE_RIGHT))
        Translate(Vector2(5.0f, 0.0f));
}

void Player::Render()
{
    playerTexture->Render();
    
    PhysEntity::Render();
}