#include "Sandbox2D.h"
#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


static const uint32_t s_MapWidth = 24;
static const char* s_MapTiles = 
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWDDDDDDDWWWWWWWWW"
"WWWWWWDDDDDDDDDDDDWWWWWW"
"WWWWWDDDDDDDDDDDDDDDWWWW"
"WWWWDDDDDDDDDDDDDDDDDWWW"
"WWWDDDDDDDDDDDDDDDDDDDWW"
"WWDDDDDDDWWWDDDDDDDDDDDW"
"WDDDDDDDDWWWDDDDDCDDDDDW"
"WWDDDDDDDDDDDDDDDDDDDDWW"
"WWWDDDDDDDDDDDDDDDDDDWWW"
"WWWWWDDDDDDDDDDDDDDWWWWW"
"WWWWWWDDDDDDDDDDDDWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
;

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
	HL_PROFILE_FUNCTION();

	m_MegamiTexture = Huiluna::Texture2D::Create("assets/textures/megami.jpg");
	m_CheckerboardTexture = Huiluna::Texture2D::Create("assets/textures/Checkerboard.png");
	m_SpriteSheet = Huiluna::Texture2D::Create("assets/game/textures/RPGpack_sheet_2X.png");
	m_TextureStairs = Huiluna::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 7, 6 }, { 128, 128 });
	m_TextureBarrel = Huiluna::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 8, 2 }, { 128, 128 });
	m_TextureTree = Huiluna::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128, 128 }, { 1, 2 });

	m_MapWidth = s_MapWidth;
	m_MapHeight = strlen(s_MapTiles) / s_MapWidth;

	// s_TextureMap
	s_TextureMap['D'] = Huiluna::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 6, 11 }, { 128, 128 });
	s_TextureMap['W'] = Huiluna::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 11, 11 }, { 128, 128 });

	// Init here
	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 5.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };

	m_CameraController.SetZoomLevel(5.0);
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

#if 0
	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		HL_PROFILE_SCOPE("Renderer Draw");
		Huiluna::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Huiluna::Renderer2D::DrawRotateQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Huiluna::Renderer2D::DrawQuad({ -1.0f, 0.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Huiluna::Renderer2D::DrawQuad({ 0.5f, -0.5f, 0.0f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Huiluna::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 2.0f);
		Huiluna::Renderer2D::DrawRotateQuad({ 0.0f, 0.0f, 0.1f }, { 1.0f, 1.0f }, glm::radians(rotation), m_MegamiTexture, 1.0f);
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


	if (Huiluna::Input::IsMouseButtonPressed(Huiluna::Mouse::ButtonLeft))
	{
		auto [x, y] = Huiluna::Input::GetMousePosition();
		auto width = Huiluna::Application::Get().GetWindow().GetWidth();
		auto height = Huiluna::Application::Get().GetWindow().GetHeight();

		auto bounds = m_CameraController.GetBounds();
		auto pos = m_CameraController.GetCamera().GetPosition();
		x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
		y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
		m_Particle.Position = { x + pos.x, y + pos.y };
		for (int i = 0; i < 5; i++)
			m_ParticleSystem.Emit(m_Particle);
	}

	m_ParticleSystem.OnUpdate(ts);
	m_ParticleSystem.OnRender(m_CameraController.GetCamera());
#endif


#if 1
	Huiluna::Renderer2D::BeginScene(m_CameraController.GetCamera());

	for (uint32_t y = 0; y < m_MapHeight; y++)
	{
		for (uint32_t x = 0; x < m_MapWidth; x++)
		{
			char tileType = s_MapTiles[x + y * m_MapWidth];
			Huiluna::Ref<Huiluna::SubTexture2D> texture;
			if (s_TextureMap.find(tileType) != s_TextureMap.end())
				texture = s_TextureMap[tileType];
			else
				texture = m_TextureBarrel;
	
			Huiluna::Renderer2D::DrawQuad({ x - m_MapWidth / 2.0f, y - m_MapHeight / 2.0f, 0.1f }, { 1.0f, 1.0f }, texture);
	
		}
	}
	
	Huiluna::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureStairs);
	Huiluna::Renderer2D::DrawQuad({ 1.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureBarrel);
	Huiluna::Renderer2D::DrawQuad({ -1.0f, 1.5f, 0.5f }, { 1.0f, 2.0f }, m_TextureTree);
	Huiluna::Renderer2D::DrawQuad({ -1.0f, 1.5f, 0.5f }, { 1.0f, 2.0f }, { 1.0f, 1.0f, 1.0f, 1.0 });

	Huiluna::Renderer2D::EndScene();
#endif
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
