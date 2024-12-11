#include "../include/Character.hpp"
Character::Character(int x, int y, std::string id): position(x, y), id(id){}
Character::~Character() {}
Point Character::getPosition() {
    return position;
}
std::string Character::getId() {
    return id;
}
