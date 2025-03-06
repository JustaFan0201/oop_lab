#ifndef OOPLAB_GETPOINTER_HPP
#define OOPLAB_GETPOINTER_HPP

#include <cstdint>
#include "stdint.h"

namespace Object {
class GetPointer {
public:
    GetPointer() = default;
    virtual ~GetPointer() = default;

    virtual uint8_t GetPoint() = 0;
};
}  // namespace Object

#endif  // OOPLAB_GETPOINTER_HPP
