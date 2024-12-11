workspace "BakuEngine"
    architecture "x86_64"
    startproject "Sandbox"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }
    
    flags
	{
		"MultiProcessorCompile"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "BakuEngine/vendor/GLFW/include"
IncludeDir["spdlog"] = "BakuEngine/vendor/spdlog/include"
IncludeDir["Glad"] = "BakuEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "BakuEngine/vendor/imgui"
IncludeDir["glm"] = "BakuEngine/vendor/glm"
IncludeDir["stb_image"] = "BakuEngine/vendor/stb_image"

-- Include premake files
group "Dependencies"
    include "BakuEngine/vendor/GLFW"
    include "BakuEngine/vendor/Glad"
    include "BakuEngine/vendor/imgui"

group ""

project "BakuEngine"
    location "BakuEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "bkpch.h"
    pchsource "BakuEngine/src/bkpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

    includedirs 
    {
        "%{prj.name}/src",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "BK_PLATFORM_WINDOWS",
            "BK_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "BK_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "BK_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "BK_DIST"
        runtime "Release"
        optimize "On"
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "On"

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
        "BakuEngine/src",
        "BakuEngine/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "BakuEngine"
    }

    filter "system:windows"
        systemversion "latest"

        defines{
            "BK_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "BK_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "BK_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "BK_DIST"
        runtime "Release"
        optimize "On"
