#include "../include/Util.hpp"
#include <iostream>
#include <string>

void Draw(Point BlinkyPoint,Point InkyPoint,Point PinkyPoint,Point ClydePoint,Point PacmanPoint){
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            std::string name = ".....";
            if(BlinkyPoint.x == i && BlinkyPoint.y == j){
                name = "..B..";
            }
            if(InkyPoint.x == i && InkyPoint.y == j){
                name = "..I..";
            }
            if(PinkyPoint.x == i && PinkyPoint.y == j){
                name = "..P..";
            }
            if(ClydePoint.x == i && ClydePoint.y == j){
                name = "..C..";
            }
            if(PacmanPoint.x == i && PacmanPoint.y == j){
                name = "..O..";
            }
            std::cout<<"|"<<name;
            if(j == 15) std::cout<<"|\n";
        }
    }
}