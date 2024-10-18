#include <Baku.h>

class ExampleLayer : public Baku::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    { }

    void OnUpdate() override
    {
        BK_INFO("ExampleLayer::Update");
    }

    void OnEvent(Baku::Event& event) override
    {
        BK_TRACE("{0}", event.ToString());
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