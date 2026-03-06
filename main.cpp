#include <raylib.h>
#include <raymath.h>
#include "Character.h"
#include "Prop.h"

int main()
{

    // window dimensions
    int windowWidth = 384;
    int windowHeight = 384;

    // initialize window
    InitWindow(windowWidth, windowHeight, "RPG - Run Paglu");

    Character knight{windowWidth, windowHeight};

    Prop rock{Vector2{0.f, 0.f}, LoadTexture("nature_tileset/Rock.png")};

    // set target FPS
    SetTargetFPS(60);

    // map variable
    Texture2D map = LoadTexture("nature_tileset/map.png");
    Vector2 bgPos{0.0f, 0.0f};
    const float mapScale{4.0f};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        bgPos = Vector2Scale(knight.getWorldPos(), -1.f);

        
        // draw the background
        DrawTextureEx(map, bgPos, 0.0, mapScale, WHITE);

        rock.Render(knight.getWorldPos());
        
        knight.tick(GetFrameTime());
        // check map bounds
        if (knight.getWorldPos().x < 0.f || knight.getWorldPos().y < 0.f || knight.getWorldPos().x + windowWidth > map.width * mapScale || knight.getWorldPos().y + windowHeight > map.height * mapScale)
        {
            knight.undoMovement();
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
