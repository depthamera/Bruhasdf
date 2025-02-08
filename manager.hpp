#pragma once
#include <windows.h>
#include "game.hpp"
#include "input.hpp"

class Manager {
    bool is_game_running = false;

    static constexpr int GAME_DELAY = 30;
    int tick_counter = 0;

    Game game;
    Key currnet_input = Key::None;

    void loop();
public:
    Manager();
    void start_game();
};