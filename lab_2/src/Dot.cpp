#include "Object/Dot.hpp"

namespace Object {
Dot::Dot(Object::GamePosition pos){
    position.x = pos.x;
    position.y = pos.y;
};

uint8_t Dot::GetPoint() {
    return point;
}

std::string Dot::GetName() const {
    return "d";
}

Object::GamePosition Dot::GetPosition() const {
    return position;
}
}  // namespace Object
