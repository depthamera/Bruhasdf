#pragma once
#include <vector>
#include <array>
#include <random>
#include "utils.hpp"

enum class Direction { None, Up, Down, Left, Right };
enum class Object { Empty, Snake, Apple };

inline constexpr unsigned int GAME_SIZE = 10;
inline constexpr unsigned int MAP_SIZE = GAME_SIZE * GAME_SIZE;

class Game {

    int snake_length = 1;
    Direction snake_dir = Direction::Right;

    std::vector<int> snake_pos;
    int apple_pos = -1;
    bool is_apple_exist = false;

    std::array<Object, MAP_SIZE> map;

    std::random_device random_device;
    std::mt19937 random_generator;

public:
    Game();
    void initialize();
    void update();
    void generate_apple();
    void try_set_snake_direction(Direction dir);
};