#include "utils.hpp"

int utils::get_random_int(const int& min, const int& max, const std::mt19937& generator) {
    return std::uniform_int_distribution<int>{min, max}(generator);
}