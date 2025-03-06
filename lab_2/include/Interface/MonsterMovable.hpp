#ifndef OOPLAB_SELFMOVABLE_HPP
#define OOPLAB_SELFMOVABLE_HPP

#include "Object/GameObject.hpp"

namespace Object {

enum class MonsterState {
    Chase,
    Scatter
};

class MonsterMovable {
public:
    MonsterMovable() = default;
    virtual ~MonsterMovable() = default;
    virtual void Move(const Object::GamePosition& playerPos) = 0;

    virtual void SetState(MonsterState s) = 0;
};
}  // namespace Object
#endif  // OOPLAB_SELFMOVABLE_HPP
