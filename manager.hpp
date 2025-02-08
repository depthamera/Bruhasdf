#pragma once
#include <windows.h>
#include "game.hpp"

class Manager {
    bool is_running = false;
    
    static constexpr int GAME_DELAY = 30;
    int counter = 0;

    Game game;

    void loop();
public:
    Manager();
    void start_game();
};