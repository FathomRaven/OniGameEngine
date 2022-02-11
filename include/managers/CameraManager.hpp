/*
Manager to keep track of cameras
*/

#pragma once

#include "Camera.hpp"
#include <vector>

class CameraManager
{
public:
    static CameraManager* Instance();
    static void Release();
    
    CameraManager();
    ~CameraManager();

    void AddCamera(Vector2 pos = Vector2(0.0f, 0.0f));
    void SetActiveCamera(int index);
    //The camera everything in rendering in respect to
    Camera* activeCamera;

private:
    static CameraManager* InstanceM;
    //Vector of all cameras
    std::vector<Camera*> cameras;
};