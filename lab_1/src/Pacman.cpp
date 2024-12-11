#include "../include/Pacman.hpp"
#include <iostream>
Pacman::Pacman(std::string id) : Character(10,10,id) {
    this->id = id;
};
Pacman::~Pacman(){};
void Pacman::setPosition(int x,int y) {
    position.x=x;
    position.y=y;
};
void Pacman::doBehavior(Point pacman) {
    std::cin>>flag;
    if(flag=="W") {
        if(position.x-3<0) {
            position.x=0;
        }
        else {
            position.x-=3;
        }
    }
    else if(flag=="A") {
        if(position.y-3<0) {
            position.y=0;
        }
        else {
            position.y-=3;
        }
    }
    else if(flag=="S") {
        if(position.x+3>15) {
            position.x=15;
        }
        else {
            position.x+=3;
        }
    }
    else if(flag=="D") {
        if(position.y+3>15) {
            position.y=15;
        }
        else {
            position.y+=3;
        }
    }
}