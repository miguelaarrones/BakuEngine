#include "bkpch.h"
#include "Baku/Core/Input.h"

#ifdef BK_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace Baku
{
	Scope<Input> Input::s_Instance = Input::Create();
	Scope<Input> Input::Create()
	{
#ifdef BK_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		BK_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}