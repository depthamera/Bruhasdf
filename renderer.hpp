#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include "game.hpp"

class Renderer {
    HANDLE handle;
    std::string buffer;

    void initialize();

public:
    Renderer();
};