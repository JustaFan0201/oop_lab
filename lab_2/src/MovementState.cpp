#include "State/MovementState.hpp"
#include "Object/GameObject.hpp"

namespace State {
Object::GamePosition MovementState::Behavior(
    GhostType            type,
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    return Object::GamePosition();
}
}  // namespace State
