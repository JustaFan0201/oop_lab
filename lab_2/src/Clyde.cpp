#include "Object/Clyde.hpp"
#include "State/ChaseState.hpp"
#include "State/ScatterState.hpp"

namespace Object {

Clyde::Clyde() {
};

std::string Clyde::GetName() const {
    return name;
};

Object::GamePosition Clyde::GetPosition() const {
    return pos;
};

void Clyde::SetState(Object::MonsterState s) {
    switch (s) {
    case MonsterState::Chase:
        state = std::make_shared<State::ChaseState>();
        break;
    case MonsterState::Scatter:
        state = std::make_shared<State::ScatterState>();
        break;
    default:
        break;
    }
}

void Clyde::Move(const Object::GamePosition& playerPos) {
    if (state) {
        pos = state->Behavior(GhostType::CLYDE, pos, playerPos);
    }
}
}  // namespace Object
