#ifndef Clyde_HPP
#define Clyde_HPP

#include "Character.hpp"

class Clyde:public Character{
private:
  int flag=1;
public:
  Clyde(std::string id);
  ~Clyde();
  void setPosition(int x,int y)override;
  void doBehavior(Point pacman)override;
};
#endif