//
// Created by wrz666 on 2024/4/14.
//

#include "Player.hpp"
#include "Common.hpp"
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
        position), direction(direction), gameMap(gameMap) {}

void raycaster::Player::move(Vector2 displacement) {
    displacement = raycaster::rotateVector(displacement,direction);
    Vector2 newPosition = {position.x + displacement.x,position.y+displacement.y};
    if(!gameMap.IsWall((int)newPosition.x,(int)newPosition.y)){
        position = newPosition;
    }
}
