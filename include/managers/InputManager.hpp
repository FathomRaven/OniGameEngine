/*
InputManager class
Handles keyboard input
*/
#pragma once

#include <SDL2/SDL_image.h>
#include <string.h>
#include "MathHelper.hpp"

namespace oni
{
    class InputManager 
    {

    public:
        enum MOUSE_BUTTON {left = 0, right, middle, back, forward};
        
        //@brief Return the InputManager instance
        static InputManager* Instance();
        
        //@brief Release the InputManager instance
        static void Release();

        //TODO: Fully comment all this out

        //@brief Returns if a key is down
        bool KeyDown(SDL_Scancode scanCode);

        //@brief Returns if a key is pressed
        bool KeyPressed(SDL_Scancode scanCode);
        
        //@brief Returns if a key is released
        bool KeyReleased(SDL_Scancode scanCode);

        //@brief Returns if a mouse button is down
        bool MouseButtonDown(MOUSE_BUTTON button);

        //@brief Returns if a mouse button is pressed
        bool MouseButtonPressed(MOUSE_BUTTON button);

        //@brief Returns if a mouse button is released
        bool MouseButtonReleased(MOUSE_BUTTON button);

        //@brief Return the position of the mouse
        Vector2 MousePos();

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
        //Constructor and destructor
        InputManager();
        ~InputManager();
    }; 
}

