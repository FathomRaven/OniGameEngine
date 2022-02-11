/*
InputManager class
Handles keyboard input
*/
#pragma once

#include <SDL2/SDL_image.h>
#include <string.h>
#include "MathHelper.hpp"

class InputManager 
{

public:
    enum MOUSE_BUTTON {left = 0, right, middle, back, forward};
    
     //Instance methods
    static InputManager* Instance();
    static void Release();
    //If a key is down
    bool KeyDown(SDL_Scancode scanCode);
    bool KeyPressed(SDL_Scancode scanCode);
    bool KeyReleased(SDL_Scancode scanCode);

    bool MouseButtonDown(MOUSE_BUTTON button);
    bool MouseButtonPressed(MOUSE_BUTTON button);
    bool MouseButtonReleased(MOUSE_BUTTON button);

    Vector2 MousePos();

    //Update
    void Update();
    void UpdatePrevInput();

private:
    

    //Instance
    static InputManager* sInstance;

    Uint8* mPrevKeyboardState;
    //KeyboardStates
    const Uint8* mKeyboardState;
    int mKeyLength;

    Uint32 mPrevMouseState;
    Uint32 mMouseState;

    int mMouseXPos;
    int mMouseYPos;

    //-----
    //Constructer and destructor
    InputManager();
    ~InputManager();
};