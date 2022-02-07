#pragma once

#include "PhysEntity.hpp"
#include "Cursor.hpp"

class Button : public PhysEntity
{
public:
    Button(std::string filename, bool _oneClick = false);
    Button(std::string backTexFilename, std::string frontTexFilename, bool _oneClick = false);
    Button(std::string backTexFilename, std::string frontText, std::string frontTextFontpath, int frontTextSize, SDL_Color frontTextColor, bool _oneClick = false);
    ~Button();

    void Update();
    void Render();

    void Hit(PhysEntity* other) override;

    bool Clicked();
    bool Hovered();
private:
    Cursor* mCursor;
    InputManager* mInput;
    
    bool oneClick;

    bool isClicked;
    bool isHovered;

    Texture* mBackTexture;
    Texture* mFrontTexture;
};