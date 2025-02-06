#include "game.hpp"
#include "utils.hpp"

Game::Game(): random_generator(random_device()) {
    map = utils::make_array<Object, MAP_SIZE>(Object::Empty);
}

void Game::update() {

}

void Game::generate_apple() {
    int random_pos = -1;

    
}

