#include <iostream>
#include "core/Common.hpp"
#include "core/Renderer.hpp"

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

    auto renderer = raycaster::Renderer(800);
    auto world = raycaster::World("../res/maps/base.map");
    // Main game loop
    double angle = raycaster::deg2rad(0);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        renderer.CalculateWallVec(world, Vector2{4, 3}, angle);
        angle += raycaster::deg2rad(0.5);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        renderer.DrawWallVec();
        DrawText(std::to_string(raycaster::rad2deg(angle)).c_str(), 0, 0, 30, BLACK);
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

