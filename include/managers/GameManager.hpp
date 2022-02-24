/*
GameManager singleton class. Handles most the main game loop
*/
#pragma once

#include "AudioManager.hpp"
#include "AnimatedTexture.hpp"
#include "Button.hpp"

namespace oni{

    class GameManager{
    public:    
        //Instance stuff
        
        static GameManager* Instance(std::string winTitle = "Oni Engine", int winWidth = 1024, int winHeight = 1024, SDL_Color winColor = {255, 255, 255, 255});
        static void Release();
        //Run loop
        void Run();

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

        //Different events
        SDL_Event mEvents;

        //! Example code below

        AnimatedTexture* mPlayer;
        Texture* mText;
        Texture* mExplainText;
        Button* mButton;

        //Construct and destruct

        GameManager(std::string winTitle, int winWidth, int winHeight, SDL_Color winColor = {255, 255, 255, 255});
        ~GameManager();

        void EarlyUpdate();
        void Update();
        void LateUpdate();

        void Render();
    };  
}