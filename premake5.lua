workspace "BakuEngine"
    architecture "x64"
    startproject "Sandbox"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "BakuEngine"
    location "BakuEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BK_PLATFORM_WINDOWS",
            "BK_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
        }

    filter "configurations:Debug"
        defines "BK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BK_DIST"
        optimize "On"
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "BakuEngine/vendor/spdlog/include",
        "BakuEngine/src"
    }

    links
    {
        "BakuEngine"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines{
            "BK_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "BK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BK_DIST"
        optimize "On"