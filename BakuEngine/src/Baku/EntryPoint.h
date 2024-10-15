#pragma once

#ifdef BK_PLATFORM_WINDOWS

extern Baku::Application* Baku::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Baku::CreateApplication();
	app->Run();
	delete app;
}

#endif
