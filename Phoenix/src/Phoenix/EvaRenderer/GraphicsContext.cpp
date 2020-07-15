#include "phxpch.h"
#include "Phoenix/EvaRenderer/GraphicsContext.h"

#include "Phoenix/EvaRenderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"
//#include "Platform/Vulkan/VulkanContext.h"

namespace Phx {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    PHX_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
			//case RendererAPI::API::Vulkan:	return CreateScope<VulkanContext>(static_cast<GLFWwindow*>(window));
		}

		PHX_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}