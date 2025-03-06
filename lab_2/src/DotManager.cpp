#include "Util/DotManager.hpp"

namespace Util {
DotManager::DotManager(
    std::shared_ptr<Object::Player>   player,
    std::vector<Object::GamePosition> pos
)
    : player(player),
      points_pos(pos) {
    for (auto& pos_elem : points_pos) {
        points.push_back(std::make_shared<Object::Dot>(pos_elem));
    }
};

DotManager::~DotManager() = default;

std::vector<std::shared_ptr<Object::Dot>> DotManager::GetPointList() {
    return points;
}

std::size_t DotManager::GetPointListSize() {
    return points.size();
}

bool DotManager::IsOverlapping() {
    for (auto& point : points) {
        if (point->GetPosition().x == player->GetPosition().x
            && point->GetPosition().y == player->GetPosition().y) {
            points.erase(
                std::remove(points.begin(), points.end(), point),
                points.end()
            );
            return true;
            }
    }
    return false;
}
}  // namespace Util
