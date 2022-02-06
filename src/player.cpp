#include "Player.hpp"
#include "BoxCollider.hpp"
#include "PhysicsManager.hpp"

Player::Player()
{
    ClearHits();
    mInputMgr = InputManager::Instance();
    mCameraMgr = CameraManager::Instance();
    mTimer = Timer::Instance();
    
    fullCheck = true;

    speed = 5.0f;

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
    mCameraMgr = nullptr;
    mTimer = nullptr;
}

void Player::Hit(PhysEntity* other)
{
}

void Player::Update()
{
    if(mInputMgr->KeyDown(SDL_SCANCODE_UP) && !GetColliderHit(0))
    {
        Translate(VEC2_UP * speed);  
    }
    if(mInputMgr->KeyDown(SDL_SCANCODE_DOWN) && !GetColliderHit(1))
    {
        Translate(VEC2_DOWN * speed);
    }
    if(mInputMgr->KeyDown(SDL_SCANCODE_LEFT) && !GetColliderHit(2))
    {
        Translate(VEC2_LEFT * speed);
    }
    if(mInputMgr->KeyDown(SDL_SCANCODE_RIGHT) && !GetColliderHit(3))
    {
        Translate(VEC2_RIGHT * speed);
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