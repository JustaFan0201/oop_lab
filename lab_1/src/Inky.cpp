#include "../include/Inky.hpp"
Inky::Inky(std::string id) : Character(15,15,id) {
    this->id = id;
};
Inky::~Inky(){};
void Inky::setPosition(int x,int y) {
    position.x=x;
    position.y=y;
};
void Inky::doBehavior(Point pacman) {
    int x=position.x;
    int y=position.y;
    if(x==15&&y==15) {
        flag=0;
    }
    if(y==0&&x==0) {
        flag=1;
    }
    if(flag == 1) {
        position = Point(position.x+3, position.y+3);
    }
    else {
        position = Point(position.x-3, position.y-3);
    }
}

