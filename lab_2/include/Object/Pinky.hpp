#ifndef OOPLAB_PINKY_HPP
#define OOPLAB_PINKY_HPP
#include <memory>
#include <iostream>
#include "GameObject.hpp"
#include "Interface/Attackable.hpp"
#include "Interface/MonsterMovable.hpp"
#include "State/ChaseState.hpp"
#include "State/MovementState.hpp"
#include "State/ScatterState.hpp"
#include "string"

constexpr int PINKY_INITIAL_POS_X = 11;
constexpr int PINKY_INITIAL_POS_Y = 0;

namespace Object {
class Pinky : public Object::GameObject,
              public Object::MonsterMovable,
              public Object::Attackable {
private:
    std::string name = "N";

    Object::GamePosition pos = {PINKY_INITIAL_POS_X, PINKY_INITIAL_POS_Y};

    std::shared_ptr<State::MovementState> state =
        std::make_shared<State::ChaseState>();

public:
    explicit Pinky();

    std::string GetName() const override;

    Object::GamePosition GetPosition() const override;

    void SetState(MonsterState s) override;

    void Move(const Object::GamePosition& playerPos) override;
};

};  // namespace Object

#endif  // OOPLAB_PINKY_HPP
