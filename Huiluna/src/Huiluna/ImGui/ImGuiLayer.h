#pragma once

#include "Huiluna/Core/Layer.h"
#include "Huiluna/Events/ApplicationEvent.h"
#include "Huiluna/Events/KeyEvent.h"
#include "Huiluna/Events/MouseEvent.h"


namespace Huiluna {
	class HUILUNA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnEvent(Event& e) override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}