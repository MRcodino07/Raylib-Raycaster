//
// Created by marco on 17/03/2024.
//

#ifndef RAYLIB_TEMPLATE_PORTABLE_WINDOWS_WORLD_HPP
#define RAYLIB_TEMPLATE_PORTABLE_WINDOWS_WORLD_HPP

#include <memory>
#include <raylib.h>
#include "RayCollision.hpp"

namespace raycaster {

    class World {
    public:
        World(const std::string& filepath);
        raycaster::RayCollision RayTrace(Vector2 from, double angle);
        bool IsWall(int x, int y);

    private:
        int m_XSize, m_YSize;
        std::shared_ptr<bool[]> m_Map;
    };

} // raycaster


#endif //RAYLIB_TEMPLATE_PORTABLE_WINDOWS_WORLD_HPP
