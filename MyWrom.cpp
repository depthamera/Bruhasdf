#include <iostream>
#include <string>
#include <random>
#include <windows.h>

constexpr int GAME_SIZE = 10;
constexpr int MAP_SIZE = GAME_SIZE * GAME_SIZE;

enum Object {
    Empty = 0,
    Snake = 1,
    Apple = 2
};
constexpr char object_char[] = {'.', 'S', 'A'};

enum Direction {
    Left,
    Right,
    Up,
    Down
};

Object map[MAP_SIZE];
int snake_pos[MAP_SIZE] = {MAP_SIZE / 2, };

std::string visual_map(MAP_SIZE + GAME_SIZE, '\n');

int snake_size = 1;

Direction current_dir;

int apple_pos = 0;

std::random_device random_device;
std::mt19937 random_generator;

std::vector<int> available_pos;

void initialize() {
    for(int i=GAME_SIZE; i<MAP_SIZE; i+=GAME_SIZE) {
        visual_map[i-1] = 'd';
        visual_map[i] = '\n';
    }

    random_generator = std::mt19937(random_device());
}

int move(int origin, Direction dir) {
    int result = origin;

    switch(dir) {
        case Left:
            result++;
            break;
        case Right:
            result--;
            break;
        case Up:
            result += GAME_SIZE;
            break;
        case Down:
            result -= GAME_SIZE;
            break;        
    }

    return result;
}

bool is_valid_move(int origin, int target, Direction dir) {
    bool result = false;

    switch (dir)
    {
        case Left:
        case Right:
            result = (origin/GAME_SIZE == target/GAME_SIZE);
            break;
        case Up:
        case Down:
            result = (target >= 0 && target < MAP_SIZE);
            break;
    }

    return result;
}

int move_head(Direction dir) {
    int target = move(snake_pos[0], dir);

    if(!is_valid_move(snake_pos[0], target, dir)) {
        return -1;
    }

    snake_pos[0] = target;

    return 0;
}

void track_head(int index, int parent_pos) {
    if(index == snake_size) return;

    int prev_pos = snake_pos[index];
    snake_pos[index] = parent_pos;

    track_head(index+1, prev_pos);   
}

int get_random_int(int min, int max) {
    return std::uniform_int_distribution<int>{min, max}(random_generator);
}

int get_random_from_vector(const std::vector<int>& vector) {
    return vector[get_random_int(0, vector.size() - 1)];
}

void generate_apple() {
    available_pos.clear();
    
    for(int i=0; i<MAP_SIZE; i++) {
        if(map[i] == Empty) {
            available_pos.push_back(i);
        }
    }

    apple_pos = get_random_from_vector(available_pos);
}

void check_apple() {
    if(snake_pos[0] == apple_pos) {
        map[apple_pos] = Empty;
        snake_size++;
        generate_apple();
    }
}

void build_map() {
    for(int i=0; i<MAP_SIZE; i++) {
        map[i] = Empty;
    }

    for(int i=0; i<snake_size; i++) {
        map[snake_pos[i]] = Snake;
    }

    map[apple_pos] = Apple;
}

void build_visual_map() {
    for(int i=0; i<MAP_SIZE; i++) {
        visual_map[i + i/GAME_SIZE] = object_char[map[i]];
    }
}

void update() {
    move_head(current_dir);
    check_apple();
    track_head(1, snake_pos[0]);
    build_map();
    build_visual_map();
}

int main() {
    initialize();
    update();
    std::cout << visual_map;
    system("pause");
    return 0;
}