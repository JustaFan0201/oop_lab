#ifndef INKY_HPP
#define INKY_HPP

#include "Character.hpp"

class Inky:public Character{
  private:
    int flag=1;
  public:
    Inky(std::string id);
    ~Inky();
    void setPosition(int x,int y)override;
    void doBehavior(Point pacman)override;
  };
#endif