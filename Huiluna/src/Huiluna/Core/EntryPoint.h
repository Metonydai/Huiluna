#pragma once
#include "Huiluna/Core/Base.h"
#include "Huiluna/Core/Application.h"

#ifdef HL_PLATFORM_WINDOWS

extern Huiluna::Application* Huiluna::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Huiluna::Log::Init();

	HL_PROFILE_BEGIN_SESSION("Startup", "HuilunaProfile-Startup.json");
	auto app = Huiluna::CreateApplication({ argc, argv});
	HL_PROFILE_END_SESSION();

	HL_PROFILE_BEGIN_SESSION("Runtime", "HuilunaProfile-Runtime.json");
	app->Run();
	HL_PROFILE_END_SESSION();

	HL_PROFILE_BEGIN_SESSION("Runtime", "HuilunaProfile-Shutdown.json");
	delete app;
	HL_PROFILE_END_SESSION();

}

#endif