#include "Huiluna.h"
#include "Huiluna/Core/EntryPoint.h"

#include "Platform/OpenGL/OpenGLShader.h"
#include "Huiluna/Renderer/UniformBuffer.h"

#include "imgui/imgui.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public Huiluna::Layer 
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f, true)
	{
		
	}

	void OnUpdate(Huiluna::Timestep ts) override
	{
	
	}

	void OnImGuiRender()
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Huiluna::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}

private:
	Huiluna::ShaderLibrary m_ShaderLibrary;
	Huiluna::Ref<Huiluna::Shader> m_Shader;
	Huiluna::Ref<Huiluna::VertexArray> m_VertexArray;

	Huiluna::Ref<Huiluna::Shader> m_FlatColorShader;
	Huiluna::Ref<Huiluna::VertexArray> m_SquareVA;

	Huiluna::Ref<Huiluna::Texture2D> m_MegamiTexture, m_ChernoLogoTexture, m_CheckerboardTexture;

	Huiluna::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

};

class Sandbox : public Huiluna::Application
{
public:
	Sandbox(Huiluna::ApplicationCommandLineArgs args)
		: Huiluna::Application("Sandbox", args)
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

Huiluna::Application* Huiluna::CreateApplication(ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}