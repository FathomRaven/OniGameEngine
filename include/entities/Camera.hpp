/*
Rudimentary Camera Class
*/

#pragma once

#include "GameEntity.hpp"
#include "Graphics.hpp"

namespace oni
{
    class Camera : public GameEntity
    {
    public:
        Camera(Vector2 _pos);
        ~Camera();

        Vector2 cameraSize;
    };
}