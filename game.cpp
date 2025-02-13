#include "game.hpp"

const std::unordered_map<Direction, int> Game::dir_int_map = {
    {Direction::Up, -GAME_SIZE},
    {Direction::Down, +GAME_SIZE},
    {Direction::Left, -1},
    {Direction::Down, 1},
};

bool Game::is_valid_movement(int target) {
    if(target < 0 || target >= MAP_SIZE) return false;

    if(snake_dir == Direction::Left || snake_dir == Direction::Right) {
        return snake_pos[0] % GAME_SIZE == target % GAME_SIZE;
    }

    return true;
}

Game::Game(): random_generator(random_device()) {
    map = utils::make_array<Object, MAP_SIZE>(Object::Empty);
}

void Game::update() {
    
}

void Game::generate_apple() {
    int random_pos = -1;

}

bool Game::try_move_snake() {
    int next_pos = snake_pos[0] + dir_int_map.at(snake_dir);

    if(!is_valid_movement(next_pos)) return false;

    for(int i=1; i<snake_length; i++) {
        snake_pos[i] = snake_pos[i-1];
    }
    snake_pos[0] = next_pos;
    
    return true;
}

bool Game::try_set_snake_direction(Direction dir) {
    if(snake_dir == utils::get_opposite_direction(dir)) {
        return false;
    }

    snake_dir = dir;
    return true;
}

std::array<Object, MAP_SIZE> Game::get_map() {
    return map;
}
