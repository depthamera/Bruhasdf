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

int move_head(Direction dir) {
    
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