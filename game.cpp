#include "game.hpp"

Game::Game(): random_generator(random_device()) {
    map = utils::make_array<Object, MAP_SIZE>(Object::Empty);
}

void Game::update() {

}

void Game::generate_apple() {
    int random_pos = -1;

}

void Game::try_set_snake_direction(Direction dir) {
    if(snake_dir == utils::get_opposite_direction(dir)) {
        return;
    }

    snake_dir = dir;
}

