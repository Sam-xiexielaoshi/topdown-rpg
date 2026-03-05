#include <raylib.h>

int main(){

    //window dimensions
    int windowDimensions[2];
    windowDimensions[0]=384;
    windowDimensions[1]=384;

    //initialize window
    InitWindow(windowDimensions[0], windowDimensions[1], "RPG - Run Paglu");

    //set target FPS
    SetTargetFPS(60);

    //map variable
    Texture2D map = LoadTexture("nature tileset/map.png");
    

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //draw the background
        Vector2 bgPos{0.0,0.0};
        DrawTextureEx(map, bgPos, 0.0,4.0,WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
