#ifndef OOPLAB_SCATTERSTATE_HPP
#define OOPLAB_SCATTERSTATE_HPP

#include "Object/GameObject.hpp"
#include "State/MovementState.hpp"

namespace State {
class ScatterState : public MovementState {
public:
    ScatterState() = default;
    ~ScatterState() = default;

    Object::GamePosition Behavior(
        GhostType            type,
        Object::GamePosition pos,
        Object::GamePosition playerPos
    ) override;

private:
    Object::GamePosition Blinky(
        Object::GamePosition pos,
        Object::GamePosition playerPos
    );

    Object::GamePosition Clyde(
        Object::GamePosition pos,
        Object::GamePosition playerPos
    );

    Object::GamePosition Inky(
        Object::GamePosition pos,
        Object::GamePosition playerPos
    );

    Object::GamePosition Pinky(
        Object::GamePosition pos,
        Object::GamePosition playerPos
    );
};
}  // namespace State

#endif  // OOPLAB_SCATTERSTATE_HPP
