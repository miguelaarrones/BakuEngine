#include <Baku.h>

#include "imgui/imgui.h"

class ExampleLayer : public Baku::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    { }

    void OnUpdate() override
    {
        if (Baku::Input::IsKeyPressed(BK_KEY_TAB))
            BK_TRACE("Tab key is pressed! (Poll)");
    }

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World!");
        ImGui::End();
    }

    void OnEvent(Baku::Event& event) override
    {
        if (event.GetEventType() == Baku::EventType::KeyPressed)
        {
            Baku::KeyPressedEvent& e = (Baku::KeyPressedEvent&)event;
            if (e.GetKeyCode() == BK_KEY_TAB)
            {
                BK_TRACE("Tab key is pressed! (Event)");
            }

            BK_TRACE("{0}", (char)e.GetKeyCode());
        }
    }
};

class Sandbox : public Baku::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }
    ~Sandbox()
    {

    }
};

Baku::Application* Baku::CreateApplication()
{
    return new Sandbox();
}