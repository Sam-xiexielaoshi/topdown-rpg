#include <raylib.h>
#include <raymath.h>

class Character
{
public:
    Vector2 getWorldPos()
    {
        return worldPos;
    }
    void setScreenPos(int winWidth, int winHeight);
    void tick(float deltaTime);

private:
    Texture2D texture{LoadTexture("character/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("character/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("character/knight_run_spritesheet.png")};
    Vector2 screenPos;
    Vector2 worldPos;
    // 1: facing right, -1: facing left
    float rightLeft{1.0f};
    // animation variables
    float runningTime{};
    int frame{};
    const int maxframe{6};
    const float updateTime{1.f / 12.f};
    const float Speed{4.f};
};

void Character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)winHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)};
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
}

int main()
{

    // window dimensions
    int windowWidth = 384;
    int windowHeight = 384;

    // initialize window
    InitWindow(windowWidth, windowHeight, "RPG - Run Paglu");

    // set target FPS
    SetTargetFPS(60);

    // map variable
    Texture2D map = LoadTexture("nature tileset/map.png");
    Vector2 bgPos{0.0, 0.0};
    float Speed{4.0};

    Texture2D knight_idle = LoadTexture("character/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("character/knight_run_spritesheet.png");
    Texture2D knight = LoadTexture("character/knight_idle_spritesheet.png");
    Vector2 knightPos = {
        (float)windowWidth / 2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f),
        (float)windowHeight / 2.0f - 4.0f * (0.5f * (float)knight.height)
    };
    // 1: facing right, -1: facing left
    float rightLeft{1.0f};
    // animation variables
    float runningTime{};
    int frame{};
    const int maxframe{6};
    const float updateTime{1.f / 12.f};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

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
            // set bgPos = bgPos - directions
            bgPos = Vector2Subtract(bgPos, Vector2Scale(Vector2Normalize(directions), Speed));
            directions.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            knight = knight_run;
        }
        else
        {
            knight = knight_idle;
        }

        bgPos.x = Clamp(bgPos.x, -(map.width * 4.0f - windowWidth), 0.0f);
        bgPos.y = Clamp(bgPos.y, -(map.height * 4.0f - windowHeight), 0.0f);

        // draw the background
        DrawTextureEx(map, bgPos, 0.0, 4.0, WHITE);

        // update animations frame
        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxframe)
                frame = 0;
        }

        // draw the character
        Rectangle source{frame * (float)knight.width / 6.0f, 0.f, rightLeft * (float)knight.width / 6.0f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width / 6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
