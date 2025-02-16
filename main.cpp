#include "game.hpp"
#include "renderer.hpp"

int main() {
    Manager &manager = Manager::get_instance();

    manager.start_game();
}