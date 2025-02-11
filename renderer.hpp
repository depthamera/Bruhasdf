#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include "game.hpp"

inline constexpr size_t BUFFER_SIZE = MAP_SIZE + GAME_SIZE;

class Renderer {
    HANDLE handle;
    std::string buffer;

    void initialize();
    static const std::unordered_map<Object, char> obj_char_map;

public:
    Renderer();
    void set_buffer(const std::array<Object, MAP_SIZE> &map);
    void print_buffer();
};