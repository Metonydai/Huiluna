#pragma once

#include "Huiluna/Core/Log.h"
#include "Huiluna/Scene/Scene.h"
#include "Huiluna/Scene/Entity.h"


namespace Huiluna {

	class SceneHierarchyPanel 
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();
		
		Entity GetSelectedEntity() const { return m_SelectionContext; }
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}