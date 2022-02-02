/*
GameManager singleton class. Handles most the main game loop
*/
#pragma once

#include "AudioManager.hpp"
#include "InputManager.hpp"
#include "AnimatedTexture.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "CameraManager.hpp"
#include "PhysicsManager.hpp"

class GameManager{
public:    
    //Instance stuff
    
    static GameManager* Instance();
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
    //Various mgrs
    Graphics* mGraphics;
    AssetManager* mAssetMgr;
    InputManager* mInputMgr;
    AudioManager* mAudioMgr;
    CameraManager* cameraMgr;
    PhysicsManager* physMgr;
    //Timer
    Timer* mTimer;
    //Different events
    SDL_Event mEvents;

    Player* playerOne;
    Tile* tile1;

    //Construct and destruct

    GameManager();
    ~GameManager();

    void EarlyUpdate();
    void Update();
    void LateUpdate();

    void Render();
};