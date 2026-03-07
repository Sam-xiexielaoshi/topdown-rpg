#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle getCollisionRec();
    virtual void tick(float deltaTime);
    virtual Vector2 getScreenPos()=0;

protected:
    Texture2D texture{LoadTexture("character/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("character/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("character/knight_run_spritesheet.png")};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    float rightLeft{1.0f};
    float runningTime{};
    int frame{};
    int maxframe{6};
    float updateTime{1.f / 12.f};
    float Speed{4.f};
    float width{};
    float height{};
    float scale{4.0f};
    Vector2 velocity{};

private:
};

#endif