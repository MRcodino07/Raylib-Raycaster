#include <iostream>
#include "core/Common.hpp"
#include "core/Renderer.hpp"
#include "core/Player.hpp"


const bool MAP[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1,

        };
const int XSIZE = 9, YSIZE = 9;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    auto screenCentre = GetWindowPosition();
    auto renderer = raycaster::Renderer(800);
    auto world = raycaster::World("../res/maps/base.map");
    auto player = raycaster::Player(Vector2{5,5},0);
    HideCursor();
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        if(IsWindowFocused()) {
            player.rotate(raycaster::deg2rad(screenCentre.x - GetMouseX()) / 2);
        }
        renderer.CalculateWallVec(world, player.getPosition(), player.getDirection());
        SetMousePosition((int)screenCentre.x,(int)screenCentre.y);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        renderer.DrawWallVec();
        ClearBackground(RAYWHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

