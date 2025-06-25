project "Jerez-Editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    buildoptions { "/utf-8" }

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/Huiluna/vendor/spdlog/include",
        "%{wks.location}/Huiluna/vendor/",
        "%{wks.location}/Huiluna/src",
        "%{IncludeDir.glm}",
        "%{IncludeDir.entt}",
        "%{IncludeDir.ImGuizmo}"
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
