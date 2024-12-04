#pragma once

#include <memory>

#ifdef BK_PLATFORM_WINDOWS
    #if BK_DYNAMIC_LINK
        #ifdef BK_BUILD_DLL
            #define BAKU_API __declspec(dllexport)
        #else
            #define BAKU_API __declspec(dllimport)
        #endif
    #else
        #define BAKU_API
    #endif
#else
    #error Baku Engine only supports Windows!
#endif

#ifdef BK_DEBUG
    #define BK_ENABLE_ASSERTS
#endif

#ifdef BK_ENABLE_ASSERTS
    #define BK_ASSERT(x, ...) { if(!(x)) { BK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define BK_CORE_ASSERT(x, ...) { if(!(x)) { BK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define BK_ASSERT(x, ...)
    #define BK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Baku
{
    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T>
    using Ref = std::shared_ptr<T>;
}