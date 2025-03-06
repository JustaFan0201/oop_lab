#ifndef OOPLAB_GAMEOBJECT_HPP
#define OOPLAB_GAMEOBJECT_HPP

#include "string"

namespace Object {
struct GamePosition {
    int x;
    int y;
    inline bool operator==(GamePosition pos) const {
        return x == pos.x and y == pos.y;
    }

    inline GamePosition operator+(GamePosition pos) const {
        return {x+pos.x,y+pos.y};
    }

    inline GamePosition operator-(GamePosition pos) const {
        return {x - pos.x, y - pos.y};
    }
};

class GameObject {
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    virtual std::string GetName() const = 0;

    virtual GamePosition GetPosition() const = 0;
};
}  // namespace Object
#endif  // OOPLAB_GAMEOBJECT_HPP
