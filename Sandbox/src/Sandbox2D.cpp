#include "Sandbox2D.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{

}

void Sandbox2D::OnAttach()
{
	PHX_PROFILE_FUNCTION();

	m_CheckerboardTexture = Phx::Texture2D::Create("assets/Texture/Checkerboard.png");
	m_SpriteSheet = Phx::Texture2D::Create("assets/SpriteSheet/RPGpack_sheet_2X.png");
	m_TextureStairs = Phx::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 7, 6 }, { 128, 128 });
}

void Sandbox2D::OnDetach()
{
	PHX_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Phx::Timestep ts)
{
	PHX_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Phx::Renderer2D::ResetStats();
	{
		PHX_PROFILE_SCOPE("Renderer Prep");
		Phx::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Phx::RenderCommand::Clear();
	}
	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;
		PHX_PROFILE_SCOPE("Renderer Draw");
		Phx::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Phx::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, rotation, { 0.8f, 0.2f, 0.3f, 1.0f });
		Phx::Renderer2D::DrawRotatedQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, -rotation, { 0.2f, 0.3f, 0.8f, 1.0f });
		Phx::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Phx::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
		Phx::Renderer2D::EndScene();

// 		Phx::Renderer2D::BeginScene(m_CameraController.GetCamera());
// 		for (float y = -5.0f; y < 5.0f; y += 0.5f)
// 		{
// 			for (float x = -5.0f; x < 5.0f; x += 0.5f)
// 			{
// 				glm::vec4 color = { (x + 5.0f) / 10.0f ,0.4f, (y + 5.0f) / 10.0f ,0.7f };
// 				Phx::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
// 			}
// 		}
// 		Phx::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	PHX_PROFILE_FUNCTION();

	uint64_t  totalAllocated = Phx::MemoryManager::Get()->GetMemoryState()->totalAllocated / (1024 * 1024);
	uint64_t totalFreed = Phx::MemoryManager::Get()->GetMemoryState()->totalFreed / (1024 * 1024);
	uint64_t currentUsed = Phx::MemoryManager::Get()->GetMemoryState()->currentUsed / (1024 * 1024);
	uint64_t totalAllocations = Phx::MemoryManager::Get()->GetMemoryState()->totalAllocations / 1000;

	uint64_t totalPhysicalMemory = Phx::MemoryManager::Get()->GetSystemMemoryInfo()->totalPhysicalMemory / (1024 * 1024);
	uint64_t availablePhysicalMemory = Phx::MemoryManager::Get()->GetSystemMemoryInfo()->availablePhysicalMemory / (1024 * 1024);



	static bool dockspaceOpean = true;
	static bool optFullscreenPersistant = true;
	bool optFullscreen = optFullscreenPersistant;
	static ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None;

	// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
	// because it would be confusing to have two docking targets within each others.
	ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
	if (optFullscreen)
	{
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->GetWorkPos());
		ImGui::SetNextWindowSize(viewport->GetWorkSize());
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
	}

	// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
	// and handle the pass-thru hole, so we ask Begin() to not render a background.
	if (dockspaceFlags & ImGuiDockNodeFlags_PassthruCentralNode)
		windowFlags |= ImGuiWindowFlags_NoBackground;

	// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
	// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
	// all active windows docked into it will lose their parent and become undocked.
	// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
	// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("DockSpace Demo", &dockspaceOpean, windowFlags);
	ImGui::PopStyleVar();

	if (optFullscreen)
		ImGui::PopStyleVar(2);

	// DockSpace
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
	{
		ImGuiID dockspaceID = ImGui::GetID("MyDockSpace");
		ImGui::DockSpace(dockspaceID, ImVec2(0.0f, 0.0f), dockspaceFlags);
	}
	

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			// Disabling fullscreen would allow the window to be moved to the front of other windows,
			// which we can't undo at the moment without finer window depth/z control.
			//ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);

			if (ImGui::MenuItem("Exit"))	Phx::Application::Get().Close();
			ImGui::EndMenu();
		}
	
		ImGui::EndMenuBar();
	}


	ImGui::Begin("Memory Tracing");
	ImGui::TextColored(ImVec4(0, 255, 255, 1), "Total allocated : %d MB", totalAllocated);
	ImGui::TextColored(ImVec4(255, 0, 0, 1), "Total freed : %d MB", totalFreed);
	ImGui::TextColored(ImVec4(0, 255, 0, 1), "Current used : %d MB", currentUsed);
	ImGui::TextColored(ImVec4(255, 255, 0, 1), "Allocations count : %dK", totalAllocations);
	ImGui::End();


	ImGui::Begin("System Memory info");
	ImGui::TextColored(ImVec4(0, 255, 255, 1), "Total Physical Memory : %d MB", totalPhysicalMemory);
	ImGui::TextColored(ImVec4(255, 0, 0, 1), "Available Physical Memory : %d MB", availablePhysicalMemory);
	ImGui::End();

	auto stats = Phx::Renderer2D::GetStats();

	ImGui::Begin("Setting");

	ImGui::Text("Renderer2d Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::End();

	ImGui::End();

}

void Sandbox2D::OnEvent(Phx::Event& e)
{
	m_CameraController.OnEvent(e);
}
