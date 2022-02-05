#pragma once
#include "PhysEntity.hpp"
#include "Texture.hpp"

class Tile : public PhysEntity
{
public:
    Tile();
    ~Tile();

    void Update();
    void Render();
    void RenderStatic();

    void Hit(PhysEntity* other) override;

    Texture* tileTexture;
};