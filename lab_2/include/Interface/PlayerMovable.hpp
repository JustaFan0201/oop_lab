#ifndef OOPLAB_PLAYERMOVABLE_HPP
#define OOPLAB_PLAYERMOVABLE_HPP

namespace Object {
class PlayerMovable {
public:
    PlayerMovable() = default;
    virtual ~PlayerMovable() = default;

    virtual void Move(char direction) = 0;
    virtual bool IsOutRange() = 0;
};
}  // namespace Object
#endif  // OOPLAB_PLAYERMOVABLE_HPP
