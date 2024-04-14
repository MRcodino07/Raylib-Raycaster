//
// Created by wrz666 on 2024/4/14.
//

#include "Player.hpp"
raycaster::Player::Player(const Vector2 &position, double direction) : position(position), direction(direction) {}

raycaster::Player::Player() {}

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

