/*
Timer class. Used for keeping track of time, and deltaTime
*/
#pragma once
#include <SDL2/SDL_image.h>

namespace oni
{
    class Timer {
    public:
        //@brief Return the Timer instance
        static Timer* Instance();
        
        //@brief Release the Timer instance
        static void Release();

        //@brief Reset the deltaTime
        void Reset();

        //@brief Return the deltaTime
        float DeltaTime();
        
        /**
         * @brief set the TimeScale
         * @param t Value to set the timescale to 
        */
        void TimeScale(float t);

        //@brief Return the current TimeScale
        float TimeScale();
        
        //Update the timer
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