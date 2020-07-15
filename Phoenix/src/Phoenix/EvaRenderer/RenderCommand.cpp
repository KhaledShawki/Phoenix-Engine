#include "phxpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"
#include "Platform/Vulkan/VulkanRendererAPI.h"

namespace Phx {

	Ref<RendererAPI> RenderCommand::s_RendererAPI = RenderCommand::Create();

	Ref<RendererAPI> RenderCommand::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:    PHX_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLRendererAPI>();
		case RendererAPI::API::Vulkan:	return CreateRef<VulkanRendererAPI>();
		}
		
		PHX_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}