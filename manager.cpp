#include "manager.hpp"

Manager::Manager(): game(Game()) {

}

void Manager::start_game() {
    is_game_running = true;
    loop();
}

void Manager::loop() {
    currnet_input = input::get_input_arrow();

    while(is_game_running) {
        

        if(++tick_counter == GAME_DELAY) {
            
            game.update();
            tick_counter = 0;
        }
    }
}