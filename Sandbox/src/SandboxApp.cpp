#include "Huiluna.h"
#include "Huiluna/Core/EntryPoint.h"

#include "Platform/OpenGL/OpenGLShader.h"

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
		m_VertexArray = Huiluna::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Huiluna::Ref<Huiluna::VertexBuffer> vertexBuffer;
		vertexBuffer = Huiluna::VertexBuffer::Create(vertices, sizeof(vertices));

		Huiluna::BufferLayout layout = {
			{ Huiluna::ShaderDataType::Float3, "a_Position" },
			{ Huiluna::ShaderDataType::Float4, "a_Color" }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Huiluna::Ref<Huiluna::IndexBuffer> indexBuffer;
		indexBuffer = Huiluna::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA = Huiluna::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Huiluna::Ref<Huiluna::VertexBuffer> squareVB;
		squareVB = Huiluna::VertexBuffer::Create(squareVertices, sizeof(squareVertices));

		squareVB->SetLayout({
			{ Huiluna::ShaderDataType::Float3, "a_Position" },
			{ Huiluna::ShaderDataType::Float2, "a_TexCoord" }
			});

		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };

		Huiluna::Ref<Huiluna::IndexBuffer> squareIB;
		squareIB = Huiluna::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));

		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0f);
			}
			
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;
			in vec4 v_Color;
			
			void main()
			{
				color = v_Color;
			}
		)";

		m_Shader = Huiluna::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec2 a_TexCoord;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			
			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0f);
			}
			
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;

			uniform	vec3 u_Color;	 	

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader = Huiluna::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_MegamiTexture = Huiluna::Texture2D::Create("assets/textures/megami.jpg");
		m_CheckerboardTexture = Huiluna::Texture2D::Create("assets/textures/Checkerboard.png");
		m_ChernoLogoTexture = Huiluna::Texture2D::Create("assets/textures/ChernoLogo.png");

		std::dynamic_pointer_cast<Huiluna::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Huiluna::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Huiluna::Timestep ts) override
	{
		// Update
		m_CameraController.OnUpdate(ts);

		// Render
		Huiluna::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Huiluna::RenderCommand::Clear();

		Huiluna::Renderer::BeginScene(m_CameraController.GetCamera());
		
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Huiluna::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Huiluna::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int j = 0; j < 20; j++)
		{
			for (int i = 0; i < 20; i++)
			{
				glm::vec3 pos(i * 0.11f, j * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;

				Huiluna::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		//m_MegamiTexture->Bind();
		//Huiluna::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_CheckerboardTexture->Bind();
		Huiluna::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_ChernoLogoTexture->Bind();
		Huiluna::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		//Huiluna::Renderer::Submit(m_Shader, m_VertexArray);

		Huiluna::Renderer::EndScene();
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
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

Huiluna::Application* Huiluna::CreateApplication()
{
	return new Sandbox;
}