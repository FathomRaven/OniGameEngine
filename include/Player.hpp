#pragma once
#include "PhysEntity.hpp"
#include "Texture.hpp"
#include "InputManager.hpp"
#include "CameraManager.hpp"
#include "Timer.hpp"

class Player : public PhysEntity
{
public:
    Player();
    ~Player();

    void Update();
    void Render();

    void Hit(PhysEntity* other) override;

    Texture* playerTexture;

private:
    //To ignore collisions, define this function
    // bool IgnoreCollisions() override;

    InputManager* mInputMgr;
    CameraManager* mCameraMgr;
    Timer* mTimer;

    float speed;
};