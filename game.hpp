#pragma once
#include <vector>
#include <array>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include "utils.hpp"
#include "manager.hpp"

enum class Direction { None, Up, Down, Left, Right };
enum class Object { Empty, Snake, Apple };

inline constexpr unsigned int GAME_SIZE = 10;
inline constexpr unsigned int MAP_SIZE = GAME_SIZE * GAME_SIZE;

class Game {

    int snake_length = 1;
    Direction snake_dir = Direction::Right;
    static const std::unordered_map<Direction, int> dir_int_map;

    std::vector<int> snake_pos;
    int apple_pos = -1;
    bool is_apple_exist = false;

    std::array<Object, MAP_SIZE> map;

    void initialize();
    void generate_apple();
    void eat_apple();
    bool try_move_snake();
    int get_next_position();
    bool is_valid_movement(int target);
public:
    Game();
    void update();
    bool try_set_snake_direction(Direction dir);
    std::array<Object, MAP_SIZE> get_map();
};