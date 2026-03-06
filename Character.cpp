#include "Character.h"
#include "raymath.h"

Character::Character(){
    width = texture.width / maxframe;
    height = texture.height;
}

void Character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * width),
        (float)winHeight / 2.0f - 4.0f * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
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
    // update animations frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxframe)
            frame = 0;
    }
    // draw the character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * width, 4.0f * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}