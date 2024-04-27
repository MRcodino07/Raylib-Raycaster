//
// Created by marco on 17/03/2024.
//

#include <iostream>
#include <valarray>
#include <fstream>
#include <string>
#include "World.hpp"
#include "Common.hpp"


namespace raycaster {

    World::World(const std::string& filepath) {
        std::ifstream in(filepath);
        in >> m_XSize;
        in >> m_YSize;

        m_Map = std::make_shared<bool[]>(m_XSize * m_YSize);

        for (int i = 0; i < m_XSize * m_YSize; ++i) {
            in >> m_Map[i];
        }
        in.close();
    }


    bool World::IsWall(int x, int y) const {
        return m_Map[y * m_XSize + x];
    }

    raycaster::RayCollision World::RayTrace(Vector2 from, double angle) {
        if(angle < 0){
            angle += deg2rad(360);
        }


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

        raycaster::RayCollision r;
        double axis;
        if(angle <= deg2rad(90)){
            axis = deg2rad(90);
        } else if (angle <= deg2rad(180)){
            axis = deg2rad(180);
        } else if(angle <= deg2rad(270)){
            axis = deg2rad(270);
        } else {
            axis = deg2rad(360);
        }

        if(side == 0){
            r.collisionAngle = axis - angle;
        } else {
            r.collisionAngle = axis - deg2rad(90) - angle;
        }
        if(side == 0){
            r.distance = sideDistX - deltaX;
        } else {
            r.distance = sideDistY - deltaY;
        }


        return r;
    }
} // raycaster
