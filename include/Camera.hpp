#pragma once

#include "GameEntity.hpp"
#include "Graphics.hpp"

class Camera : public GameEntity
{
public:
    Camera(Vector2 _pos);
    ~Camera();

    Vector2 cameraSize;
};