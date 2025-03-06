set(SRC_FILES
    Blinky.cpp
    Clyde.cpp
    Inky.cpp
    Pinky.cpp

    Player.cpp

    Map.cpp
    Dot.cpp
    MovementState.cpp
    ChaseState.cpp
    ScatterState.cpp
    DotManager.cpp
)


set(INCLUDE_FILES
    Interface/Attackable.hpp
    Interface/GetPointer.hpp
    Interface/MonsterMovable.hpp
    Interface/PlayerMovable.hpp

    Util/DotManager.hpp
    Util/Map.hpp

    Object/Monster.hpp
    Object/Player.hpp
    Object/Dot.hpp
    Object/GameObject.hpp
    Object/Clyde.hpp
    Object/Blinky.hpp
    Object/Inky.hpp

    State/ChaseState.hpp
    State/ScatterState.hpp
    State/MovementState.hpp
)

set(TEST_FILES
    ut_GamePosition.cpp

)