#include "State/ChaseState.hpp"
#include "iostream"
#include <random>
namespace State {
Object::GamePosition ChaseState::Behavior(
    GhostType            type,
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    if (type == GhostType::BLINKY){
        pos = Blinky(pos,playerPos);
    }
    else if (type == GhostType::INKY){
        pos = Inky(pos,playerPos);
    }
    else if (type == GhostType::PINKY){
        pos = Pinky(pos,playerPos);
    }
    else{
        pos = Clyde(pos,playerPos);
    }
    return pos;
}

bool ChaseState::IsOutRange(Object::GamePosition pos) {
    if (pos.x > 11){
        return false;
    }
    else if (pos.x < 0){
        return false;
    }

    if (pos.y > 11){
        return false;
    }
    else if (pos.y < 0){
        return false;
    }
    return true;
}

Object::GamePosition ChaseState::Blinky(


    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    Object::GamePosition ori=pos;
    if (pos.x > playerPos.x) pos.x--;
    else if (pos.x < playerPos.x) pos.x++;

    if (pos.y > playerPos.y) pos.y--;
    else if (pos.y < playerPos.y) pos.y++;
    if(IsOutRange(pos)==0) {
        return ori;
    }
    return pos;
}

Object::GamePosition ChaseState::Clyde(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    Object::GamePosition ori=pos;
    int x_range1 = pos.x + 4;
    int x_range2 = pos.x - 4;
    int y_range1 = pos.y + 4;
    int y_range2 = pos.y - 4;
    int rand[3] = {-1,0,1};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2);
    int random_number;

    if (x_range2 < pos.x && pos.x < x_range1){
        if (pos.x > playerPos.x){
            pos.x -= 1;
        }
        else if (pos.x < playerPos.x){
            pos.x += 1;
        }
    }
    else{
        random_number = distrib(gen);
        pos.x += rand[random_number];
    }

    if (y_range2 < pos.y && pos.y < y_range1){
        if (pos.y > playerPos.y){
            pos.y -= 1;
        }
        else if (pos.y < playerPos.y){
            pos.y += 1;
        }
    }
    else{
        random_number = distrib(gen);
        pos.y += rand[random_number];
    }
    if(IsOutRange(pos)==0) {
        return ori;
    }
    return pos;
}

Object::GamePosition ChaseState::Inky(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    Object::GamePosition target = playerPos + (playerPos - pos);
    Object::GamePosition ori=pos;
    if (pos.x > target.x) pos.x--;
    else if (pos.x < target.x) pos.x++;

    if (pos.y > target.y) pos.y--;
    else if (pos.y < target.y) pos.y++;
    if(IsOutRange(pos)==0) {
        return ori;
    }
    return pos;
}

Object::GamePosition ChaseState::Pinky(
    Object::GamePosition pos,
    Object::GamePosition playerPos
) {
    Object::GamePosition target = playerPos;
    target.x += 4;
    Object::GamePosition ori=pos;
    if (pos.x > target.x) pos.x--;
    else if (pos.x < target.x) pos.x++;

    if (pos.y > target.y) pos.y--;
    else if (pos.y < target.y) pos.y++;
    if(IsOutRange(pos)==0) {
        return ori;
    }
    return pos;
}
}  // namespace State