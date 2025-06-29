#pragma once

namespace Huiluna {
	
	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();
		// ContentBrowser(const Ref<Scene>& context);

		// void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();
	private:
		std::filesystem::path m_CurrentDirectory;
	};

}