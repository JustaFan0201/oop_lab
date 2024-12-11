#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "Character.hpp"
class Pacman:public Character{
private:
  std::string flag="";
public:
  Pacman(std::string id);
  ~Pacman();
  void setPosition(int x,int y)override;
  void doBehavior(Point pacman)override;
};
#endif