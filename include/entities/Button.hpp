/*
Button class

It's buttons, what else do you want me to say?
*/

#pragma once

#include "PhysEntity.hpp"
#include "Cursor.hpp"

class Button : public PhysEntity
{
public:
    //Button Constructor, with only back texture
    //@param filename The filename of the texture to load
    //@param _oneClick If the button should only be clicked once
    Button(std::string filename, bool _oneClick = false);
    //Button Constructor, with back texture, and front texture
    //@param backTexFilename The filename of the back texture to load
    //@param frontTexFilename The filename of the front texture to load
    //@param _oneClick If the button should only be clicked once
    Button(std::string backTexFilename, std::string frontTexFilename, bool _oneClick = false);
    //Button Constructor, with back texture, and text as front texture
    //@param backTexFilename The filename of the back texture to load
    //@param frontTextFontpath The filename of the font for the front texture
    //@param frontTextSize The size of the front textures text
    //@param frontTextColor The color of the front textures tex
    //@param _oneClick If the button should only be clicked once
    Button(std::string backTexFilename, std::string frontText, std::string frontTextFontpath, int frontTextSize, SDL_Color frontTextColor, bool _oneClick = false);
        
    ~Button();

    void Update() override;
    void Render() override;

    void Hit(PhysEntity* other, int collliderIndex = 0) override;

    bool Clicked();
    bool Hovered();
private:
    Cursor* mCursor;
    InputManager* mInput;
    //If the button is supposed to only be clicked once
    bool oneClick;

    bool isClicked;
    bool isHovered;

    Texture* mBackTexture;
    Texture* mFrontTexture;
};