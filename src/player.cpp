#include "Player.hpp"
#include "BoxCollider.hpp"
#include "PhysicsManager.hpp"

Player::Player()
{
    ClearHits();
    mInputMgr = InputManager::Instance();
    mCameraMgr = CameraManager::Instance();
    
    fullCheck = true;

    playerTexture = new Texture("Simpleplayer.png");
    playerTexture->Parent(this);

    Vector2 tScale = playerTexture->ScaledDimemsions();

    AddCollider(new BoxCollider(Vector2(tScale.x - 1, 1.0f)), Vector2(0.0f, -tScale.y/2));
    AddCollider(new BoxCollider(Vector2(tScale.x - 1, 1.0f)), Vector2(0.0f, tScale.y/2));

    AddCollider(new BoxCollider(Vector2(1.0f, tScale.y - 1)), Vector2(-tScale.x/2, 0.0f));
    AddCollider(new BoxCollider(Vector2(1.0f, tScale.y - 1)), Vector2(tScale.x/2, 0.0f));

    AddCollider(new BoxCollider(Vector2(tScale.x -1, tScale.y - 1)));

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
}

void Player::Update()
{
    if(mInputMgr->KeyDown(SDL_SCANCODE_UP) && !GetColliderHit(0))
    {
        Translate(Vector2(0.0f, -5.0f));  
        mCameraMgr->activeCamera->Translate(Vector2(0.0f, -5.0f));
    }
    if(mInputMgr->KeyDown(SDL_SCANCODE_DOWN) && !GetColliderHit(1))
    {
        Translate(Vector2(0.0f, 5.0f));
        mCameraMgr->activeCamera->Translate(Vector2(0.0f, 5.0f));
    }
    if(mInputMgr->KeyDown(SDL_SCANCODE_LEFT) && !GetColliderHit(2))
    {
        Translate(Vector2(-5.0f, 0.0f));
        mCameraMgr->activeCamera->Translate(Vector2(-5.0f, 0.0f));
    }
    if(mInputMgr->KeyDown(SDL_SCANCODE_RIGHT) && !GetColliderHit(3))
    {
        Translate(Vector2(5.0f, 0.0f));
        mCameraMgr->activeCamera->Translate(Vector2(5.0f, 0.0f));
    }

    // if(GetColliderHit(0))
    //     printf("top\n");
    // if(GetColliderHit(1))
    //     printf("bottom\n");
    // if(GetColliderHit(2))
    //     printf("left\n");
    // if(GetColliderHit(3))
    //     printf("right\n");

    ClearHits();
}

void Player::Render()
{
    playerTexture->Render();
    
    PhysEntity::Render();
}