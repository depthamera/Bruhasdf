#include "renderer.hpp"

Renderer::Renderer() {
    initialize();
}

void Renderer::initialize() {
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info = {0, };
	cursor_info.dwSize = 1;
	cursor_info.bVisible = false;
    SetConsoleCursorInfo(handle, &cursor_info);

    buffer = std::string(" ", BUFFER_SIZE);
    for(int i=GAME_SIZE; i<BUFFER_SIZE; i+=GAME_SIZE) {
        buffer[i] = '\n';
    }
}

static const std::unordered_map<Object, char> obj_char_map = {
    {Object::Empty, 'O'},
    {Object::Snake, 'S'},
    {Object::Apple, 'A'}
};

void Renderer::set_buffer(const std::array<Object, MAP_SIZE> &map) {
    int row = 0;
    for(int i=0; i<MAP_SIZE; i++) {
        buffer[i + row] = obj_char_map.at(map[i]);

        if(i%GAME_SIZE) {
            row++;
        }
    }
}

void Renderer::print_buffer() {
    std::cout << buffer;
}