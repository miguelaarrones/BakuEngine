#include <Baku.h>

class Sandbox : public Baku::Application
{
public:
    Sandbox()
    {

    }
    ~Sandbox()
    {

    }
};

Baku::Application* Baku::CreateApplication()
{
    return new Sandbox();
}