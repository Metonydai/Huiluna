workspace "Huiluna"
    architecture "x64"
    startproject "Jerez-Editor"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

group "Dependencis"
        project "GLFW"
        project "Glad"
        project "ImGui"

group ""

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folders (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Huiluna/vendor/GLFW/include"
IncludeDir["Glad"] = "Huiluna/vendor/Glad/include"
IncludeDir["ImGui"] = "Huiluna/vendor/imgui"
IncludeDir["glm"] = "Huiluna/vendor/glm"
IncludeDir["stb_image"] = "Huiluna/vendor/stb_image"
IncludeDir["entt"] = "Huiluna/vendor/entt/include"

include "Huiluna/vendor/GLFW"
include "Huiluna/vendor/Glad"
include "Huiluna/vendor/imgui"

project "Huiluna"
    location "Huiluna"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    buildoptions { "/utf-8" }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "hlpch.h"
    pchsource "Huiluna/src/hlpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.entt}"
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
            "HL_PLATFORM_WINDOWS",
            "HL_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "HL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "HL_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "HL_DIST"
        runtime "Release"
        optimize "on"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    buildoptions { "/utf-8" }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Huiluna/vendor/spdlog/include",
        "Huiluna/vendor/",
        "Huiluna/src",
        "%{IncludeDir.glm}",
        "%{IncludeDir.entt}"
    }

    links
    {
        "Huiluna"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "HL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "HL_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "HL_DIST"
        runtime "Release"
        optimize "on"


project "Jerez-Editor"
    location "Jerez-Editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    buildoptions { "/utf-8" }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Huiluna/vendor/spdlog/include",
        "Huiluna/vendor/",
        "Huiluna/src",
        "%{IncludeDir.glm}",
        "%{IncludeDir.entt}"
    }

    links
    {
        "Huiluna"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "HL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "HL_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "HL_DIST"
        runtime "Release"
        optimize "on"