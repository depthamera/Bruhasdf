#pragma once
#include <conio.h>

enum class Key {
    None = 0,
    Up = 72,
    Down = 80,
    Left = 75,
    Right = 77
};

namespace input {
    Key get_input_arrow();
}