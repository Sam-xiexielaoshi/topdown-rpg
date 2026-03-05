#include <raylib.h>
#include<raymath.h>

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
    Vector2 bgPos{0.0,0.0};
    float Speed{4.0};

    Texture2D knight = LoadTexture("character/knight_idle_spritesheet.png");
    Vector2 knightPos{windowDimensions[0]/2.0f -4.0f * (0.5* (float)knight.width/6.0), windowDimensions[1]/2.0f - 4.0f *(0.5*(float)knight.height)};

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 directions{};
        if(IsKeyDown(KEY_A)) directions.x-=1.0;
        if(IsKeyDown(KEY_D)) directions.x+=1.0;
        if(IsKeyDown(KEY_W)) directions.y-=1.0;
        if(IsKeyDown(KEY_S)) directions.y+=1.0;
        if(Vector2Length(directions)!=0.0){
            //set bgPos = bgPos - directions
            bgPos=Vector2Subtract(bgPos, Vector2Scale(Vector2Normalize(directions), Speed));
        }

        bgPos.x = Clamp(bgPos.x, -(map.width * 4.0f - windowDimensions[0]), 0.0f);
        bgPos.y = Clamp(bgPos.y, -(map.height * 4.0f - windowDimensions[1]), 0.0f);

        //draw the background
        DrawTextureEx(map, bgPos, 0.0,4.0,WHITE);

        //draw the caracter
        Rectangle source{0.f,0.f,(float)knight.width/6.0f,(float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{},0.f,WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
