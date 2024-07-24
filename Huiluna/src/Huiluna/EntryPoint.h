#pragma once

#ifdef HL_PLATFORM_WINDOWS

extern Huiluna::Application* Huiluna::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Huiluna::CreateApplication();
	app->Run();
	delete app;
}

#endif