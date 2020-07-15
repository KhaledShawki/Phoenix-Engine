 #include "phxpch.h"
// 
#include "VulkanShader.h"
// #include "VulkanContext.h"
// 
// 
// extern  VkDevice GetDevice();
// 
// namespace Phx {
// 
// 
// 	VulkanShader::VulkanShader(const std::string& filepath)
// 	{
// 
// 	}
// 
// 	VulkanShader::VulkanShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
// 	{	
// 		VkDevice device = GetDevice();
// 
// 		VkShaderModuleCreateInfo vertexShaderModuleCreateInfo = { VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO };
// 		vertexShaderModuleCreateInfo.codeSize = vertexSrc.size();
// 		vertexShaderModuleCreateInfo.pCode = reinterpret_cast<const uint32_t*>(vertexSrc.data());
// 		VkShaderModule vertexShader;
// 		PHX_VK_ASSERT(vkCreateShaderModule(device, &vertexShaderModuleCreateInfo, nullptr, &vertexShader),
// 			"Could not create vertex shader");
// 	
// 		VkShaderModuleCreateInfo fragmentShaderModuleCreateInfo = { VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO };
// 		fragmentShaderModuleCreateInfo.codeSize = fragmentSrc.size();
// 		fragmentShaderModuleCreateInfo.pCode = reinterpret_cast<const uint32_t*>(fragmentSrc.data());
// 		VkShaderModule fragmentShader;
// 		PHX_VK_ASSERT(vkCreateShaderModule(device, &fragmentShaderModuleCreateInfo, nullptr, &fragmentShader),
// 			"Could not create fragment shader");
// 
// 	}
// 
// 	void VulkanShader::Bind() const
// 	{
// 
// 	}
// 
// 	void VulkanShader::Unbind() const
// 	{
// 
// 	}
// 
// 	void VulkanShader::SetUniformInt(const std::string& name, int value)
// 	{
// 
// 	}
// 
// 	void VulkanShader::SetUniformVec(const std::string& name, float value)
// 	{
// 
// 	}
// 
// 	void VulkanShader::SetUniformVec2(const std::string& name, const glm::vec2& value)
// 	{
// 
// 	}
// 
// 	void VulkanShader::SetUniformVec3(const std::string& name, const glm::vec3& value)
// 	{
// 
// 	}
// 
// 	void VulkanShader::SetUniformVec4(const std::string& name, const glm::vec4& value)
// 	{
// 
// 	}
// 
// 	void VulkanShader::SetUniformMat3(const std::string& name, const glm::mat3& matrix)
// 	{
// 
// 	}
// 
// 	void VulkanShader::SetUniformMat4(const std::string& name, const glm::mat4& matrix)
// 	{
// 
// 	}
// 
// 	const std::string& VulkanShader::GetName() const
// 	{
// 		return m_Name;
// 	}
// 
// 	std::string VulkanShader::ReadFile(const std::string& filepath)
// 	{
// 		return nullptr;
// 	}
// 
// }