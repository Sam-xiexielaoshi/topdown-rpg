#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight)
{
    width = texture.width / maxframe;
    height = texture.height;
    screenPos = {
        static_cast<float>(winWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(winHeight) / 2.0f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    BaseCharacter::tick(deltaTime);
    Vector2 directions{};
    if (IsKeyDown(KEY_A))
        directions.x -= 1.0;
    if (IsKeyDown(KEY_D))
        directions.x += 1.0;
    if (IsKeyDown(KEY_W))
        directions.y -= 1.0;
    if (IsKeyDown(KEY_S))
        directions.y += 1.0;
    if (Vector2Length(directions) != 0.0)
    {
        // set worldPos = worldPos + directions
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(directions), Speed));
        directions.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
}