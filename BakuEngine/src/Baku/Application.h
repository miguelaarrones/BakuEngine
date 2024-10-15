#pragma once

#include "Core.h"

namespace Baku
{
	class BAKU_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application *CreateApplication();
}

