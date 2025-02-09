#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include "game.hpp"

inline constexpr size_t BUFFER_SIZE = MAP_SIZE + GAME_SIZE;

class Renderer {
    HANDLE handle;
    std::string buffer;

    void initialize();

public:
    Renderer();
};