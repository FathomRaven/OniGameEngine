#include "Timer.hpp"
//Basic singleton
Timer* Timer::sInstance = nullptr;

Timer* Timer::Instance()
{
    if(sInstance == nullptr)
        sInstance = new Timer();
    return sInstance;
}

void Timer::Release()
{
    delete sInstance;
    sInstance = nullptr;
}
//Constucter and destructer
Timer::Timer()
{
    Reset();
    mElapsedTicks = 0;
    mDeltaTime = 0.0f;
    mTimeScale = 1.0f;
}

Timer::~Timer()
{
    
}
//Reset the  timer
void Timer::Reset()
{
    mStartTicks = SDL_GetTicks();

}
//DeltaTime getter
float Timer::DeltaTime()
{
    return mDeltaTime;
}
//TimeScale setter
void Timer::TimeScale(float t)
{
    mTimeScale = t;
}
//TimeScale getter
float Timer::TimeScale()
{
    return mTimeScale;
}
//Update
void Timer::Update()
{
    mElapsedTicks = SDL_GetTicks() - mStartTicks;
    mDeltaTime = mElapsedTicks * 0.001f;
}