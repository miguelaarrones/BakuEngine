#pragma once

#ifdef BK_PLATFORM_WINDOWS
	#ifdef BK_BUILD_DLL
		#define BAKU_API __declspec(dllexport)
	#else
		#define BAKU_API __declspec(dllimport)
	#endif
#else
	#error Baku Engine only supports Windows!
#endif

#define BIT(x) (1 << x)