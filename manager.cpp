#include "manager.hpp"

Manager::Manager(): game(Game()) {

}

void Manager::start_game() {
    is_running = true;
    loop();
}

void Manager::loop() {
    while(is_running) {
        
    }
}