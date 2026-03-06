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
    const float mapScale{4.0f};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // bgPos.x = Clamp(bgPos.x, -(map.width * mapScale - windowWidth), 0.0f);
        // bgPos.y = Clamp(bgPos.y, -(map.height * mapScale - windowHeight), 0.0f);

        bgPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the background
        DrawTextureEx(map, bgPos, 0.0, mapScale, WHITE);
        knight.tick(GetFrameTime());
        //check map bounds
        if(knight.getWorldPos().x<0.f||knight.getWorldPos().y<0.f||knight.getWorldPos().x+windowWidth>map.width*mapScale||knight.getWorldPos().y+windowHeight>map.height*mapScale)
        {
            DrawText("Out of bounds!", 10, 10, 20, RED);
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
