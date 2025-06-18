#include "Sandbox2D.h"
#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
	HL_PROFILE_FUNCTION();

	m_MegamiTexture = Huiluna::Texture2D::Create("assets/textures/megami.jpg");
	m_CheckerboardTexture = Huiluna::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	HL_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Huiluna::Timestep ts)
{
	HL_PROFILE_FUNCTION();
	
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		HL_PROFILE_SCOPE("Renderer Prep");
		Huiluna::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Huiluna::RenderCommand::Clear();
	}

	{
		HL_PROFILE_SCOPE("Renderer Draw");
		Huiluna::Renderer2D::BeginScene(m_CameraController.GetCamera());
		//Huiluna::Renderer2D::DrawRotateQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Huiluna::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Huiluna::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		//Huiluna::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1 }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.f, {1.0f, 0.9f, 0.9f, 1.0f});
		Huiluna::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	HL_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Huiluna::Event& e)
{
	m_CameraController.OnEvent(e);
}
