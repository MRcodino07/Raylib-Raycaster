//
// Created by marco on 17/03/2024.
//

#include "Renderer.hpp"
#include <raylib.h>
#include <iostream>

namespace raycaster {

    void Renderer::CalculateWallVec(const raycaster::World& world, Vector2 from, double angle) {\
        double currentAngle = angle - m_FOV/2;
        int i = 0;
        while (currentAngle < angle + m_FOV/2) {
            m_WallVec[i] = world.RayTrace(from, currentAngle);
            currentAngle += m_FOV/m_XRES;
            i++;
        }
    }

    void Renderer::DrawWallVec() {
        const double K = 255.0 / m_MAX_DIST;
        for (int i = 0; i < m_XRES; i++) {
            int xPos = (GetScreenWidth() / m_XRES) * i;
            int width = (int) ((double)GetScreenWidth() / (double )m_XRES);
            int height = (int) ((double )GetScreenHeight() * (1 / m_WallVec[i].distance));
            int yPos = (GetScreenHeight() - height) / 2;

            auto disp = (unsigned char)(std::min(m_MAX_DIST, m_WallVec[i].distance) * K);
            unsigned char green = 255 - disp;
            Color c{0, green, 0, 255};
            DrawRectangle( xPos,  yPos, width, height, c);
        }
    }



} // raycaster