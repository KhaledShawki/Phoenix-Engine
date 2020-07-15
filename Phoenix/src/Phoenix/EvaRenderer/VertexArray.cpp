#include "phxpch.h"
#include "VertexArray.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"
#include "Renderer.h"

namespace Phx {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    PHX_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		case RendererAPI::API::Vulkan:	/*return CreateRef<VulkanVertexArray>();*/break;
		}

		PHX_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}