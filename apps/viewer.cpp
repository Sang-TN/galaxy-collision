#include "raylib.h"
#include "core/vec3.hpp"
#include "core/teilchenspeicher.hpp"
#include "setup/zufall.hpp"
#include <iostream>

int main()
{

    Teilchenspeicher speicher;
    zufaelligePunkte(speicher, 500, 1.0f, 42);
    speicher.positionen()[0].x;

    std::cout << speicher.positionen()[0].x << " " << speicher.positionen()[0].y << " " << speicher.positionen()[0].z << std::endl;

    std::cout << speicher.anzahl() << std::endl;

    InitWindow(1280, 720, "Galaxienkollision");

    Camera3D kamera{{3.0f, 2.0f, 3.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, CAMERA_PERSPECTIVE};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(kamera);
        DrawGrid(10, 0.5f);
        EndMode3D();
        EndDrawing();
    }

    CloseWindow();
}