#pragma once
#include <vector>
#include <array>
#include <random>
#include "game.hpp"

namespace utils {
    template<typename T, std::size_t N>
    constexpr std::array<T, N> make_array(const T& value) {
        std::array<T, N> result;
        for(auto& e: temp) {
            e = value;
        }
        return result
    }

    int get_random_int(int min, int max);

    Direction get_opposite_direction(Direction dir);

    
}