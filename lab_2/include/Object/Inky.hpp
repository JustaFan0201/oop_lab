#ifndef OOPLAB_INKY_HPP
#define OOPLAB_INKY_HPP
#include <memory>
#include "Interface/Attackable.hpp"
#include "GameObject.hpp"
#include "Interface/MonsterMovable.hpp"
#include "State/ChaseState.hpp"
#include "State/MovementState.hpp"
#include "State/ScatterState.hpp"

constexpr int INKY_INITIAL_POS_X = 0;
constexpr int INKY_INITIAL_POS_Y = 11;

namespace Object {
class Inky : public Object::GameObject,
             public Object::MonsterMovable,
             public Object::Attackable {
public:
  std::string name = "I";

  Object::GamePosition pos = {INKY_INITIAL_POS_X, INKY_INITIAL_POS_Y};

  std::shared_ptr<State::MovementState> state = std::make_shared<State::ChaseState>();

public:
  explicit Inky();

  std::string GetName() const override;

  Object::GamePosition GetPosition() const override;

    void SetState(MonsterState s) override;

  void Move(const Object::GamePosition &playerPos) override;
};

} // namespace Object
#endif // OOPLAB_Inky_HPP