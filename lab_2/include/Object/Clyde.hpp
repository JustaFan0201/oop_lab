#ifndef OOPLAB_CLYDE_HPP
#define OOPLAB_CLYDE_HPP
#include <memory>
#include "GameObject.hpp"
#include "Interface/Attackable.hpp"
#include "Interface/MonsterMovable.hpp"
#include "State/ChaseState.hpp"
#include "State/MovementState.hpp"

constexpr int CLYDE_INITIAL_POS_X = 11;
constexpr int CLYDE_INITIAL_POS_Y = 11;

namespace Object {
class Clyde : public Object::GameObject,
              public Object::MonsterMovable,
              public Object::Attackable {
public:
    std::string name = "C";

    Object::GamePosition pos = {CLYDE_INITIAL_POS_X, CLYDE_INITIAL_POS_Y};

    std::shared_ptr<State::MovementState> state =
        std::make_shared<State::ChaseState>();

public:
    explicit Clyde();

    std::string GetName() const override;

    Object::GamePosition GetPosition() const override;

    void SetState(MonsterState s) override;

    void Move(const Object::GamePosition& playerPos) override;
};

}  // namespace Object
#endif  // OOPLAB_CLYDE_HPP
