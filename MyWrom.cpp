#include <iostream>
#include <string>
#include <random>
#include <conio.h>
#include <windows.h>

constexpr int GAME_SIZE = 10;
constexpr int MAP_SIZE = GAME_SIZE * GAME_SIZE;
constexpr int GAME_DELAY = 15;

HANDLE handle;

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

Direction current_dir = Right;
Direction next_dir = Right;

int apple_pos = -1;
bool is_apple_generated = false;

std::random_device random_device;
std::mt19937 random_generator;

std::vector<int> available_pos;

void initialize() {
    handle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursor_info = {0, };
	cursor_info.dwSize = 1;
	cursor_info.bVisible = false;
    SetConsoleCursorInfo(handle, &cursor_info);


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
            result--;
            break;
        case Right:
            result++;
            break;
        case Up:
            result -= GAME_SIZE;
            break;
        case Down:
            result += GAME_SIZE;
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
            result &= (target >= 0 && target < MAP_SIZE);
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
    is_apple_generated = true;
}

void check_apple() {
    if(snake_pos[0] == apple_pos) {
        is_apple_generated = false;
        map[apple_pos] = Empty;
        snake_size++;
    }
}

void build_map() {
    for(int i=0; i<MAP_SIZE; i++) {
        map[i] = Empty;
    }

    for(int i=0; i<snake_size; i++) {
        map[snake_pos[i]] = Snake;
    }
}

void build_visual_map() {
    for(int i=0; i<MAP_SIZE; i++) {
        visual_map[i + i/GAME_SIZE] = object_char[map[i]];
    }
}

void print_screen() {
    SetConsoleCursorPosition(handle, {0, 0});
    std::cout << visual_map;
}   

void update() {
    int prev_head_pos = snake_pos[0];
    current_dir = next_dir;
    move_head(current_dir);
    check_apple();
    track_head(1, prev_head_pos);
    build_map();
    if(!is_apple_generated) {
        generate_apple();
    }
    map[apple_pos] = Apple;
    build_visual_map();
    print_screen();
    std::cout << snake_pos[0];
}

void start_loop() {
    int count = 0;
    int key = 0;

    while(true) {
        count++;
        
        if(_kbhit() && getch() == 224) {
            switch(key = _getch()) {
                case 75:
                    if(current_dir == Right) break;
                    next_dir = Left;
                    break;
                case 77:
                    if(current_dir == Left) break;
                    next_dir = Right;
                    break;
                case 72:
                    if(current_dir == Down) break;
                    next_dir = Up;
                    break;
                case 80:
                    if(current_dir == Up) break;
                    next_dir = Down;
                    break;
            }
        }

        if(count == 15) {
            update();
            count = 0;
        }

        Sleep(GAME_DELAY);
    }
}
int main() {
    initialize();
    start_loop();
    return 0;
}