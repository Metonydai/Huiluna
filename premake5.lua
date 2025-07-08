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
        include "Huiluna/vendor/Box2D"
        include "Huiluna/vendor/Glad"
        include "Huiluna/vendor/imgui"
        include "Huiluna/vendor/yaml-cpp"
group ""

group "Core"
    include "Huiluna"
    include "Huiluna-ScriptCore"
group ""

group "Tools"
    include "Jerez-Editor"    
group ""

group "Misc"
    include "Sandbox"
group ""