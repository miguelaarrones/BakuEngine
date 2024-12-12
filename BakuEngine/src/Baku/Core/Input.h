#pragma once

#include "Baku/Core/Core.h"
#include "Baku/Core/KeyCodes.h"
#include "Baku/Core/MouseCodes.h"

namespace Baku
{
    class Input
    {
    protected:
        Input() = default;
    public:
        virtual ~Input() = default;
        
        Input(const Input&) = delete;
        Input& operator=(const Input&) = delete;

        static bool IsKeyPressed(KeyCode key) { return s_Instance->IsKeyPressedImpl(key); }
        
        static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
        static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
        static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
        static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

        static Scope<Input> Create();
    protected:
        virtual bool IsKeyPressedImpl(KeyCode  key) = 0;
        virtual bool IsMouseButtonPressedImpl(MouseCode button) = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;

    private:
        static Scope<Input> s_Instance;
    };
}