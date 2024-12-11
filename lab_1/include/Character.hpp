#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <memory>
#include <string>

struct Point{
    int x = 0;
    int y = 0;
    Point(int x,int y): x(x),y(y) {}
};
class Character{
  protected:
        Point position;
        std::string id;
    public:
        Character(int x,int y, std::string id);
        virtual ~Character();
        Point getPosition();
        virtual void setPosition(int x,int y)=0;
        virtual void doBehavior(Point pacman)=0;
        std::string getId();
};

#endif