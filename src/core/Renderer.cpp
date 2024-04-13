//
// Created by marco on 17/03/2024.
//

#include "Renderer.hpp"
#include <raylib.h>
#include <iostream>

namespace raycaster {


    Renderer::Renderer(int xRes) {
        m_XRes = xRes;
        m_WallVec = std::make_unique<double[]>(m_XRes);
    }

    void Renderer::CalculateWallVec(raycaster::World& world, Vector2 from, double angle) {\
        double currentAngle = angle - m_FOV/2;
        int i = 0;
        while (currentAngle < angle + m_FOV/2) {
            m_WallVec[i] = world.RayTrace(from, currentAngle);
            currentAngle += m_FOV/m_XRes;
            i++;
        }
    }

    void Renderer::DrawWallVec() {
        for (int i = 0; i < m_XRes; i++) {
            int xPos = (GetScreenWidth() / m_XRes) * i;
            int width = (int) ((double)GetScreenWidth() / (double )m_XRes);
            int height = (int) ((double )GetScreenHeight() * (1 / m_WallVec[i]));
            int yPos = (GetScreenHeight() - height) / 2;
            DrawRectangle( xPos,  yPos, width, height, GREEN);
        }
    }



} // raycaster