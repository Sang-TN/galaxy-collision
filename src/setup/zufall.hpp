#pragma once
#include "core/teilchenspeicher.hpp"
#include <random>
#include <cstddef>

inline void zufaelligePunkte(Teilchenspeicher &speicher, std::size_t anzahl, float radius, unsigned int seed)
{
    std::mt19937 generator(seed);
    std::uniform_real_distribution<float> verteilung(-radius, radius);

    for (std::size_t i = 0; i < anzahl; i++)
    {
        float zufall_x = verteilung(generator);
        float zufall_y = verteilung(generator);
        float zufall_z = verteilung(generator);
        Vec3 position = Vec3(zufall_x, zufall_y, zufall_z);
        Vec3 geschwindigkeit = Vec3();
        speicher.hinzufuegen(position, geschwindigkeit);
    }
}
