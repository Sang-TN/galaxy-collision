#include "raylib.h"
#include "core/vec3.hpp"
#include <iostream>

int main()
{
    Vec3 v(3, 4, 12);
    std::cout << v.length() << std::endl;
    InitWindow(1280, 720, "Galaxienkollision");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
}