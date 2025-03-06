#include "Object/Pinky.hpp"

namespace Object {

Pinky::Pinky() {
};

std::string Pinky::GetName() const {
    return name;
};

Object::GamePosition Pinky::GetPosition() const {
    return pos;
};

void Pinky::SetState(Object::MonsterState s) {
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

void Pinky::Move(const Object::GamePosition& playerPos) {
    if (state) {
        pos = state->Behavior(GhostType::PINKY, pos, playerPos);
    }
}
}  // namespace Object
