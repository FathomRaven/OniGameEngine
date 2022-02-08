#include "GameManager.hpp"

//TODO:
//Particle engine
//Camera zooming

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