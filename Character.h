#include "raylib.h"
class Character
{
public:
    Character();
    Vector2 getWorldPos(){return worldPos;}
    void setScreenPos(int winWidth, int winHeight);
    void tick(float deltaTime);

private:
    Texture2D texture{LoadTexture("character/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("character/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("character/knight_run_spritesheet.png")};
    Vector2 screenPos;
    Vector2 worldPos;
    float rightLeft{1.0f};
    float runningTime{};
    int frame{};
    int maxframe{6};
    float updateTime{1.f / 12.f};
    float Speed{4.f};
    float width{};
    float height{};
};