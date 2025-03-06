#include "State/ScatterState.hpp"

namespace State {

Object::GamePosition ScatterState::Behavior(
    GhostType type,
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    switch (type) {
    case GhostType::BLINKY:
        return Blinky(pos, playerPos);
    case GhostType::CLYDE:
        return Clyde(pos, playerPos);
    case GhostType::INKY:
        return Inky(pos, playerPos);
    case GhostType::PINKY:
        return Pinky(pos, playerPos);
    default:
        return pos;
    }
}

Object::GamePosition ScatterState::Blinky(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    pos.x = 0;  // 靜止回到某一個點
    pos.y = 0;
    return pos;
}

Object::GamePosition ScatterState::Clyde(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    pos.x = 11;  // 靜止回到某一個點
    pos.y = 11;
    return pos;
}

Object::GamePosition ScatterState::Inky(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    pos.x = 0;  // 靜止回到某一個點
    pos.y = 11;
    return pos;
}

Object::GamePosition ScatterState::Pinky(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    pos.x = 11;  // 靜止回到某一個點
    pos.y = 0;
    return pos;
}
}  // namespace State
