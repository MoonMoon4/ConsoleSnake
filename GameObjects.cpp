#include "GameObjects.h"

GameObject::GameObject(std::vector<int> location_x, std::vector<int> location_y, const char appearance) : ch(appearance) {
    loc[X] = location_x;
    loc[Y] = location_y;
}

/*-----------------------------------------------------*/

Snake::Snake(std::vector<int> location_x, std::vector<int> location_y, const char appearance)
    : GameObject(location_x, location_y, appearance) {}

int Snake::SnakeSize() const {
    if (loc[X].size() == loc[Y].size()) {
        return loc[X].size();
    }
    return -1;
}

/*-----------------------------------------------------*/

Food::Food(std::vector<int> location_x, std::vector<int> location_y, const char appearance)
    : GameObject(location_x, location_y, appearance), food_effects(effects(4 % rand())) {}

void Food::RandomEffects() {
    food_effects = effects(4 % rand());
}