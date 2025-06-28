include "Dependencies.lua"

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

group "Dependencis"
        include "Huiluna/vendor/GLFW"
        include "Huiluna/vendor/Glad"
        include "Huiluna/vendor/imgui"
        include "Huiluna/vendor/yaml-cpp"
group ""

include "Huiluna"
include "Sandbox"
include "Jerez-Editor"