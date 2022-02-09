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
Terminolgy: 
! Means error
// Meanings it's being ignored for now
* Is worked on
This all works best with VSCode bettercomments extension
*/

//! Add in a way for individual colliders to detect what layer they are colliding with
//! Occasional odd collision
    //? More info needed
//// Particle engine
//// Camera zooming

int shutup(int argc )
{
    return argc;
}

char ** shutup(char ** argv)
{
    return argv;
}

int main(int argc, char ** argv){

    //Make a gamemanager instance
    GameManager* game = GameManager::Instance();

    //Run the game loop
    game->Run();

    //Clean up gamemanager
    GameManager::Release();
    game = nullptr;

    shutup(argc);
    shutup(argv);

    return 0;
}