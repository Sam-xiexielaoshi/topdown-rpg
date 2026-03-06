#include <raylib.h>
#include <raymath.h>
#include "Character.h"

int main()
{

    // window dimensions
    int windowWidth = 384;
    int windowHeight = 384;

    // initialize window
    InitWindow(windowWidth, windowHeight, "RPG - Run Paglu");

    Character knight;
    knight.setScreenPos(windowWidth, windowHeight);

    // set target FPS
    SetTargetFPS(60);

    // map variable
    Texture2D map = LoadTexture("nature tileset/map.png");
    Vector2 bgPos{0.0f, 0.0f};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        bgPos.x = Clamp(bgPos.x, -(map.width * 4.0f - windowWidth), 0.0f);
        bgPos.y = Clamp(bgPos.y, -(map.height * 4.0f - windowHeight), 0.0f);

        bgPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the background
        DrawTextureEx(map, bgPos, 0.0, 4.0, WHITE);
        knight.tick(GetFrameTime());

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
