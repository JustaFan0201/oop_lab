#include "Object/Blinky.hpp"
#include "State/ChaseState.hpp"
#include "State/ScatterState.hpp"

namespace Object {

Blinky::Blinky() {}

std::string Blinky::GetName() const {
    return name;
}

Object::GamePosition Blinky::GetPosition() const {
    return pos;
}

void Blinky::SetState(Object::MonsterState s) {
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

void Blinky::Move(const Object::GamePosition& playerPos) {
    if (state) {
        pos = state->Behavior(GhostType::BLINKY, pos, playerPos);
    }
}
}  // namespace Object
