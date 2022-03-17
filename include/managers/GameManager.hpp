/*
GameManager singleton class. Handles most the main game loop
*/
#pragma once

#include "AudioManager.hpp"
#include "AnimatedTexture.hpp"
#include "Button.hpp"

namespace oni
{
    class GameManager{
    public:    
        
        //@brief Return the GameManager instance
        static GameManager* Instance();
        //@brief Release the GameManager instance
        static void Release();
        //Run loop
        bool Run();

        bool FrameLimit();
        
        /**
         * @brief Add an entity to be rendered every frame
         * @param entity Entity to be added 
        */
        void AddToRenders(GameEntity* entity);

        /**
         * @brief Add an entity to be updated every frame
         * @param entity Entity to be added 
        */
        void AddToUpdates(GameEntity* entity);

        void EarlyUpdate();
        void Update();
        void LateUpdate();

        void Render();
    private:
        //Instance 
        static GameManager* sInstance;
        //The framerate to keep the game at
        const int FRAME_RATE = 60;
        //If quit yet
        bool mQuit;
        //Various Managers
        Graphics* mGraphics;
        AssetManager* mAssetMgr;
        InputManager* mInputMgr;
        AudioManager* mAudioMgr;
        CameraManager* cameraMgr;
        PhysicsManager* physMgr;
        //Timer
        Timer* mTimer;
        
        Cursor* mCursor;

        SDL_Event mEvents;

        std::vector<GameEntity*> mEntityRender;
        std::vector<GameEntity*> mEntityUpdate;

        GameManager();
        ~GameManager();
    };
};