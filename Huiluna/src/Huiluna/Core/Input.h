#pragma once

#include "Huiluna/Core/KeyCodes.h"
#include "Huiluna/Core/MouseButtonCodes.h"

#include <utility>


namespace Huiluna {
    
    class Input
    {
    public:
        static bool IsKeyPressed(KeyCode keycode);

        static bool IsMouseButtonPressed(MouseCode button);
        static std::pair<float, float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}