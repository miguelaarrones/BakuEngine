#pragma once
#include "Baku/Core/Core.h"

#ifdef BK_PLATFORM_WINDOWS

extern Baku::Application* Baku::CreateApplication();

int main(int argc, char** argv)
{
    Baku::Log::Init();

    BK_PROFILE_BEGIN_SESSION("Startup", "BakuProfile-Startup.json");
    auto app = Baku::CreateApplication();
    BK_PROFILE_END_SESSION();

    BK_PROFILE_BEGIN_SESSION("Runtime", "BakuProfile-Runtime.json");
    app->Run();
    BK_PROFILE_END_SESSION();

    BK_PROFILE_BEGIN_SESSION("Shutdown", "BakuProfile-Shutdown.json");
    delete app;
    BK_PROFILE_END_SESSION();
}

#endif
