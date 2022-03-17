/*
Box collider class

A collider, in the shape of a box! Truly amazing
*/

#pragma once
#include "Collider.hpp"

namespace oni
{
        class BoxCollider : public Collider
    {    
    public:
        BoxCollider(Vector2 size);
        ~BoxCollider();
        
        //@brief Get the furthest point of the box collider
        Vector2 GetFurthestPoint() override;

        //@brief Vertex getter
        Vector2 GetVertexPos(int index);

    private:
        //Vertices of the box
        static const int MAX_VERTS = 4;

        GameEntity* mVerts[MAX_VERTS];

        void AddVert(int index, Vector2 pos);
    };
}