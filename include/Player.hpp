#include "PhysEntity.hpp"
#include "Texture.hpp"

class Player : public PhysEntity
{
public:
    Player();
    ~Player();

    void Update();
    void Render();

    Texture* playerTexture;

};