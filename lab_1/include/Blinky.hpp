#ifndef BLINKY_HPP
#define BLINKY_HPP

#include "Character.hpp"

class Blinky:public Character{
private:
public:
    Blinky(std::string id);
    ~Blinky();
    void setPosition(int x,int y)override;

    void doBehavior(Point pacman) override;
};

#endif