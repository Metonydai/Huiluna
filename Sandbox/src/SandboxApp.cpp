#include "Huiluna.h"

class ExampleLayer : public Huiluna::Layer 
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Huiluna::Event& event) override
	{
		HL_TRACE("{0}", event.ToString());
	}
};

class Sandbox : public Huiluna::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Huiluna::Application* Huiluna::CreateApplication()
{
	return new Sandbox;
}