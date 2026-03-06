#include "raylib.h"
class Enemy
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    Vector2 getWorldPos() { return worldPos; }
    void tick(float deltaTime);
    void undoMovement();
    Rectangle getCollisionRec();

private:
    Texture2D texture{LoadTexture("character/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("character/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("character/knight_run_spritesheet.png")};
    Vector2 screenPos{};
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
};