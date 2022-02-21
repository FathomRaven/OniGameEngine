/*
AnimatedTexture class
Is a texture, but animated
Uses a sprite sheet
*/
#pragma once

#include "Texture.hpp"
#include "Timer.hpp"

class AnimatedTexture : public Texture
{
public:
    //Enums
    enum WRAP_MODE {once = 0, loop = 1}; //If the animation goes once or loops
    enum ANIM_DIR {horizontal = 0, vertical = 1}; //Direction of sprite sheet

    //Constructor and destructor
    //AnimatedTexture Constructor 
    //@param filename The name of the spritesheet to load
    //@param frameCount The amount of frames in the spritesheet
    //@param animationSpeed The speed of the animation 
    //@param direction of the sprite sheet 
    AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir);
    ~AnimatedTexture();
    //Wrapping mode setter
    void WrapMode(WRAP_MODE mode);
    //Update
    void Update();

private:
    //Timer instance
    Timer* mTimer;
    //Where the texture starts at
    int mStartX, mStartY;
    
    float mAnimationTimer; //Animation timer
    float mAnimationSpeed; //Speed of animation
    float mTimePerFrame; //Time in between each frame
    
    int mFrameCount; //Amount of frames the animation will last
    
    WRAP_MODE mWrapMode; //Current wrapmode. Set to loop by default
    ANIM_DIR mAnimationDirection; //The sprite sheet direction
    
    bool mAnimationDone;//If the animation is done or not
    
};