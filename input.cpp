#include "input.hpp"

Key input::get_input_arrow() {
    Key result = Key::None;

    if(_getch() == 224) {
        switch (_getch())
        {
        case 72:
            result = Key::Up;
            break;
        case 80:
            result == Key::Down;
            break;
        case 75:
            result == Key::Left;
            break;
        case 77:
            result == Key::Right;
            break;
        }
    }
    return result;
}