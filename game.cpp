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

Game::Game() {
    map = utils::make_array<Object, MAP_SIZE>(Object::Empty);
}

void Game::update() {
    if(!try_move_snake()) {
        Manager::get_instance().stop_game();
    }

    eat_apple();

    if(!is_apple_exist) {
        generate_apple();
    }
}

void Game::eat_apple() {
    if(snake_pos[0] == apple_pos) {
        snake_length++;
        snake_pos.push_back(-1);

        apple_pos = -1;
        is_apple_exist = false;
    }
}

void Game::generate_apple() {
    std::vector<int> empty_pos;
    empty_pos.reserve(MAP_SIZE - snake_length);
    std::unordered_set<int> snake_exclude;

    for(const auto &pos:snake_pos) {
        if(pos != -1) snake_exclude.emplace(pos);
    }

    for(int i=0; i<MAP_SIZE; i++) {
        if(snake_exclude.contains(i)) continue;
        empty_pos.push_back(i);
    }
    
    apple_pos = empty_pos[utils::get_random_int(0, empty_pos.size())];
    is_apple_exist = true;
}



bool Game::try_move_snake() {
    int next_pos = snake_pos[0] + dir_int_map.at(snake_dir);

    if(!is_valid_movement(next_pos)) return false;

    for(int i=3, end = snake_length - 1; i<end; i++) {
        if(snake_pos[i] == next_pos) return false;
    }

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
