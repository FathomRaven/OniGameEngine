/*
Manager to keep track of cameras
*/

#pragma once

#include "Camera.hpp"
#include <vector>

namespace oni
{
    class CameraManager
    {
    public:
        //@brief Return the CameraManager instance
        static CameraManager* Instance();
        
        //@brief Release the CameraManager instance
        static void Release();
        
        /**
         * @brief Add a camera to the CameraManagers list of cameras
         * @param pos Position of the new camera, set to 0, 0 by default 
        */
        void AddCamera(Vector2 pos = Vector2(0.0f, 0.0f));
        
        /**
         * @brief Set the CameraManagers active camera
         * @param index Index of the camera to be set as active 
        */
        void SetActiveCamera(int index);

        //The camera everything is rendering through
        Camera* activeCamera;

    private:
        CameraManager();
        ~CameraManager();

        static CameraManager* InstanceM;
        std::vector<Camera*> cameras;
    };
}