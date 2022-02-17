#include "GameManager.hpp"
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

//! Add in a way for individual colliders to detect what layer they are colliding with
//! Occasional odd collision
    //? More info needed
//Improve comments
    /*
    Some poor wording throughout
    Add in param info
    Spell checking
    
    Still need to comment:
    Cursor
    */
//// Particle engine
//// Camera zooming

int main(int argc, char ** argv){

    //Make a gamemanager instance
    GameManager* game = GameManager::Instance();
    
    Texture* testText = new Texture("Simpleplayer.png");
    testText->Pos(Vector2(300.0f, 300.0f));

    Button* mButton = new Button("BoxCollider.png", "Press me", "test.ttf", 16, {0, 0, 0, 255}, true);
    mButton->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH/2, 800.0f));

    game->AddToRenders(testText);
    game->AddToRenders(mButton);

    game->AddToUpdates(mButton);

    //Run the game loop
    while (!game->Run())
    {
        if(game->FrameLimit())
        {
            game->EarlyUpdate();
            game->Update();


            game->LateUpdate();

            game->Render();
        }
    }

    //Clean up gameManager
    GameManager::Release();
    game = nullptr;

    return 0;
}