#ifndef OOPLAB_BLINKY_HPP
#define OOPLAB_BLINKY_HPP

#include <memory>
#include "GameObject.hpp"
#include "Interface/Attackable.hpp"
#include "Interface/MonsterMovable.hpp"
#include "State/ChaseState.hpp"
#include "State/MovementState.hpp"

constexpr int BLINKY_INITIAL_POS_X = 0;
constexpr int BLINKY_INITIAL_POS_Y = 0;

namespace Object {
class Blinky : public Object::GameObject,
               public Object::MonsterMovable,
               public Object::Attackable {
public:
    std::string name = "B";

    Object::GamePosition pos = {BLINKY_INITIAL_POS_X, BLINKY_INITIAL_POS_Y};

    std::shared_ptr<State::MovementState> state =
        std::make_shared<State::ChaseState>();

public:
    explicit Blinky();

    std::string GetName() const override;

    Object::GamePosition GetPosition() const override;

    void SetState(MonsterState s) override;

    void Move(const Object::GamePosition& playerPos) override;
};

}  // namespace Object
#endif  // OOPLAB_BLINKY_HPP
