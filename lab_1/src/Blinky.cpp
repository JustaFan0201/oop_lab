#include "../include/Blinky.hpp"

Blinky::Blinky(std::string id) : Character(0,0,id) {
    this->id = id;
};
Blinky::~Blinky(){};
void Blinky::setPosition(int x,int y) {
    position.x=x;
    position.y=y;
};
void Blinky::doBehavior(Point pacman) {
    int x=position.x;
    int y=position.y;
    if(x<15&&y==0) {
        position = Point(position.x+3, position.y);
    }
    else if(x == 15 && y < 15) {
        position = Point(position.x, position.y+3);
    }
    else if(y==15 && x > 0) {
        position = Point(position.x-3, position.y);
    }
    else {
        position = Point(position.x, position.y-3);
    }
}
