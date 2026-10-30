#include "raylib.h"
#include "core/vec3.hpp"
#include "core/Teilchenspeicher.hpp"
#include <iostream>

int main()
{
    Vec3 v(3, 4, 12);
    Vec3 v1(7, 10, 15);
    Teilchenspeicher speicher;
    speicher.hinzufuegen(v, v1);
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