/*
Timer class. Used for keeping track of time, and deltaTime
*/
#pragma once
#include <SDL2/SDL_image.h>

namespace oni
{
    class Timer {
    public:
        //Singleton instance methods
        static Timer* Instance();
        static void Release();
        //DeltaTime getter, and reset method
        void Reset();
        float DeltaTime();
        //Sets and gets the timeScale
        void TimeScale(float t);
        float TimeScale();
        //Update method
        void Update();

    private:
        static Timer* sInstance; //Instance
        //Various variables
        unsigned int mStartTicks; //The amount of ticks at start
        unsigned int mElapsedTicks; //The amount of ticks since startTicks
        float mDeltaTime;
        float mTimeScale;

        Timer();
        ~Timer();
    }; 
}