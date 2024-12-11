#ifndef PINKY_HPP
#define PINKY_HPP
#include "Character.hpp"

class Pinky:public Character{
private:
  int flag=1;
public:
  Pinky(std::string id);
  ~Pinky();
  void setPosition(int x,int y)override;
  void doBehavior(Point pacman)override;
};
#endif