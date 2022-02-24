#include "GameManager.hpp"

using namespace oni;
/*
# -------------------
#   Oni Game Engine 
# -------------------
#
# Credit to Ather Omar for the base engine
#
# Use:
# Create instances of singletons in GameManager
# Update and render them in GameManager's loop
# Can also create objects
#
# GameEntity is the base class from which all other entities inherit
# Can be parented to another GameEntity
# Has local and world pos, rotation, and scale
# Local is the exact space on the screen, world is space according to parents
#
# PhysEntity is an GameEntity with collisions
# Can have box or circle colliders
#
# Texture is a GameEntity that renders as a SDL_Texture
# Can be a texture or text 
#
# AnimatedTexture is a texture that uses a spritesheet to create an animation
# Inherits from texture
#
# Cursor is a simple entity that is always at the mouse position, used for collisions
#
# Cameras are simple GameEntities that can be set to be the active camera with the cameramanager
# All textures are rendered in respect to the active cameras position
#
# Buttons are modified textures that collide with the cursor
#
*/



//TODO:
/*
Terminology: 
! Means error
// Meanings it's being ignored for now
* Is worked on
This all works best with VSCode bettercomments extension
*/

//Docs

//! Occasional odd collision
    //? More info needed
//AnimatorState
//Random class
//Improve comments
    /*
    Some poor wording throughout
    Add in param info
    Spell checking
    */
//// Particle engine
//// Camera zooming

int main(int argc, char ** argv){

    //Make a gamemanager instance
    GameManager* game = GameManager::Instance("Example of Oni Engine", 1024, 896, {255, 255, 255, 255});

    Texture* mPlayer;
    mPlayer = new Texture("Simpleplayer.png");
    mPlayer->Pos(Vector2(500.0f, 500.0f));

    game->AddToRenders(mPlayer);

    //Run the game loop
    while (!game->Run())
    {
        if(game->FrameLimit())
        {
            game->EarlyUpdate();
            game->Update();

            if(InputManager::Instance()->KeyDown(SDL_SCANCODE_DOWN))
                mPlayer->Translate(VEC2_DOWN*5.0f);
            if(InputManager::Instance()->KeyDown(SDL_SCANCODE_LEFT))
                mPlayer->Translate(VEC2_LEFT*5.0f);
            if(InputManager::Instance()->KeyDown(SDL_SCANCODE_RIGHT))
                mPlayer->Translate(VEC2_RIGHT*5.0f);
            if(InputManager::Instance()->KeyDown(SDL_SCANCODE_UP))
                mPlayer->Translate(VEC2_UP*5.0f);

            game->LateUpdate();
            game->Render();
        }
    }

    //Clean up gameManager
    GameManager::Release();
    game = nullptr;

    return 0;
}