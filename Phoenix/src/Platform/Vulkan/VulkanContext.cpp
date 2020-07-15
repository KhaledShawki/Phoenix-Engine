#include "phxpch.h"
// 
 #include "VulkanContext.h"
// 
// #include <vulkan/vulkan.h>
// #include <GLFW/glfw3.h>
// namespace Phx {
// 
// 	VulkanContext::VulkanContext(GLFWwindow* windowHandle)
// 		:m_WindowHandle(windowHandle)
// 	{
// 		PHX_CORE_ASSERT(windowHandle, "Window handle is null!");
// 
// 		m_VulkanInstance = VK_NULL_HANDLE;
// 		m_PhysicalDevice = VK_NULL_HANDLE;
// 		m_Device = VK_NULL_HANDLE;
// 		m_Surface = VK_NULL_HANDLE;
// 		m_GraphicsQueue = VK_NULL_HANDLE;
// 		m_ComputeQueue = VK_NULL_HANDLE;
// 		m_TransferQueue = VK_NULL_HANDLE;
// 		m_PresentQueue = VK_NULL_HANDLE;
// 		m_Swapchain = VK_NULL_HANDLE;
// 		m_SurfaceFormat = {};
// 		m_PresentMode = {};
// 	}
// 
// 	void VulkanContext::Init()
// 	{
// 		CreateVulkanInstance();
// 		CreateWindowSurface();
// 		PickPhysicalDevice();
// 		CreateLogicalDevice();
// 		CreateSwapchain();
// 		CreateImageView();
// 	}
// 
// 	void VulkanContext::SwapBuffers()
// 	{
// 	}
// 
// 	void VulkanContext::CreateVulkanInstance()
// 	{
// 		VkApplicationInfo appInfo = { VK_STRUCTURE_TYPE_APPLICATION_INFO };
// 		appInfo.apiVersion = VK_API_VERSION_1_2;
// 		appInfo.pApplicationName = "Phoenix";
// 		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
// 		appInfo.pEngineName = "Phoenix Engine";
// 		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
// 
// 		VkInstanceCreateInfo instanceInfo = { VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };
// 		instanceInfo.pApplicationInfo = &appInfo;
// 
// 		// Extensions
// 		uint32_t glfwExtensionCount = 0;
// 		const char** glfwExtensions;
// 
// 		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
// 		instanceInfo.enabledExtensionCount = glfwExtensionCount;
// 		instanceInfo.ppEnabledExtensionNames = glfwExtensions;
// 
// 		// Layers
// 		uint32_t availableLayerCount = 0;
// 		PHX_VK_ASSERT(vkEnumerateInstanceLayerProperties(&availableLayerCount, nullptr),
// 			"Could not get the number of supported instance properties.");
// 		std::vector<VkLayerProperties> availableLayer(availableLayerCount);
// 		PHX_VK_ASSERT(vkEnumerateInstanceLayerProperties(&availableLayerCount, availableLayer.data()),
// 			"Could not enumerate supported instance properties.");
// 
// 		if (instanceLayer.size() != 0)
// 		{
// 			for (int i = 0; i < (int)instanceLayer.size(); i++)
// 			{
// 				bool found = false;
// 				for (int x = 0; x < availableLayerCount; x++)
// 				{
// 					if (strcmp(instanceLayer[i], availableLayer[x].layerName) == 0)
// 					{
// 						found = true;
// 						break;
// 					}
// 				}
// 				if (!found)
// 				{
// 					PHX_CORE_ERROR("{0} is missing!", instanceLayer[i]);
// 				}
// 			}
// 			instanceInfo.enabledLayerCount = (int)instanceLayer.size();
// 			instanceInfo.ppEnabledLayerNames = instanceLayer.data();
// 		}
// 
// 		PHX_VK_ASSERT(vkCreateInstance(&instanceInfo, nullptr, &m_VulkanInstance), "Could not create vulkan instance.");
// 	}
// 
// 	void VulkanContext::CreateWindowSurface()
// 	{
// 		PHX_VK_ASSERT(glfwCreateWindowSurface(m_VulkanInstance, m_WindowHandle, nullptr, &m_Surface),
// 			"Failed to create window surface!");
// 	}
// 
// 	void VulkanContext::PickPhysicalDevice()
// 	{
// 		uint32_t physicaDevicesCount = 0;
// 		PHX_VK_ASSERT(vkEnumeratePhysicalDevices(m_VulkanInstance, &physicaDevicesCount, nullptr),
// 			"Could not get the number of suported physical devices.");
// 		PHX_CORE_ASSERT(physicaDevicesCount > 0, "No supported physical device were found.");
// 		std::vector<VkPhysicalDevice>  physicadevices(physicaDevicesCount);
// 		PHX_VK_ASSERT(vkEnumeratePhysicalDevices(m_VulkanInstance, &physicaDevicesCount, physicadevices.data()),
// 			"Could not enumerate supported physical devices.");
// 
// 		if (physicaDevicesCount == 1)
// 		{
// 			m_PhysicalDevice = physicadevices[0];
// 		}
// 		else
// 		{
// 			// Use an ordered map to automatically sort candidates by increasing score
// 			std::multimap<int, VkPhysicalDevice> candidates;
// 
// 			for (const auto& device : physicadevices)
// 			{
// 				if (IsDeviceSuitable(device))
// 				{
// 					int score = RateDeviceSuitability(device);
// 					candidates.insert(std::make_pair(score, device));
// 				}
// 			}
// 			// Take the best score
// 			PHX_CORE_ASSERT(candidates.rbegin()->first > 0, "Failed to find a suitable GPU!");
// 			m_PhysicalDevice = candidates.rbegin()->second;
// 		}
// 
// 	}
// 
// 	void VulkanContext::CreateLogicalDevice()
// 	{
// 		QueueFamilyIndices indices = FindQueueFamilies(m_PhysicalDevice);
// 		std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
// 		std::vector<uint32_t> uniqueQueueFamilies = {
// 			indices.graphicsFamily.value(),
// 			indices.computeFamily.value(),
// 			indices.transferFamily.value(),
// 			indices.presentFamily.value()
// 		};
// 		float queuePriority = 1.0;
// 		for (uint32_t queueFamily : uniqueQueueFamilies)
// 		{
// 			VkDeviceQueueCreateInfo queueCreateInfo = { VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO };
// 			queueCreateInfo.queueFamilyIndex = queueFamily;
// 			queueCreateInfo.queueCount = 1;
// 			queueCreateInfo.pQueuePriorities = &queuePriority;
// 			queueCreateInfos.push_back(queueCreateInfo);
// 		}
// 
// 		VkPhysicalDeviceFeatures deviceFeatures = {};
// 
// 
// 		// Logical Device
// 		VkDeviceCreateInfo deviceInfo = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO };
// 		deviceInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
// 		deviceInfo.pQueueCreateInfos = queueCreateInfos.data();
// 		deviceInfo.pEnabledFeatures = &deviceFeatures;
// 		deviceInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
// 		deviceInfo.ppEnabledExtensionNames = deviceExtensions.data();
// 
// 		deviceInfo.enabledLayerCount = static_cast<uint32_t>(deviceLayer.size());
// 		deviceInfo.ppEnabledLayerNames = deviceLayer.data();
// 
// 		PHX_VK_ASSERT(vkCreateDevice(m_PhysicalDevice, &deviceInfo, nullptr, &m_Device), "Failed to create logical device!");
// 
// 		vkGetDeviceQueue(m_Device, indices.graphicsFamily.value(), 0, &m_GraphicsQueue);
// 		vkGetDeviceQueue(m_Device, indices.computeFamily.value(), 0, &m_ComputeQueue);
// 		vkGetDeviceQueue(m_Device, indices.transferFamily.value(), 0, &m_TransferQueue);
// 		vkGetDeviceQueue(m_Device, indices.presentFamily.value(), 0, &m_PresentQueue);
// 
// 	}
// 
// 	void VulkanContext::CreateSwapchain()
// 	{
// 		QueueFamilyIndices indices = FindQueueFamilies(m_PhysicalDevice);
// 		std::vector<uint32_t> uniqueQueueFamilies = {
// 			indices.graphicsFamily.value(),
// 			indices.computeFamily.value(),
// 			indices.transferFamily.value(),
// 			indices.presentFamily.value()
// 		};
// 
// 		// swapchain
// 		VkSurfaceCapabilitiesKHR surfaceCapabilities = {};
// 		PHX_VK_ASSERT(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_PhysicalDevice, m_Surface, &surfaceCapabilities),
// 			"Could not get capabilities of a presentation surface .");
// 
// 		uint32_t surfaceFormatsCount = 0;
// 		PHX_VK_ASSERT(vkGetPhysicalDeviceSurfaceFormatsKHR(m_PhysicalDevice, m_Surface, &surfaceFormatsCount, nullptr),
// 			"Could not get the number of supported surface formats.");
// 		std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatsCount);
// 		PHX_VK_ASSERT(vkGetPhysicalDeviceSurfaceFormatsKHR(m_PhysicalDevice, m_Surface, &surfaceFormatsCount, surfaceFormats.data()),
// 			"Could not enumerate supported surface formats.");
// 
// 		uint32_t presentModeCount = 0;
// 		PHX_VK_ASSERT(vkGetPhysicalDeviceSurfacePresentModesKHR(m_PhysicalDevice, m_Surface, &presentModeCount, nullptr),
// 			"Could not get the number of supported surface present modes.");
// 		std::vector<VkPresentModeKHR> presentModes(presentModeCount);
// 		PHX_VK_ASSERT(vkGetPhysicalDeviceSurfacePresentModesKHR(m_PhysicalDevice, m_Surface, &presentModeCount, presentModes.data()),
// 			"Could not enumerate supported present modes.");
// 
// 		m_SurfaceFormat = ChooseSurfaceFormat(surfaceFormats);
// 		m_PresentMode = ChooseSwapPresentMode(presentModes);
// 
// 		VkSwapchainCreateInfoKHR swapchainCreateInfo = { VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR };
// 		swapchainCreateInfo.surface = m_Surface;
// 		swapchainCreateInfo.minImageCount = surfaceCapabilities.minImageCount;
// 		swapchainCreateInfo.imageFormat = m_SurfaceFormat.format;
// 		swapchainCreateInfo.imageColorSpace = m_SurfaceFormat.colorSpace;
// 		swapchainCreateInfo.imageExtent = surfaceCapabilities.currentExtent;
// 		swapchainCreateInfo.imageArrayLayers = 1; //surfaceCapabilities.maxImageArrayLayers;
// 		swapchainCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
// 
// 		if (indices.presentFamily.value() != indices.graphicsFamily.value())
// 			swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
// 		else
// 			swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
// 
// 		swapchainCreateInfo.queueFamilyIndexCount = static_cast<uint32_t>(uniqueQueueFamilies.size());
// 		swapchainCreateInfo.pQueueFamilyIndices = uniqueQueueFamilies.data();
// 		swapchainCreateInfo.preTransform = surfaceCapabilities.currentTransform;
// 		swapchainCreateInfo.presentMode = m_PresentMode;
// 		swapchainCreateInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
// 		swapchainCreateInfo.clipped = VK_TRUE;
// 		swapchainCreateInfo.oldSwapchain = VK_NULL_HANDLE;
// 
// 		PHX_VK_ASSERT(vkCreateSwapchainKHR(m_Device, &swapchainCreateInfo, nullptr, &m_Swapchain),
// 			"Could not create a swapchain.");
// 	}
// 
// 	void VulkanContext::CreateImageView()
// 	{
// 		// swapchain images
// 		uint32_t imagesCount = 0;
// 		PHX_VK_ASSERT(vkGetSwapchainImagesKHR(m_Device, m_Swapchain, &imagesCount, nullptr),
// 			"Could not get the number of swapchain images.");
// 		m_SwapchainImages = std::vector<VkImage>(imagesCount);
// 		PHX_VK_ASSERT(vkGetSwapchainImagesKHR(m_Device, m_Swapchain, &imagesCount, m_SwapchainImages.data()),
// 			"Could not enumerate swapchain images.");
// 
// 		// swap chain image views
// 		for (int i = 0; i < imagesCount; i++)
// 		{
// 			VkImageViewCreateInfo imageViewCreateInfo = { VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO };
// 			imageViewCreateInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
// 			imageViewCreateInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
// 			imageViewCreateInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
// 			imageViewCreateInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
// 			imageViewCreateInfo.image = m_SwapchainImages[i];
// 			imageViewCreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
// 			imageViewCreateInfo.format = m_SurfaceFormat.format;
// 			imageViewCreateInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
// 			imageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
// 			imageViewCreateInfo.subresourceRange.baseMipLevel = 0;
// 			imageViewCreateInfo.subresourceRange.layerCount = 1;
// 			imageViewCreateInfo.subresourceRange.levelCount = 1;
// 
// 			PHX_VK_ASSERT(vkCreateImageView(m_Device, &imageViewCreateInfo, nullptr, &m_SwapchainImageViews[i]),
// 				"Could not creat swapchain image view.");
// 		}
// 
// 	}
// 
// 	void VulkanContext::Cleanup()
// 	{
// 		for (auto imageView : m_SwapchainImageViews) {
// 			vkDestroyImageView(m_Device, imageView, nullptr);
// 		}
// 		for (auto image : m_SwapchainImages) {
// 			vkDestroyImage(m_Device, image, nullptr);
// 		}
// 
// 		vkDestroySwapchainKHR(m_Device, m_Swapchain, nullptr);
// 		
// 		vkDestroyDevice(m_Device, nullptr);
// 
// 		vkDestroySurfaceKHR(*m_VulkanInstance, m_Surface, nullptr);
// 
// 		vkDestroyInstance(*m_VulkanInstance, nullptr);
// 
// 		glfwDestroyWindow(m_WindowHandle);
// 
// 		glfwTerminate();
// 	}
// 
// 	bool VulkanContext::IsDeviceSuitable(VkPhysicalDevice device)
// 	{
// 		bool extensionsSupported = CheckDeviceExtensionSupport(device);
// 		bool layerSupported = CheckDeviceLayerSupport(device);
// 		QueueFamilyIndices indices = FindQueueFamilies(device);
// 		
// 		// check swapchain adequate
// 		uint32_t surfaceFormatsCount = 0;
// 		PHX_VK_ASSERT(vkGetPhysicalDeviceSurfaceFormatsKHR(m_PhysicalDevice, m_Surface, &surfaceFormatsCount, nullptr),
// 			"Could not get the number of supported surface formats.");
// 		std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatsCount);
// 		PHX_VK_ASSERT(vkGetPhysicalDeviceSurfaceFormatsKHR(m_PhysicalDevice, m_Surface, &surfaceFormatsCount, surfaceFormats.data()), 
// 			"Could not enumerate supported surface formats.");
// 
// 		uint32_t presentModeCount = 0;
// 		PHX_VK_ASSERT(vkGetPhysicalDeviceSurfacePresentModesKHR(m_PhysicalDevice, m_Surface, &presentModeCount, nullptr), 
// 			"Could not get the number of supported surface present modes.");
// 		std::vector<VkPresentModeKHR> presentModes(presentModeCount);
// 		PHX_VK_ASSERT(vkGetPhysicalDeviceSurfacePresentModesKHR(m_PhysicalDevice, m_Surface, &presentModeCount, presentModes.data()), 
// 			"Could not enumerate supported present modes.");
// 
// 		bool swapchainAdequate = !surfaceFormats.empty() && !presentModes.empty();
// 
// 		return indices.isComplete() && extensionsSupported && layerSupported && swapchainAdequate;
// 	}
// 
// 	int VulkanContext::RateDeviceSuitability(VkPhysicalDevice device)
// 	{
// 		VkPhysicalDeviceProperties physicaDeviceProperties;
// 		VkPhysicalDeviceFeatures physicaDeviceFeatures;
// 
// 		vkGetPhysicalDeviceProperties(device, &physicaDeviceProperties);
// 		vkGetPhysicalDeviceFeatures(device, &physicaDeviceFeatures);
// 
// 		int score = 0;
// 
// 		// Discrete GPUs have a significant performance advantage
// 		if (physicaDeviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
// 			score += 1000;
// 		
// 		// Maximum possible size of textures affects graphics quality
// 		score += physicaDeviceProperties.limits.maxImageDimension2D;
// 		score += physicaDeviceProperties.limits.maxImageDimension3D;
// 
// 		// Application can't function without geometry shaders
// 		if (!physicaDeviceFeatures.geometryShader) 
// 			return 0;
// 
// 		return score;
// 	}
// 
// 	bool VulkanContext::CheckDeviceExtensionSupport(VkPhysicalDevice device)
// 	{
// 		uint32_t availableDeviceExtensionsCount = 0;
// 		PHX_VK_ASSERT(vkEnumerateDeviceExtensionProperties(device, nullptr, &availableDeviceExtensionsCount, nullptr), "");
// 		std::vector<VkExtensionProperties> availableDeviceExtensions(availableDeviceExtensionsCount);
// 		PHX_VK_ASSERT(vkEnumerateDeviceExtensionProperties(device, nullptr, &availableDeviceExtensionsCount, availableDeviceExtensions.data()), "");
// 
// 		bool success = true;
// 		for (int i = 0; i < (int)deviceExtensions.size(); i++)
// 		{
// 			bool found = false;
// 			for (int x = 0; x < (int) availableDeviceExtensions.size(); x++)
// 			{
// 				if (strcmp(deviceExtensions[i], availableDeviceExtensions[x].extensionName) == 0)
// 				{
// 					found = true;
// 					break;
// 				}
// 			}
// 			if (!found)
// 			{
// 				success = false;
// 				PHX_CORE_ERROR("{0} is missing!", deviceExtensions[i]);
// 			}
// 		}
// 		return success;
// 	}
// 
// 	bool VulkanContext::CheckDeviceLayerSupport(VkPhysicalDevice device)
// 	{
// 		uint32_t availableDeviceLayerCount = 0;
// 		PHX_VK_ASSERT(vkEnumerateDeviceLayerProperties(device, nullptr, &availableDeviceLayerCount, nullptr), "");
// 		std::vector<VkLayerProperties> availableDeviceLayers(availableDeviceLayerCount);
// 		PHX_VK_ASSERT(vkEnumerateDeviceLayerProperties(device, nullptr, &availableDeviceLayerCount, availableDeviceLayers.data()), "");
// 
// 		bool success = true;
// 		for (int i = 0; i < (int)deviceExtensions.size(); i++)
// 		{
// 			bool found = false;
// 			for (int x = 0; x < (int)availableDeviceLayers.size(); x++)
// 			{
// 				if (strcmp(deviceLayer[i], availableDeviceLayers[x].layerName) == 0)
// 				{
// 					found = true;
// 					break;
// 				}
// 			}
// 			if (!found)
// 			{
// 				success = false;
// 				PHX_CORE_ERROR("{0} is missing!", deviceLayer[i]);
// 			}
// 		}
// 		return success;
// 	}
// 
// 	QueueFamilyIndices VulkanContext::FindQueueFamilies(VkPhysicalDevice device)
// 	{
// 		QueueFamilyIndices indices;
// 
// 		uint32_t queueFamiliesCount;
// 		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamiliesCount, nullptr);
// 		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamiliesCount);
// 		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamiliesCount, queueFamilies.data());
// 
// 		int i = 0;
// 		for (const auto& queueFamily : queueFamilies)
// 		{
// 			if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
// 				indices.graphicsFamily = i;
// 			
// 			 if (queueFamily.queueFlags & VK_QUEUE_COMPUTE_BIT)
// 				indices.computeFamily = i;
// 		   
// 			 if (queueFamily.queueFlags & VK_QUEUE_TRANSFER_BIT)
// 				indices.transferFamily = i;
// 
// 			 VkBool32 presentSupport = false;
// 			 vkGetPhysicalDeviceSurfaceSupportKHR(device, i, m_Surface, &presentSupport);
// 
// 			 if (presentSupport)
// 				 indices.presentFamily = i;
// 
// 			if (indices.isComplete())
// 			{
// 				break;
// 			}
// 			i++;
// 		}
// 		return indices;
// 	}
// 
// 	VkSurfaceFormatKHR VulkanContext::ChooseSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& surfaceFormats)
// 	{
// 		for (const auto& surfaceFormat : surfaceFormats)
// 		{
// 			if (surfaceFormat.format == VK_FORMAT_B8G8R8A8_SRGB && surfaceFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
// 				return surfaceFormat;
// 		}
// 		return surfaceFormats[0];
// 	}
// 
// 	VkPresentModeKHR VulkanContext::ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& presentModes)
// 	{
// 		for (const auto& presentMode : presentModes)
// 		{
// 			if (presentMode == VK_PRESENT_MODE_MAILBOX_KHR)
// 				return presentMode;
// 		}
// 		return VK_PRESENT_MODE_FIFO_KHR;
// 	}
// 
// 	VkInstance VulkanContext::GetInstance()
// 	{
// 		return *m_VulkanInstance;
// 	}
// 
// 	VkPhysicalDevice VulkanContext::GetPhysicalDevice()
// 	{
// 		return m_PhysicalDevice;
// 	}
// 
// 	VkDevice VulkanContext::GetDevice()
// 	{
// 		return m_Device;
// 	}
// 
// 	VkSurfaceKHR VulkanContext::GetSurface()
// 	{
// 		return m_Surface;
// 	}
// 
// 	VkQueue VulkanContext::GetGraphicsQueue()
// 	{
// 		return m_GraphicsQueue;
// 	}
// 
// 	VkQueue VulkanContext::GetComputeQueue()
// 	{
// 		return m_ComputeQueue;
// 	}
// 
// 	VkQueue VulkanContext::GetTransferQueue()
// 	{
// 		return m_TransferQueue;
// 	}
// 
// 	VkQueue VulkanContext::GetPresentQueue()
// 	{
// 		return m_PresentQueue;
// 	}
// 
// 	VkSwapchainKHR VulkanContext::GetSwapchain()
// 	{
// 		return m_Swapchain;
// 
// 	}
// 
// }