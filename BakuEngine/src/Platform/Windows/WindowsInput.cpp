#include "bkpch.h"
#include "Platform/Windows/WindowsInput.h"

#include "Baku/Core/Application.h"

#include <GLFW/glfw3.h>

namespace Baku
{
    bool WindowsInput::IsKeyPressedImpl(KeyCode keyCode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, static_cast<int32_t>(keyCode));

        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(MouseCode button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));

        return state == GLFW_PRESS;
    }

    float WindowsInput::GetMouseXImpl()
    {
        auto [x, y] = GetMousePosition();
        return x;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto [x, y] = GetMousePosition();
        return y;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        return { (float)xPos, (float)yPos };
    }
}