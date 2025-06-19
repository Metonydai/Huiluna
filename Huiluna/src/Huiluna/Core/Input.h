#pragma once

//#include "Huiluna/Core/KeyCodes.h"
//#include "Huiluna/Core/MouseButtonCodes.h"

#include <utility>

namespace Huiluna {
    
    class Input
    {
    public:
        static bool IsKeyPressed(int keycode);

        static bool IsMouseButtonPressed(int button);
        static std::pair<float, float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}