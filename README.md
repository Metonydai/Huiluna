# Huiluna
Huiluna Engine is a personal project aimed at building a fundamental game engine from scrapt program, guided by the detailed tutorials of YouTube videos, [thecherno.com/engine](https://thecherno.com/engine). 

***

## Getting Started
Visual Studio 2022 is recommended, focus mainly on a Windows build.

<ins>**1. Downloading the repository:**</ins>

Start by cloning the repository with `git clone --recursive https://github.com/Metonydai/Huiluna`.

If the repository was cloned non-recursively previously, use `git submodule update --init` to clone the necessary submodules.

<ins>**2. Configuring the dependencies:**</ins>

1. Python3 is needed to be installed.

2. One prerequisite is the Vulkan SDK which is needed to be installed from LunarG. 

3. After installation, run the [Septup.bat](https://github.com/Metonydai/Huiluna/blob/master/scripts/Setup.bat) file found in script folder. This will download the required prerequisites for the project if they are not present yet.

If changes are made, or if you want to regenerate project files, rerun the [Win-GenProjects.bat](https://github.com/Metonydai/Huiluna/blob/master/scripts/Win-GenProjects.bat) script file found in scripts folder.

## Engine Features
1. Core systems (Events, Input, Entity/Component, etc.)

2. Rendering (OpenGL, 2D batching, maybe later 3D, shaders, etc.)

3. Physics (Box2D integration)

4. Editor (Jerez Editor)

5. Scripting (C# via Mono), at scripting branch

## Jerez-Editor Demo Clip
[![Jerez Editor Demo](https://img.youtube.com/vi/a88KpgSuSPM/0.jpg)](https://youtu.be/a88KpgSuSPM)



