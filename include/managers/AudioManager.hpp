#pragma once
#include "AssetManager.hpp"

namespace oni
{
class AudioManager 
{
public:
    
    //@brief Return the singleton instance
    static AudioManager* Instance(); 
    //@brief Release the singleton instance
    static void Release();
    /**
     * @brief Play music through the AudioManager
     * @param filename Name of the .wav file to play
     * @param loops Amount of times to loop the music, default set to -1, which loops forever
     * @param volume Volume to play the music at  
    */
    void PlayMusic(std::string filename, int loops = -1, int volume = 128);
    
    void PauseMusic();
    void ResumeMusic();
    
    /**
     * @brief Play a sound effect through the AudioManager
     * @param filename Name of the .wav file to play
     * @param volume Volume to play the sound effect at
     * @param loops Amount of times to loop the sound effect, default set to 0
     * @param channel Sound channel to play the sound effect in
    */
    void PlaySFX(std::string filename, int volume = 128, int loops = 0, int channel = 0);

private:

    static AudioManager* sInstance;

    AssetManager* mAssetMgr;
    
    AudioManager();
    ~AudioManager();
};
}