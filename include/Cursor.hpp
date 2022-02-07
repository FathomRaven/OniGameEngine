#pragma once

#include "PhysEntity.hpp"
#include "InputManager.hpp"
#include "PhysicsManager.hpp"
#include "BoxCollider.hpp"

class Cursor : public PhysEntity
{    
public:
    static Cursor* Instance();
    static void Release();

    Cursor();
    ~Cursor();

    void Update();
    void Render();
private:
    static Cursor* InstanceM;

    InputManager* mInput;
};