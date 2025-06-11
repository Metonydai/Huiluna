#include "Huiluna.h"

#include "imgui/imgui.h"

class ExampleLayer : public Huiluna::Layer 
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Huiluna::Input::IsKeyPressed(HL_KEY_TAB))
			HL_TRACE("Tab key is pressed (poll)!");
	}


	void OnEvent(Huiluna::Event& event) override
	{
		if (event.GetEventType() == Huiluna::EventType::KeyPressed)
		{
			Huiluna::KeyPressedEvent& e = (Huiluna::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HL_KEY_TAB)
				HL_TRACE("Tab key is pressed (event)!");
			else
				HL_TRACE("{0}", (char)e.GetKeyCode());
		}
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