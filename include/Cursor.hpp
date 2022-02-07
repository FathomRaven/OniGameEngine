#pragma once

#include "PhysEntity.hpp"
#include "InputManager.hpp"
#include "PhysicsManager.hpp"
#include "BoxCollider.hpp"

class Cursor : public PhysEntity
{    
public:
    Cursor();
    ~Cursor();

    void Update();
    void Render();
private:
    InputManager* mInput;
};