#pragma once

#include "Phoenix/EvaRenderer/RendererAPI.h"
#include <GLFW/glfw3.h>

#include "Phoenix/Core/Application.h"

#include <vulkan/vulkan.h>

namespace Phx {

	class VulkanRendererAPI : public RendererAPI
	{
		public:
			virtual void Init() override;
			virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

			virtual void SetClearColor(const glm::vec4& color) override;
			virtual void Clear() override;

			virtual void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) override;
	};
}