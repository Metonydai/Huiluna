#pragma once

#ifdef HL_PLATFORM_WINDOWS

extern Huiluna::Application* Huiluna::CreateApplication();

int main(int argc, char** argv)
{
	Huiluna::Log::Init();
	HL_CORE_WARN("Initialized Log!");
	int a = 5;
	HL_INFO("I love Huiyu {0} times!", a);

	auto app = Huiluna::CreateApplication();
	app->Run();
	delete app;
}

#endif