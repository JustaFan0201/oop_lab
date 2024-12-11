#include "../include/Clyde.hpp"

Clyde::Clyde(std::string id) : Character(7,7,id) {
    this->id = id;
};
Clyde::~Clyde(){};
void Clyde::setPosition(int x,int y) {
    position.x=x;
    position.y=y;
};
/*void Clyde::doBehavior(Point pacman){
    int y=position.y-pacman.y;
    int x=position.x-pacman.x;
    if(pacman.y==position.y) {
        if(y>0) {
            if(position.x-2<0) {
                position.x=0;
            }
            else {
                position.x-=2;
            }
        }
        else {
            if(position.x+2>15) {
                position.x=15;
            }
            else {
                position.x+=2;
            }
        }
    }
    else if(pacman.x==position.x) {
        if(x>0) {
            if(position.y-2<0) {
                position.y=0;
            }
            else {
                position.y-=2;
            }
        }
        else {
            if(position.y+2>15) {
                position.y=15;
            }
            else {
                position.y+=2;
            }
        }
    }
    else {
        if(y>0&&x>0) {
            if(position.x-3<0) {
                position.x=0;
            }
            else {
                position.x-=3;
            }
            if(position.y-3<0) {
                position.y=0;
            }
            else {
                position.y-=3;
            }
        }
        else if(y<0&&x>0) {
            if(position.x-3<0) {
                position.x=0;
            }
            else {
                position.x-=3;
            }
            if(position.y+3>15) {
                position.y=15;
            }
            else {
                position.y+=3;
            }
        }
        else if(y<0&&x<0) {
            if(position.x+3>15) {
                position.x=15;
            }
            else {
                position.x+=3;
            }
            if(position.y+3>15) {
                position.y=15;
            }
            else {
                position.y+=3;
            }
        }
        else {
            if(position.x+3>15) {
                position.x=15;
            }
            else {
                position.x+=3;
            }
            if(position.y-3<0) {
                position.y=0;
            }
            else {
                position.y-=3;
            }
        }
    }
}*/
void Clyde::doBehavior(Point pacman) {
    position.x=pacman.x;
    position.y=pacman.y;
}