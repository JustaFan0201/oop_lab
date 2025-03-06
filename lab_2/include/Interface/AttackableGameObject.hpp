#ifndef OOPLAB_ATTACKABLEGAMEOBJECT_HPP
#define OOPLAB_ATTACKABLEGAMEOBJECT_HPP

#include "Attackable.hpp"
#include "Object/GameObject.hpp"

namespace Object {

class AttackableGameObject : public Attackable, public GameObject {
public:
    virtual ~AttackableGameObject() = default;
};

}  // namespace Object

#endif  // OOPLAB_ATTACKABLEGAMEOBJECT_HPP
