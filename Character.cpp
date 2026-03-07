#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) : windowWidth(winWidth), windowHeight(winHeight)
{
    width = texture.width / maxframe;
    height = texture.height;
}

Vector2 Character::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    if (!getAlive())
        return;
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;
    BaseCharacter::tick(deltaTime);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (rightLeft > 0.f)
    {
        origin = {0.f, sword.height * scale};
        offset = {35.f, 55.f};
        swordCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - sword.height * scale,
            sword.width * scale,
            sword.height * scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.f : 0.f;
    }
    else
    {
        origin = {sword.width * scale, sword.height * scale};
        offset = {25.f, 55.f};
        swordCollisionRec = {getScreenPos().x + offset.x - sword.width * scale,
                             getScreenPos().y + offset.y - sword.height * scale,
                             sword.width * scale,
                             sword.height * scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.f : 0.f;
    }

    // draw sword
    Rectangle source{0.f, 0.f, static_cast<float>(sword.width) * rightLeft, static_cast<float>(sword.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, sword.width * scale, sword.height * scale};
    DrawTexturePro(sword, source, dest, origin, rotation, WHITE);

    DrawRectangleLines(swordCollisionRec.x, swordCollisionRec.y, swordCollisionRec.width, swordCollisionRec.height, RED);
}