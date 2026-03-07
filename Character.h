#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "BaseCharacter.h"
class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    Rectangle getSwordCollisionRec() { return swordCollisionRec; }

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D sword{LoadTexture("character/weapon_sword.png")};
    Rectangle swordCollisionRec{};
};

#endif