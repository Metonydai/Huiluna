#pragma once

#include "Base.h"

#include "Window.h"
#include "LayerStack.h"
#include "Huiluna/Events/Event.h"
#include "Huiluna/Events/ApplicationEvent.h"

#include "Huiluna/Core/Timestep.h"

#include "Huiluna/ImGui/ImGuiLayer.h"

namespace Huiluna {

	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			HL_CORE_ASSERT(index < Count, "");
			return Args[index];
		}
	};

	class Application
	{
	public:
		Application(const std::string& name = "Huiluna App", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; };
		
		inline static Application& Get() { return *s_Instance; }

		ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		ApplicationCommandLineArgs m_CommandLineArgs;
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true, m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);
}
