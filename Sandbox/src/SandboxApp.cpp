#include "Phoenix.h"
#include "Phoenix/EntryPoint.h"

#include "Sandbox2D.h"

class Sandbox : public Phx::Application 
{

public:
	Sandbox()
	{
		PushLayer(new Sandbox2D());
	}
	~Sandbox() = default;
};
Phx::Application* Phx::CreateApplication() 
{
	Phx::RendererAPI::SetAPI(Phx::RendererAPI::API::OpenGL);
	// Phx::RendererAPI::SetAPI(Phx::RendererAPI::API::Vulkan);
	return new Sandbox();
} 
