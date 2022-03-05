#include "Button.hpp"

using namespace oni;

Button::Button(std::string filename, bool _oneClick)
{
    mCursor = Cursor::Instance();
    mInput = InputManager::Instance();

    oneClick = _oneClick;

    isClicked = false;
    isHovered = false;
    
    mBackTexture = new Texture(filename);
    mBackTexture->Parent(this);

    AddCollider(new BoxCollider(mBackTexture->ScaledDimensions()));

    mID = PhysicsManager::Instance()->RegisterEntity(this, "UI");
}

Button::Button(std::string backTexFilename, std::string frontTexFilename, bool _oneClick)
{
    mCursor = Cursor::Instance();
    mInput = InputManager::Instance();

    oneClick = _oneClick;

    isClicked = false;
    isHovered = false;
    
    mBackTexture = new Texture(backTexFilename);
    mBackTexture->Parent(this);

    mFrontTexture = new Texture(frontTexFilename);
    mFrontTexture->Parent(this);

    AddCollider(new BoxCollider(mBackTexture->ScaledDimensions()));

    mID = PhysicsManager::Instance()->RegisterEntity(this, "UI");
}

Button::Button(std::string backTexFilename, std::string frontText, std::string frontTextFontpath, int frontTextSize, SDL_Color frontTextColor, bool _oneClick)
{
    mCursor = Cursor::Instance();
    mInput = InputManager::Instance();

    oneClick = _oneClick;

    isClicked = false;
    isHovered = false;
    
    mBackTexture = new Texture(backTexFilename);
    mBackTexture->Parent(this);

    mFrontTexture = new Texture(frontText, frontTextFontpath, frontTextSize, frontTextColor);
    mFrontTexture->Parent(this);

    AddCollider(new BoxCollider(mBackTexture->ScaledDimensions()));

    mID = PhysicsManager::Instance()->RegisterEntity(this, "UI");
}

Button::~Button()
{
    mCursor = nullptr;
    mInput = nullptr;

    delete mBackTexture;
    mBackTexture = nullptr;

    if(mFrontTexture != nullptr)
    {
        delete mFrontTexture;
        mFrontTexture = nullptr;
    }
}

bool Button::Clicked()
{
    return isClicked;
}

bool Button::Hovered()
{
    return isHovered;
}

void Button::Hit(PhysEntity* other, int collliderIndex)
{
    if(PhysicsManager::Instance()->GetEntityLayer(other->GetID()) != 1)
        return;
    isHovered = true;
}

void Button::Update()
{
    if(!oneClick)
        isClicked = false;
    
    if(isHovered && mInput->MouseButtonPressed(InputManager::MOUSE_BUTTON::left))
    {
        isClicked = true;
    }

    isHovered = false; 
}

void Button::Render()
{
    mBackTexture->Render();
    if(mFrontTexture != nullptr)
        mFrontTexture->Render();
}