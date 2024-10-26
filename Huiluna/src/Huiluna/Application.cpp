#include "hlpch.h"

#include "Application.h"

#include "Huiluna/Events/ApplicationEvent.h"
#include "Huiluna/Log.h"

#include <GLFW/glfw3.h>

namespace Huiluna {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);

		while (m_Running)
		{
			glClearColor(0, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}
