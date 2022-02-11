#include "Camera.hpp"

Camera::Camera(Vector2 _pos)
    :GameEntity()
{    
    Pos(_pos);
    Active(false);

    cameraSize.x = Graphics::Instance()->SCREEN_WIDTH;
    cameraSize.y = Graphics::Instance()->SCREEN_HEIGHT;
}

Camera::~Camera()
{

}