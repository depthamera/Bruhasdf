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
}