#include "Application.h"

#include "Baku/Events/ApplicationEvent.h"
#include "Baku/Log.h"

namespace Baku
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		BK_TRACE(e.ToString());

		while (true);
	}
}
