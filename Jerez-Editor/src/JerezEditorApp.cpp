#include "Huiluna.h"
#include "Huiluna/Core/EntryPoint.h"

#include "EditorLayer.h"


namespace Huiluna {

	class JerezEditor : public Application
	{
	public:
		JerezEditor()
			: Application("Jerez-Editor")
		{
			PushLayer(new EditorLayer());
		}

		~JerezEditor()
		{

		}
	};

	Application* CreateApplication()
	{
		return new JerezEditor();
	}
}