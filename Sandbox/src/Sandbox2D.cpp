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
	Huiluna::Renderer2D::ResetStats();
	{
		HL_PROFILE_SCOPE("Renderer Prep");
		Huiluna::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Huiluna::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		HL_PROFILE_SCOPE("Renderer Draw");
		Huiluna::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Huiluna::Renderer2D::DrawRotateQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, 45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Huiluna::Renderer2D::DrawQuad({ -1.0f, 0.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Huiluna::Renderer2D::DrawQuad({ 0.5f, -0.5f, 0.0f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Huiluna::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 2.0f);
		Huiluna::Renderer2D::DrawRotateQuad({ 0.0f, 0.0f, 0.1f }, { 1.0f, 1.0f }, rotation, m_MegamiTexture, 1.0f);
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Huiluna::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Huiluna::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	HL_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	auto stats = Huiluna::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Huiluna::Event& e)
{
	m_CameraController.OnEvent(e);
}
