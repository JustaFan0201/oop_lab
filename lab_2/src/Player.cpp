#include "Object/Player.hpp"
#include "Object/GameObject.hpp"

namespace Object {

std::string Player::GetName() const {
    return name;
};

Object::GamePosition Player::GetPosition() const {
    return pos;
};

void Player::Move(char direction) {
    if (direction == 'w'){
        pos.y += 1;
    }
    else if (direction == 'a'){
        pos.x -= 1;
    }
    else if (direction == 's'){
        pos.y -= 1;
    }
    else if (direction == 'd'){
        pos.x += 1;
    }
    IsOutRange();
}

bool Player::IsOutRange() {
    if (pos.x > 11){
        pos.x = 11;
    }
    else if (pos.x < 0){
        pos.x = 0;
    }

    if (pos.y > 11){
        pos.y = 11;
    }
    else if (pos.y < 0){
        pos.y = 0;
    }
    return true;
}

}  // namespace Object
