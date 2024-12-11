#pragma once

#include "Baku/Core/Input.h"

namespace Baku
{
    class WindowsInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(KeyCode keyCode) override;
        virtual bool IsMouseButtonPressedImpl(MouseCode button) override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
    };
}

