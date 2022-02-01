#include "CameraManager.hpp"

CameraManager* CameraManager::InstanceM = nullptr;

CameraManager* CameraManager::Instance()
{
    if(InstanceM == nullptr)
        InstanceM = new CameraManager();

    return InstanceM;
}

void CameraManager::Release()
{
    delete InstanceM;
    InstanceM = nullptr;
}

CameraManager::CameraManager()
{
    activeCamera = nullptr;
}

CameraManager::~CameraManager()
{

    for (int i = 0; i < (int)cameras.size(); i++)
    {
        delete cameras[i];
        cameras[i] = nullptr;
    }
    
    cameras.clear();
}

void CameraManager::AddCamera(Vector2 pos)
{
    cameras.push_back(new Camera(pos));
}

void CameraManager::SetActiveCamera(int index)
{
    if(index > (int)cameras.size())
        return;
    if(activeCamera != nullptr)
        activeCamera->Active(false);

    activeCamera = cameras[index];
    activeCamera->Active(true);
}
