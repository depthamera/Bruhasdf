#pragma once
#include <array>
#include <random>

enum class Direction { Up, Down, Left, Right };
enum class Object { Empty, Snake, Apple };

class Game {
    static constexpr int GAME_SIZE = 10;
    static constexpr int MAP_SIZE = GAME_SIZE * GAME_SIZE;

    int snake_length = 1;
    Direction snake_current_dir = Direction::Right;
    Direction snake_next_dir = Direction::Right;

    std::array<int, MAP_SIZE> snake_pos;
    int apple_pos = -1;
    bool is_apple_exist = false;

    std::array<Object, MAP_SIZE> map(Object::Empty);

    std::random_device random_device;
    std::mt19937 random_generator = std::mt19937(random_device());

public:
    Game();
    void initialize();
    void update();
    void generate_apple();
};