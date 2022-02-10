#pragma once
#include "AssetManager.hpp"

class AudioManager 
{
public:
    //Singleton instance and release functions

    static AudioManager* Instance(); //Get the instance
    static void Release(); //Release instance
    //Play a .wav file as music 
    //@param filename the name of the .wav file to play 
    //@param loops the amount of times to loop the music, set to -1 as default
    //@param volume set the volume to play the music at
    void PlayMusic(std::string filename, int loops = -1, int volume = 128);
    
    void PauseMusic(); //Pause any music playing
    void ResumeMusic(); //Resume any music playing
    
    //Play A .wav file as a sound effect 
    //@param filename the name of the file to play 
    //@param volume the volume of the sound effect
    //@parma loops how many times to loop it, set to 0 as default
    //@param channel the channel to play the music in
    void PlaySFX(std::string filename, int volume = 128, int loops = 0, int channel = 0);

private:

    static AudioManager* sInstance; //Singleton instance

    AssetManager* mAssetMgr; //AssetManager instance

    AudioManager();
    ~AudioManager();
};