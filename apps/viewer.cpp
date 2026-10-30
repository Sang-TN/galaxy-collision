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

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
}