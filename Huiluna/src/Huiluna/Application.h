#pragma once

#include "Core.h"

namespace Huiluna {
	class HUILUNA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
