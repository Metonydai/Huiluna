#include "Application.h"

#include "Huiluna/Events/ApplicationEvent.h"
#include "Huiluna/Log.h"

namespace Huiluna {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HL_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HL_TRACE(e.ToString());
		}

		while (true);
	}

}
