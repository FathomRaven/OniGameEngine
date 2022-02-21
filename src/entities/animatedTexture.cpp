#include "AnimatedTexture.hpp"

AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir)
    :Texture(filename, x, y, w, h)
{
    mTimer = Timer::Instance();
    
    //Sets variables to match parameters
    
    mStartX = x;
    mStartY = y;

    mFrameCount = frameCount;
    mAnimationSpeed = animationSpeed;
    mTimePerFrame = mAnimationSpeed / mFrameCount;
    mAnimationTimer = 0.0f;

    mAnimationDirection = animationDir;

    mAnimationDone = false;

    mWrapMode = loop;
}

AnimatedTexture::~AnimatedTexture()
{
    mTimer = nullptr;
}

void AnimatedTexture::WrapMode(WRAP_MODE mode)
{
    mWrapMode = mode;
}

void AnimatedTexture::Update()
{
    //Check if the animations done or not
    if(!mAnimationDone)
    {
        mAnimationTimer += mTimer->DeltaTime(); //Update the timer

        if(mAnimationTimer >= mAnimationSpeed) //Checks if the timer has gone on longer then the speed of the animation.
        {
            //If the animation loops, start the animation again
            //Else, stop the animation
            if(mWrapMode == loop)
            {
                mAnimationTimer -= mAnimationSpeed;
            } else
            {
                mAnimationDone = true;
                mAnimationTimer = mAnimationSpeed - mTimePerFrame;
            }

        }
        //Moves along the sprite sheet to find each frame
        if (mAnimationDirection == horizontal)
        {
            mClipRect.x = mStartX + (int)(mAnimationTimer / mTimePerFrame) * mWidth;

        } else 
        {
            mClipRect.y = mStartY + (int)(mAnimationTimer / mTimePerFrame) * mHeight;
        }
    }
}