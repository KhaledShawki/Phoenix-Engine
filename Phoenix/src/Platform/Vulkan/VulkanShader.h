// #pragma once
// 
// #include "Phoenix/EvaRenderer/Shader.h"
// 
// namespace Phx {
// 
// 	class VulkanShader : public Shader
// 	{
// 	public:
// 		VulkanShader(const std::string& filepath);
// 		VulkanShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
// 
// 		virtual void Bind() const override;
// 		virtual void Unbind() const override;
// 
// 		virtual void SetUniformInt(const std::string& name, int value) override;
// 
// 		virtual void SetUniformVec(const std::string& name, float value) override;
// 		virtual void SetUniformVec2(const std::string& name, const glm::vec2& value) override;
// 		virtual void SetUniformVec3(const std::string& name, const glm::vec3& value) override;
// 		virtual void SetUniformVec4(const std::string& name, const glm::vec4& value) override;
// 
// 		virtual void SetUniformMat3(const std::string& name, const glm::mat3& matrix) override;
// 		virtual void SetUniformMat4(const std::string& name, const glm::mat4& matrix) override;
// 
// 		virtual const std::string& GetName() const override;
// 
// 	private:
// 		std::string ReadFile(const std::string& filepath);
// 		std::string m_Name;
// 
// 	};
// }