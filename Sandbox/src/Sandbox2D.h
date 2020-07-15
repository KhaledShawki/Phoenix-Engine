#pragma once

#include "Phoenix.h"

class Sandbox2D : public Phx::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	
	void OnUpdate(Phx::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Phx::Event& e) override;
private:
	Ref<Phx::Shader> m_Shader;

	Ref<Phx::VertexArray> m_VertexArray;
	
	Phx::OrthographicCameraController m_CameraController;

	Ref<Phx::Texture2D> m_CheckerboardTexture;
	Ref<Phx::Texture2D> m_SpriteSheet;
	Ref<Phx::SubTexture2D> m_TextureStairs; 

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

};