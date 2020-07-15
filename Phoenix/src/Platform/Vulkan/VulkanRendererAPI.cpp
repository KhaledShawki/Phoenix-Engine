#include "phxpch.h"
#include "VulkanRendererAPI.h"

namespace Phx {

	void VulkanRendererAPI::Init()
	{

	}
		
	void VulkanRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		VkViewport viewport = {};
		viewport.x = x;
		viewport.y = y;
		viewport.width = width;
		viewport.height = height;

		//vkCmdSetViewport(nullptr, 0, 0, &viewport);
	}

	void VulkanRendererAPI::SetClearColor(const glm::vec4& color)
	{
// 		VkClearColorValue clearColorValue = {};
// 		float colorRGBA[4] = { color.r, color.g, color.b, color.a };
// 		clearColorValue.float32 = colorRGBA;
	}

	void VulkanRendererAPI::Clear()
	{
	}

	void VulkanRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount)
	{
	}


}