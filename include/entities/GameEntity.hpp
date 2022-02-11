#pragma once
#include "MathHelper.hpp"
//Game entity class
class GameEntity 
{
public:
    //Enumeration is local or world
    enum SPACE {local = 0, world = 1};

    //functions
    //Construct and destruct

    GameEntity(float x = 0.0f, float y = 0.0f);
    virtual ~GameEntity();
    //Postion getter and setter

    void Pos(Vector2 pos);
    Vector2 Pos(SPACE space = world);
    //Rotation getter and setter

    void Rotation(float rotation);
    float Rotation(SPACE space = world);

    void Scale(Vector2 scale);
    Vector2 Scale(SPACE space = world);
    //Activation getter and setter

    void Active(bool active);
    bool Active();
    //Parent getter and setter

    void Parent(GameEntity* parent);
    GameEntity* Parent();
    //Move the entity by a vector 2

    void Translate(Vector2 vec);
    void Rotate(float amount);

    //Render and update, virtual

    virtual void Update();
    virtual void Render();
private:
    //Private variables
    Vector2 mPos;
    float mRotation;
    Vector2 mScale;

    bool mActive;
    GameEntity* mParent;
};