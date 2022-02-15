#pragma once

#include <vector>

static constexpr int X = 0;
static constexpr int Y = 1;

class GameObject {
  public:
    std::vector<int> loc[2];
    const char ch;

    GameObject(std::vector<int> location_x, std::vector<int> location_y, const char appearance);
};

class Snake : public GameObject {
  public:
    Snake(std::vector<int> location_x, std::vector<int> location_y, const char appearance);
    int SnakeSize() const;
};

class Food : public GameObject {
    enum class effects {
        NO_EFFECTS = 0,
        BOOST,
        POISONING,
        FREEZE
    };
    effects food_effects;

  public:
    Food(std::vector<int> location_x, std::vector<int> location_y, const char appearance);
    void RandomEffects();
};