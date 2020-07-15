#pragma once

#include "Phoenix/Core/Timestep.h"
#include "Events/Event.h"

namespace Phx {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DubugName; }
	protected:
		std::string m_DubugName;
	};
}