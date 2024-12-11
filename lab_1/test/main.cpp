#include "Util.hpp"

#include <Blinky.hpp>
#include <Inky.hpp>
#include <Pacman.hpp>
#include <Pinky.hpp>
#include <Clyde.hpp>
#include <vector>
#include <array>
#include <cstdlib>


void manager(Point BlinkyPoint,Point InkyPoint,Point PinkyPoint,Point ClydePoint,Point PacmanPoint) {
    std::vector<Point> enemies = {BlinkyPoint, InkyPoint, PinkyPoint, ClydePoint};
    for(auto p : enemies) {
        if(PacmanPoint.x==p.x && PacmanPoint.y==p.y) {
            printf("your loss");
            exit(0);
        }
    }
}
int main(){
    std::shared_ptr<Character> blinky = std::make_shared<Blinky>("B");
    std::shared_ptr<Character> inky = std::make_shared<Inky>("I");
    std::shared_ptr<Character> pinky = std::make_shared<Pinky>("P");
    std::shared_ptr<Character> clyde = std::make_shared<Clyde>("C");
    std::shared_ptr<Character> pacman = std::make_shared<Pacman>("O");
    Draw(blinky->getPosition(),inky->getPosition(),pinky->getPosition(),clyde->getPosition(),pacman->getPosition());
    std::vector<std::shared_ptr<Character>> characters = {blinky, inky, pinky, pacman,clyde};
    for(int i=0;i<50;i++) {
        for(auto character:characters) {
            character->doBehavior(pacman->getPosition());
        }
        Draw(blinky->getPosition(),inky->getPosition(),pinky->getPosition(),clyde->getPosition(),pacman->getPosition());
        printf("--------------------------------------\n");
        for(auto character:characters) {
            Point find = character->getPosition();
            printf("%s %i %i \n",character->getId().c_str(),character->getPosition().x,character->getPosition().y);
        }
        manager(blinky->getPosition(),inky->getPosition(),pinky->getPosition(),clyde->getPosition(),pacman->getPosition());
    }
    printf("ggez");
}