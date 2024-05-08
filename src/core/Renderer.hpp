//
// Created by marco on 17/03/2024.
//

#ifndef RAYLIB_TEMPLATE_PORTABLE_WINDOWS_RENDERER_HPP
#define RAYLIB_TEMPLATE_PORTABLE_WINDOWS_RENDERER_HPP

#include <memory>
#include "World.hpp"
#include "Common.hpp"
#include "RayCollision.hpp"

namespace raycaster {

    class Renderer {
    public:
        void DrawWallVec();
        void CalculateWallVec(const raycaster::World& world, Vector2 from, double angle);

    private:
        const double m_FOV = raycaster::deg2rad(90);
        const double m_MAX_DIST = 10;
        static const int m_XRES = 5;
        const double m_DELTA = m_FOV/m_XRES;
        raycaster::RayCollision m_WallVec[m_XRES];
    };

} // raycaster

#endif //RAYLIB_TEMPLATE_PORTABLE_WINDOWS_RENDERER_HPP
