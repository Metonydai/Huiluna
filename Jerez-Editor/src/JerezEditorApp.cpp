#include "Huiluna.h"
#include "Huiluna/Core/EntryPoint.h"

#include "EditorLayer.h"


namespace Huiluna {

	class JerezEditor : public Application
	{
	public:
		JerezEditor(ApplicationCommandLineArgs args)
			: Application("Jerez-Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~JerezEditor()
		{

		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new JerezEditor(args);
	}
}
