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
    CameraMgr
    Cursor
    */
//// Particle engine
//// Camera zooming

int main(int argc, char ** argv){

    //Make a gamemanager instance
    GameManager* game = GameManager::Instance();

    //Run the game loop
    game->Run();

    //Clean up gameManager
    GameManager::Release();
    game = nullptr;

    return 0;
}