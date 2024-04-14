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
        Renderer(int xRes);
        void DrawWallVec();
        void CalculateWallVec(raycaster::World& world, Vector2 from, double angle);

    private:
        const double m_FOV = raycaster::deg2rad(90);
        int m_XRes;
        std::unique_ptr<raycaster::RayCollision[]> m_WallVec;
    };

} // raycaster

#endif //RAYLIB_TEMPLATE_PORTABLE_WINDOWS_RENDERER_HPP
