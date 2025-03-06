#ifndef OOPLAB_STATE_MOVEMENTSTATE_HPP
#define OOPLAB_STATE_MOVEMENTSTATE_HPP

#include "Object/GameObject.hpp"

enum class GhostType { BLINKY, CLYDE, INKY, PINKY };

namespace State {
class MovementState {
public:
    MovementState() = default;
    virtual ~MovementState() = default;

    virtual Object::GamePosition Behavior(
        GhostType            type,
        Object::GamePosition pos,
        Object::GamePosition playerPos
    );
};
}  // namespace State

#endif  // OOPLAB_STATE_MOVEMENTSTATE_HPP
