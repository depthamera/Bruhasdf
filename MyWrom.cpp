#include <iostream>
#include <string>
#include <windows.h>

constexpr int GAME_SIZE = 10;
constexpr int MAP_SIZE = GAME_SIZE * GAME_SIZE;

enum Object {
    Empty = 0,
    Snake = 1,
    Apple = 2
};

enum Direction {
    Left,
    Right,
    Up,
    Down
};

Object map[MAP_SIZE];
int snake_data[MAP_SIZE];

std::string visual_map;

int snake_size = 1;


void initialize() {
    visual_map.reserve(MAP_SIZE + GAME_SIZE);
    for(int i=GAME_SIZE; i<MAP_SIZE; i+=GAME_SIZE) {
        visual_map[i] = '\n';
    }
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
            result = (origin%GAME_SIZE == target%GAME_SIZE);
            break;
        case Up:
        case Down:
            result = (target >= 0 && target < MAP_SIZE);
            break;
    }

    return result;
}

int move_head(Direction dir) {
    int target = move(snake_data[0], dir);

    if(!is_valid_move(snake_data[0], target, dir)) {
        return -1;
    }

    return 0;
}

void track_head(int index, int parent_pos) {
    if(index == snake_size) return;

    int prev_pos = snake_data[index];
    snake_data[index] = parent_pos;

    track_head(index+1, prev_pos);   
}

void build_visual_map() {
    for(int i=0; i<MAP_SIZE; i++) {
        switch(map[i]) {
            case Empty:
                visual_map[i + i%GAME_SIZE] = '0';
                break;
            case Snake:
                visual_map[i + i%GAME_SIZE] = '1';
                break;
            case Apple:
                visual_map[i + i%GAME_SIZE] = '2';
                break;
            default:
        }
    }
}

int main() {
    initialize();
}