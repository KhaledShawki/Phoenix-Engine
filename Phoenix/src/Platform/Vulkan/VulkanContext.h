// #pragma once
// #include "Phoenix/EvaRenderer/GraphicsContext.h"
// 
// namespace Phx {
// 
// 	struct QueueFamilyIndices {
// 		std::optional<uint32_t> graphicsFamily;
// 		std::optional<uint32_t> computeFamily;
// 		std::optional<uint32_t> transferFamily;
// 		std::optional<uint32_t> presentFamily;
// 
// 		bool isComplete() {
// 			return graphicsFamily.has_value()
// 				&& computeFamily.has_value()
// 				&& transferFamily.has_value()
// 				&& presentFamily.has_value();
// 		}
// 	};
// 
// 	class VulkanContext : public GraphicsContext
// 	{
// 	public:
// 		VulkanContext(GLFWwindow* windowHandle);
// 		virtual void Init() override;
// 		virtual void SwapBuffers() override;
// 
// 	public:
// 		VkInstance GetInstance();
// 		VkPhysicalDevice GetPhysicalDevice();
// 		VkDevice GetDevice();
// 		VkSurfaceKHR GetSurface();
// 		VkQueue GetGraphicsQueue();
// 		VkQueue GetComputeQueue(); 
// 		VkQueue GetTransferQueue(); 
// 		VkQueue GetPresentQueue(); 
// 		VkSwapchainKHR GetSwapchain();
// 
// 	private:
// 		void CreateVulkanInstance();
// 		void CreateWindowSurface();
// 		void PickPhysicalDevice();
// 		void CreateLogicalDevice();
// 		void CreateSwapchain();
// 		void CreateImageView();
// 
// 	public:
// 		void Cleanup();
// 
// 	private:
// 		GLFWwindow* m_WindowHandle;
// 	
// 	private:
// 		 VkInstance* m_VulkanInstance;
// 		 VkPhysicalDevice m_PhysicalDevice;;
// 		 VkDevice m_Device; // Logical device
// 		 VkSurfaceKHR m_Surface;
// 		 VkQueue m_GraphicsQueue;
// 		 VkQueue m_ComputeQueue;
// 		 VkQueue m_TransferQueue;
// 		 VkQueue m_PresentQueue;
// 		 VkSurfaceFormatKHR m_SurfaceFormat;
// 		 VkPresentModeKHR m_PresentMode;
// 		 VkSwapchainKHR m_Swapchain;
// 		std::vector<VkImage> m_SwapchainImages;
// 		std::vector<VkImageView> m_SwapchainImageViews;
// 
// 	private:
// 		bool IsDeviceSuitable(VkPhysicalDevice device);
// 		int RateDeviceSuitability(VkPhysicalDevice device);
// 		bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
// 		bool CheckDeviceLayerSupport(VkPhysicalDevice device);
// 		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);	
// 		VkSurfaceFormatKHR ChooseSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& surfaceFormats);
// 		VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& presentModes);
// 
// 	private:
// 		const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
// #ifdef PHX_DEBUG
// 			std::vector<const char*> instanceLayer = { "VK_LAYER_KHRONOS_validation" };
// 			std::vector<const char*> deviceLayer = { "VK_LAYER_KHRONOS_validation" };
// #else 
// 			std::vector<const char*> instanceLayer = {};
// 			std::vector<const char*> deviceLayer = {};
// #endif // PHX_DEBUG
// 	};
// }