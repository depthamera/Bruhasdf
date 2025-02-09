#pragma once
#include <windows.h>
#include <unordered_map>
#include "game.hpp"
#include "input.hpp"
#include "renderer.hpp"

class Manager {
    bool is_game_running = false;

    static constexpr int GAME_DELAY = 30;
    int tick_counter = 0;

    Game game;
    Key current_input = Key::None;
    static const std::unordered_map<Key, Direction> key_dir_map;

    void loop();
public:
    Manager();
    void start_game();
};