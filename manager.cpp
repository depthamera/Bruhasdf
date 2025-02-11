#include "manager.hpp"

Manager::Manager(): game(Game()), renderer(Renderer()) {

}

void Manager::start_game() {
    is_game_running = true;
    loop();
}

const std::unordered_map<Key, Direction> Manager::key_dir_map = {
    {Key::Up, Direction::Up},
    {Key::Down, Direction::Down},
    {Key::Left, Direction::Left},
    {Key::Right, Direction::Right}
};

void Manager::loop() {
    while(is_game_running) {
        current_input = input::get_input_arrow();

        if(++tick_counter == GAME_DELAY) {
            game.try_set_snake_direction(key_dir_map.at(current_input));
            game.update();
            
            renderer.set_buffer(game.get_map());
            renderer.print_buffer();
            tick_counter = 0;
        }
    }
}