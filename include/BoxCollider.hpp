#pragma once
#include "Collider.hpp"

class BoxCollider : public Collider
{    
public:
    BoxCollider(Vector2 size);
    ~BoxCollider();

private:
    static const int MAX_VERTS = 4;

    GameEntity* mVerts[MAX_VERTS];

    void AddVert(int index, Vector2 pos);
};