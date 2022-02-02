#include "PhysEntity.hpp"
#include "Texture.hpp"


class Player : public PhysEntity
{
public:
    Player();
    ~Player();

    void Update();
    void Render();

    void Hit(PhysEntity* other) override;

    Texture* playerTexture;

private:
    //To ignore collisions, define this function
    // bool IgnoreCollisions() override;
};