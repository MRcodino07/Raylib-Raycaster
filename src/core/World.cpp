//
// Created by marco on 17/03/2024.
//

#include <iostream>
#include <valarray>
#include <fstream>
#include <string>
#include "World.hpp"


namespace raycaster {

    World::World(const std::string& filepath) {
        freopen(filepath.c_str(), "r", stdin);
        std::cin >> m_XSize;
        std::cin >> m_YSize;

        m_Map = std::make_unique<bool[]>(m_XSize * m_YSize);

        for (int i = 0; i < m_XSize * m_YSize; ++i) {
            std::cin >> m_Map[i];
        }
        fclose(stdin);
    }

    bool World::IsWall(int x, int y) {
        return m_Map[y * m_XSize + x];

    }

    double World::RayTrace(Vector2 from, double angle) {
        bool hit = false;

        int mapX = (int)from.x;
        int mapY = (int)from.y;

        double dirX = cos(angle);
        double dirY = sin(angle);

        int stepX,stepY;
        double deltaX = dirX == 0 ? 1e30 : std::abs(1/dirX);
        double deltaY = dirY == 0 ? 1e30 : std::abs(1/dirY);
        double sideDistX;
        double sideDistY;

        if(dirX < 0){
            stepX = -1;
            sideDistX = (from.x - mapX) * deltaX;
        } else {
            stepX = 1;
            sideDistX = (mapX - from.x + 1.0) * deltaX;
        }

        if(dirY < 0){
            stepY = -1;
            sideDistY = (from.y - mapY) * deltaY;
        } else {
            stepY = 1;
            sideDistY = (mapY - from.y + 1.0) * deltaY;
        }
        int side = 0;
        while(!hit){
            if(sideDistX < sideDistY){
                sideDistX += deltaX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaY;
                mapY += stepY;
                side = 1;
            }
            hit = IsWall(mapX,mapY);
        }
        if(side == 0){
            return sideDistX - deltaX;
        } else {
            return sideDistY - deltaY;
        }
    }
} // raycaster
