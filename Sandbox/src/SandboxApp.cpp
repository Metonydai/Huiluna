#include "Huiluna.h"

class Sandbox : public Huiluna::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

Huiluna::Application* Huiluna::CreateApplication()
{
	return new Sandbox;
}