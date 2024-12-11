#include "../include/Pinky.hpp"
Pinky::Pinky(std::string id) : Character(0,15,id) {
    this->id = id;
};
Pinky::~Pinky(){};
void Pinky::setPosition(int x,int y) {
    position.x=x;
    position.y=y;
};
void Pinky::doBehavior(Point pacman) {
    int x=position.x;
    int y=position.y;
    if(x==0&&y==15) {
        flag=1;
    }
    if(x==15&&y==0) {
        flag=0;
    }
    if(flag == 1) {
        position = Point(position.x+3, position.y-3);
    }
    else {
        position = Point(position.x-3, position.y+3);
    }
}
