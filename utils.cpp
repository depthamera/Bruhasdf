#include "utils.hpp"

int utils::get_random_int(const int& min, const int& max, const std::mt19937& generator) {
    return std::uniform_int_distribution<int>{min, max}(generator);
}

Direction utils::get_opposite_direction(Direction dir) {
    switch (dir) {
    case Direction::Up:
        return Direction::Down;

    case Direction::Down:
        return Direction::Up;

    case Direction::Left:
        return Direction::Right;
        
    case Direction::Right:
        return Direction::Left;
    }

    return Direction::None;
}