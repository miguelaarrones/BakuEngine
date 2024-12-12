#pragma once

#include "Baku/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Baku {
    class Log
    {
    public:
        static void Init();

        static Ref<spdlog::logger> &GetCoreLogger() { return s_CoreLogger;  }
        static Ref<spdlog::logger> &GetClientLogger() { return s_ClientLogger;  }

    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define BK_CORE_ERROR(...)        ::Baku::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BK_CORE_WARN(...)         ::Baku::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BK_CORE_INFO(...)         ::Baku::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BK_CORE_TRACE(...)        ::Baku::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BK_CORE_CRITICAL(...)     ::Baku::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define BK_ERROR(...)      ::Baku::Log::GetClientLogger()->error(__VA_ARGS__)
#define BK_WARN(...)       ::Baku::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BK_INFO(...)       ::Baku::Log::GetClientLogger()->info(__VA_ARGS__)
#define BK_TRACE(...)      ::Baku::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BK_CRITICAL(...)   ::Baku::Log::GetClientLogger()->critical(__VA_ARGS__)
