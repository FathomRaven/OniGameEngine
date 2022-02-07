#include "Cursor.hpp"

Cursor* Cursor::InstanceM = nullptr;

Cursor* Cursor::Instance()
{
    if(InstanceM == nullptr)
        InstanceM = new Cursor();

    return InstanceM;
}

void Cursor::Release()
{
    delete InstanceM;
    InstanceM = nullptr;
}

Cursor::Cursor()
{
    mInput = InputManager::Instance();

    AddCollider(new BoxCollider(Vector2(30.0f, 30.0f)), Pos());

    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Mouse);
}

Cursor::~Cursor()
{
    mInput = nullptr;
}

void Cursor::Update()
{
    Pos(mInput->MousePos());
    // printf("My Pos: %f\n", Pos().x);
    // printf("Mouse Pos: %f\n", mInput->MousePos().x);
}

void Cursor::Render()
{
    PhysEntity::Render();
}