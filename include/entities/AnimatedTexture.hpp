/*
AnimatedTexture class
Is a texture, but animated
Uses a sprite sheet
*/
#pragma once

#include "Texture.hpp"
#include "Timer.hpp"

namespace oni
{
    class AnimatedTexture : public Texture
    {
    public:
        //Enums
        enum WRAP_MODE {once = 0, loop = 1}; //If the animation goes once or loops
        enum ANIM_DIR {horizontal = 0, vertical = 1}; //Direction of sprite sheet

        /**
         * @brief A texture that animates through a sprite sheet
         * @param filename Name of the sprite sheet file
         * @param x Starting X position
         * @param y Starting Y position
         * @param w Width of a single frame
         * @param h Height of a single frame
         * @param framecount Number of frames in the animation
         * @param animationSpeed Duration of the animation
         * @param animationDir Direction of the sprite sheet
        */
        AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir);

        ~AnimatedTexture();

        /**
         * @brief Change the textures wrapmode
        */
        void WrapMode(WRAP_MODE mode);

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
}