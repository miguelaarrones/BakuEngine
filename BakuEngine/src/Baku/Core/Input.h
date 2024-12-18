#pragma once

#include "Baku/Core/Core.h"
#include "Baku/Core/KeyCodes.h"
#include "Baku/Core/MouseCodes.h"

namespace Baku
{
    class Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);

        static bool IsMouseButtonPressed(MouseCode button);
        static std::pair<float, float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}