#ifndef OOPLAB_STATE_CHASESTATE_HPP
#define OOPLAB_STATE_CHASESTATE_HPP

#include "Object/GameObject.hpp"
#include "State/MovementState.hpp"

namespace State {
class ChaseState : public MovementState {
public:
    ChaseState() = default;

    ~ChaseState() = default;

    Object::GamePosition Behavior(
        GhostType            type,
        Object::GamePosition pos,
        Object::GamePosition playerPos
    ) override;

private:
    bool IsOutRange(Object::GamePosition pos);

    Object::GamePosition Blinky(
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

    Object::GamePosition Clyde(
        Object::GamePosition pos,
        Object::GamePosition playerPos
    );
};
}  // namespace State

#endif  // OOPLAB_STATE_CHASESTATE_HPP
