#ifndef LAB02_MAP_HPP
#define LAB02_MAP_HPP

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Object/GameObject.hpp"

constexpr uint8_t WIDTH = 12;
constexpr uint8_t HEIGHT = 12;

namespace Map {
struct Rendered {
    Object::GamePosition pos;
    std::string          name;

    inline bool operator==(const Rendered& rhs) const { return pos == rhs.pos; }
};

void Draw(const std::vector<std::shared_ptr<Object::GameObject>>& object);
}  // namespace Map
#endif  // LAB02_MAP_HPP
