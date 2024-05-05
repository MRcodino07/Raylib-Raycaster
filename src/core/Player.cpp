//
// Created by wrz666 on 2024/4/14.
//

#include "Player.hpp"
#include "Common.hpp"
#include <fstream>
const Vector2 &raycaster::Player::getPosition() const {
    return position;
}

double raycaster::Player::getDirection() const {
    return direction;
}

void raycaster::Player::rotate(float angle) {
    this -> direction += angle;
    if(direction >= 2 * PI){
        direction -= 2 * PI;
    } else if(direction <= -2 * PI){
        direction += 2 * PI;
    }
}

raycaster::Player::Player(const Vector2 &position, double direction, const raycaster::World &gameMap) : position(
        position), direction(direction), gameMap(gameMap) {
    std::ifstream in("../res/config/player.config");
    std::string key;
    while(in >> key){
        float x,y;
        in  >> x >> y;
        keyMap[key][0] = x;
        keyMap[key][1] = y;
    }
}

void raycaster::Player::move(Vector2 displacement) {
    displacement = raycaster::rotateVector(displacement,direction);
    float dTime = GetFrameTime();
    Vector2 newPosition = {position.x + displacement.x*m_SPEED*dTime,position.y+displacement.y*m_SPEED*dTime};
    if(!gameMap.IsWall((int)newPosition.x,(int)newPosition.y)){
        position = newPosition;
    }
}

void raycaster::Player::actionByKeyCode() {
    for (const auto &key : keyMap) {
        int i = 0;
        for(; i <key.first.size(); i++){
            if(!IsKeyDown(key.first[i])){
                break;
            }
        }
        if(i == key.first.size()){
            move(Vector2 {key.second[0],key.second[1]});
        }
    }
}
