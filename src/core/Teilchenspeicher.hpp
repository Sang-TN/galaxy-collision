#pragma once
#include "core/vec3.hpp"
#include <vector>
#include <cstddef>
#include <span>

class Teilchenspeicher
{
private:
    std::vector<Vec3> positionen_;
    std::vector<Vec3> geschwindigkeiten_;
    std::vector<Vec3> beschleunigungen_;

public:
    void hinzufuegen(const Vec3 &position, const Vec3 &geschwindigkeit)
    {
        positionen_.push_back(position);
        geschwindigkeiten_.push_back(geschwindigkeit);
        beschleunigungen_.push_back(Vec3());
    }
    std::size_t anzahl() const
    {
        return positionen_.size();
    }

    std::span<Vec3> positionen()
    {
        return positionen_;
    }

    std::span<const Vec3> positionen() const
    {
        return positionen_;
    }
};