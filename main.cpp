#include <raylib.h>
#include <raymath.h>
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

int main()
{

    // window dimensions
    int windowWidth = 384;
    int windowHeight = 384;

    // initialize window
    InitWindow(windowWidth, windowHeight, "RPG - Run Paglu");

    Character knight{windowWidth, windowHeight};

    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}};

    Enemy goblin
    {
        Vector2{},
        LoadTexture("character/goblin_idle_spritesheet.png"),
        LoadTexture("character/goblin_run_spritesheet.png")
    };
    goblin.setTarget(&knight);
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

        // draw the props
        for (auto prop : props)
        {
            prop.Render(knight.getWorldPos());
        }

        knight.tick(GetFrameTime());
        // check map bounds
        if (knight.getWorldPos().x < 0.f || knight.getWorldPos().y < 0.f || knight.getWorldPos().x + windowWidth > map.width * mapScale || knight.getWorldPos().y + windowHeight > map.height * mapScale)
        {
            knight.undoMovement();
        }
        // check prop collision
        for (auto prop : props)
        {
            if (CheckCollisionRecs(knight.getCollisionRec(), prop.getCollisionRec(knight.getWorldPos())))
            {
                knight.undoMovement();
            }
        }

        goblin.tick(GetFrameTime());

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            if(CheckCollisionRecs(goblin.getCollisionRec(), knight.getCollisionRec())){
                goblin.setAlive(false);
            }
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
