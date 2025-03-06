#include <gtest/gtest.h>
#include "Object/GameObject.hpp"

TEST(Gameobject_system_test, test_01) {
    Object::GamePosition pos = {0 ,0};

    EXPECT_EQ(pos.x, 0);
    EXPECT_EQ(pos.y, 0);
}

// TEST(Gameobject_system_test, test_02) {
//     Object::GamePosition pos = {1 ,1};

//     EXPECT_EQ(pos.x, 1);
//     EXPECT_EQ(pos.y, 1);
// }
