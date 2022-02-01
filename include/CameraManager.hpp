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

    Camera* activeCamera;

private:
    static CameraManager* InstanceM;
    
    std::vector<Camera*> cameras;
    
};