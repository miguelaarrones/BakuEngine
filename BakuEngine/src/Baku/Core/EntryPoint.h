#pragma once

#ifdef BK_PLATFORM_WINDOWS

extern Baku::Application* Baku::CreateApplication();

int main(int argc, char** argv)
{
    Baku::Log::Init();

    BK_CORE_WARN("Initialized log!");
    int a = 5;
    BK_INFO("Hello! Var={0}", a);

    auto app = Baku::CreateApplication();
    app->Run();
    delete app;
}

#endif
