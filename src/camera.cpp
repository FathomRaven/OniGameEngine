#include "Camera.hpp"

Camera::Camera(Vector2 _pos)
    :GameEntity()
{    
    Pos(_pos);
    Active(false);
}

Camera::~Camera()
{

}
