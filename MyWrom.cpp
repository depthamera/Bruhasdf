#include <iostream>
#include <string>
#include <windows.h>

constexpr int POW(const int& value) {
    return value * value;
}

constexpr int GAME_SIZE = 10;
constexpr int MAP_SIZE = POW(GAME_SIZE);

constexpr int MAP[MAP_SIZE];
constexpr int SNAKE_DATA[MAP_SIZE];

std::string visual_map;

int snake_size = 1;

void initialize() {
    visual_map.reserve(MAP_SIZE + GAME_SIZE);
    for(int i=GAME_SIZE; i<MAP_SIZE; i+=GAME_SIZE) {
        visual_map[i] = '\n';
    }
}

void build_visual_map() {
    for(int i=0; i<MAP_SIZE; i++) {
        switch(MAP[i]) {
            case 1:
                visual_map[i + i%GAME_SIZE] = '0';
                break;
            default:
        }
    }
}

int main() {
    initialize();


}