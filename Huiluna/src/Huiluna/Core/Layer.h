#pragma once

#include "Huiluna/Core/Base.h"
#include "Huiluna/Events/Event.h"

#include "Huiluna/Core/Timestep.h"

namespace Huiluna {

	class HUILUNA_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}