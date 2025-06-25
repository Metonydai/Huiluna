workspace "Huiluna"
    architecture "x64"
    startproject "Jerez-Editor"

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

-- Include directories relative to root folders (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Huiluna/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Huiluna/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Huiluna/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Huiluna/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Huiluna/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Huiluna/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Huiluna/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Huiluna/vendor/ImGuizmo"

group "Dependencis"
        include "Huiluna/vendor/GLFW"
        include "Huiluna/vendor/Glad"
        include "Huiluna/vendor/imgui"
        include "Huiluna/vendor/yaml-cpp"
group ""

include "Huiluna"
include "Sandbox"
include "Jerez-Editor"