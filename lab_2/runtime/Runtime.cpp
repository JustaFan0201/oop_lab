#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Interface/MonsterMovable.hpp"
#include "Object/GameObject.hpp"
#include "Util/Map.hpp"
#include "Util/RuntimeFramework.hpp"

namespace Util {

void RuntimeFramework::Initial() {
    state = RuntimeState::INITIAL;
    game_objects.clear();
    game_objects.push_back(blinky);
    game_objects.push_back(clyde);
    game_objects.push_back(inky);
    game_objects.push_back(pinky);
    game_objects.push_back(player);
    std::vector<std::shared_ptr<Object::Dot>> dots
    = point_manager->GetPointList();
    for (int i=0;i<point_manager->GetPointListSize();i++){
        game_objects.push_back(dots[i]);
    }
}

void RuntimeFramework::Running() {
    state = RuntimeState::RUNNING;
    int flag = 0;
    std::string action;
    while (flag != 1){
        std::cin>>action;
        flag = 1;
        if (action == "c"){
            std::cout<<"Switch to Chase"<<std::endl;
            blinky->SetState(Object::MonsterState::Chase);
            clyde->SetState(Object::MonsterState::Chase);
            inky->SetState(Object::MonsterState::Chase);
            pinky->SetState(Object::MonsterState::Chase);
        }
        else if (action == "x"){
            std::cout<<"Switch to Scatter"<<std::endl;
            blinky->SetState(Object::MonsterState::Scatter);
            clyde->SetState(Object::MonsterState::Scatter);
            inky->SetState(Object::MonsterState::Scatter);
            pinky->SetState(Object::MonsterState::Scatter);
        }
        else if (action == "w"){
            player->Move('w');
        }
        else if (action == "a"){
            player->Move('a');
        }
        else if (action == "s"){
            player->Move('s');
        }
        else if (action == "d"){
            player->Move('d');
        }
        else{
            std::cout<<"Invalid action, please enter again"<<std::endl;
            flag = 0;
        }
    }
    if (point_manager->IsOverlapping()){
        Initial();
    }

    Object::GamePosition playerPos = player->GetPosition();
    blinky->Move(playerPos);
    clyde->Move(playerPos);
    inky->Move(playerPos);
    pinky->Move(playerPos);

    for (int i=0;i<4;i++){
        if (game_objects[i]->GetPosition() == playerPos){
            state = RuntimeState::END;
            break;
        }
    }
    if(point_manager->GetPointListSize()==0) {
        state = RuntimeState::END;
    }
}

void RuntimeFramework::Render() {
    Map::Draw(game_objects);
}

void RuntimeFramework::End() {
    if (point_manager->GetPointListSize() == 0){

        std::cout<<"You Win"<<std::endl;
    }
    else{
        std::cout<<"You Lose"<<std::endl;
    }
    exit(0);
}
};  // namespace Util


