#include <iostream>
#include "core/Common.hpp"
#include "core/Renderer.hpp"
#include "core/Player.hpp"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const float step = 0.1;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    auto screenCentre = GetWindowPosition();
    auto renderer = raycaster::Renderer(800);
    auto world = raycaster::World("../res/maps/base.map");
    auto player = raycaster::Player(Vector2{5,5},0,world);
    HideCursor();
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        if(IsWindowFocused()) {
            player.rotate((float )raycaster::deg2rad((float)GetMouseX()-screenCentre.x) / 2);
            if(IsKeyDown(KEY_W)){
                player.move({step,0});

            }
            if(IsKeyDown(KEY_A)){
                player.move({0,-step});

            }
            if(IsKeyDown(KEY_S)){
                player.move({-step,0});
            }
            if(IsKeyDown(KEY_D)){
                player.move({0,step});
            }
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

