#pragma once
#include "Huiluna.h"
#include "ParticleSystem.h"

class Sandbox2D : public Huiluna::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Huiluna::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Huiluna::Event& e) override;

private:
	Huiluna::OrthographicCameraController m_CameraController;
	
	Huiluna::Ref<Huiluna::Texture2D> m_MegamiTexture, m_CheckerboardTexture;
	Huiluna::Ref<Huiluna::Texture2D> m_SpriteSheet;
	Huiluna::Ref<Huiluna::SubTexture2D> m_TextureStairs, m_TextureBarrel, m_TextureTree;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	
	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;

	uint32_t m_MapWidth, m_MapHeight;
	std::unordered_map<char, Huiluna::Ref<Huiluna::SubTexture2D>> s_TextureMap;
};