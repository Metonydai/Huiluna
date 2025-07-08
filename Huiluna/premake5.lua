project "Huiluna"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"
    buildoptions { "/utf-8" }

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "hlpch.h"
    pchsource "src/hlpch.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp",
        "vendor/stb_image/**.cpp",
        "vendor/glm/glm/**.hpp",
        "vendor/glm/glm/**.inl",
        "vendor/ImGuizmo/ImGuizmo.h",
        "vendor/ImGuizmo/ImGuizmo.cpp",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "src",
        "vendor/spdlog/include",
        "%{IncludeDir.Box2D}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.entt}",
        "%{IncludeDir.mono}",
        "%{IncludeDir.yaml_cpp}",
        "%{IncludeDir.ImGuizmo}",
        "%{IncludeDir.VulkanSDK}"
    }

    links
    {
        "GLFW",
        "Box2D",
        "Glad",
        "ImGui",
        "yaml-cpp",
        "opengl32.lib",

         "%{Library.mono}"
    }
    
    filter "files:vendor/ImGuizmo/**.cpp"
    flags { "NoPCH" }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "HL_PLATFORM_WINDOWS",
            "HL_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        links
        {
             "%{Library.WinSock}",
             "%{Library.WinMM}",
             "%{Library.WinVersion}",
             "%{Library.BCrypt}"
        }

    filter "configurations:Debug"
        defines "HL_DEBUG"
        runtime "Debug"
        symbols "on"

        links
        {
            "%{Library.ShaderC_Debug}",
            "%{Library.SPIRV_Cross_Debug}",
            "%{Library.SPIRV_Cross_GLSL_Debug}"
        }

    filter "configurations:Release"
        defines "HL_RELEASE"
        runtime "Release"
        optimize "on"

        links
        {
            "%{Library.ShaderC_Release}",
            "%{Library.SPIRV_Cross_Release}",
            "%{Library.SPIRV_Cross_GLSL_Release}"
        }

    filter "configurations:Dist"
        defines "HL_DIST"
        runtime "Release"
        optimize "on"

        links
        {
            "%{Library.ShaderC_Release}",
            "%{Library.SPIRV_Cross_Release}",
            "%{Library.SPIRV_Cross_GLSL_Release}"
        }
