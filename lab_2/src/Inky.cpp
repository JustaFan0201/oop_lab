#include "Object/Inky.hpp"

namespace Object {

Inky::Inky() {
};

std::string Inky::GetName() const {
    return name;
};

Object::GamePosition Inky::GetPosition() const {
    return pos;
};

void Inky::SetState(Object::MonsterState s) {
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

void Inky::Move(const Object::GamePosition& playerPos) {
    if (state) {
        pos = state->Behavior(GhostType::INKY, pos, playerPos);
    }
}
}  // namespace Object
