#ifndef OOPLAB_PLAYER_HPP
#define OOPLAB_PLAYER_HPP

#include <string>
#include "GameObject.hpp"
#include "Interface/PlayerMovable.hpp"

namespace Object {
class Player : public Object::GameObject, Object::PlayerMovable {
private:
    std::string          name = "P";
    Object::GamePosition pos = {7, 7};

public:
    Player() = default;

    std::string GetName() const override;

    Object::GamePosition GetPosition() const override;

    void Move(char direction) override;

    bool IsOutRange() override;
};
}  // namespace Object

#endif  // OOPLAB_PLAYER_HPP
