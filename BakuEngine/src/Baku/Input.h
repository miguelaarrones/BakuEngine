#pragma once

#include "Baku/Core.h"

namespace Baku
{
    class BAKU_API Input
    {
    protected:
        Input() = default;
    public:
        Input(const Input&) = delete;
        Input& operator=(const Input&) = delete;

        inline static bool IsKeyPressed(int keyCode) { return s_Instance->IsKeyPressedImpl(keyCode); }
        
        inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
        inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
        inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
        inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

    protected:
        virtual bool IsKeyPressedImpl(int keyCode) = 0;
        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;

    private:
        static Scope<Input> s_Instance;
    };
}