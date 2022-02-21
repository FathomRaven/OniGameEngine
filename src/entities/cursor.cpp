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

    AddCollider(new BoxCollider(Vector2(3.0f, 3.0f)), Pos());

    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Mouse);
}

Cursor::~Cursor()
{
    mInput = nullptr;
}

void Cursor::Update()
{
    //Constantly put the cursor at the mouse position
    Pos(mInput->MousePos());
}

void Cursor::Render()
{
    PhysEntity::Render();
}