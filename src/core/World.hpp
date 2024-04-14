//
// Created by marco on 17/03/2024.
//

#ifndef RAYLIB_TEMPLATE_PORTABLE_WINDOWS_WORLD_HPP
#define RAYLIB_TEMPLATE_PORTABLE_WINDOWS_WORLD_HPP

#include <memory>
#include <raylib.h>

namespace raycaster {

    class World {
    public:
        World(const std::string& filepath);
        double RayTrace(Vector2 from, double angle);


    private:
        int m_XSize, m_YSize;
        const double RAY_STEP = 0.05;
        std::unique_ptr<bool[]> m_Map;

        bool IsWall(int x, int y);




    };

} // raycaster


#endif //RAYLIB_TEMPLATE_PORTABLE_WINDOWS_WORLD_HPP
