#pragma once
#include "Phoenix/Core/Layer.h"
#include "Phoenix/Core/Events/MouseEvent.h"
#include "Phoenix/Core/Events/ApplicationEvent.h"
#include "Phoenix/Core/Events/KeyEvent.h"

namespace Phx {
	class ImGuiLayer : public Layer
	{

	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}

