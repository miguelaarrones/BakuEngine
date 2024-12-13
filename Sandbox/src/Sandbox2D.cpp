#include "Sandbox2D.h"

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
    : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{ 
}

void Sandbox2D::OnAttach()
{
    BK_PROFILE_FUNCTION();

    m_CheckerboardTexture = Baku::Texture2D::Create("assets/textures/Checkerboard.png");
    m_SpriteSheet = Baku::Texture2D::Create("assets/game/textures/tilemap_packed.png");

    m_TextureBarbarian = Baku::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 3, 3 }, { 16, 16 });
    m_TexturePillar = Baku::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 6, 8 }, { 16, 16 }, { 1, 3 });

    m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
    m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
    m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
    m_Particle.LifeTime = 1.0f;
    m_Particle.Velocity = { 0.0f, 0.0f };
    m_Particle.VelocityVariation = { 3.0f, 1.0f };
    m_Particle.Position = { 0.0f, 0.0f };
}

void Sandbox2D::OnDetach()
{
    BK_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Baku::Timestep ts)
{
    BK_PROFILE_FUNCTION();

	// Update
    m_CameraController.OnUpdate(ts);

	// Render
    Baku::Renderer2D::ResetStats();
    {
        BK_PROFILE_SCOPE("Renderer Prep");
        Baku::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        Baku::RenderCommand::Clear();
    }

	{
        BK_PROFILE_SCOPE("Renderer Draw");
#if 0
        static float rotation = 0.0f;
        rotation += ts * 50.0f;

		Baku::Renderer2D::BeginScene(m_CameraController.GetCamera());
	
        Baku::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0), { 0.8f, 0.2f, 0.3f, 1.0f });
        Baku::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
        Baku::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
        Baku::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
        Baku::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(rotation), m_CheckerboardTexture, 20.0f);
    
		Baku::Renderer2D::EndScene();

        Baku::Renderer2D::BeginScene(m_CameraController.GetCamera());
        for (float y = -5.0f; y < 5.0f; y += 0.5f)
        {
            for (float x = -5.0f; x < 5.0f; x += 0.5f)
            {
                glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f , (y + 5.0f) / 10.0f, 0.7f };
                Baku::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
            }
        }
        Baku::Renderer2D::EndScene();
#endif
        if (Baku::Input::IsMouseButtonPressed(BK_MOUSE_BUTTON_LEFT))
        {
            auto [x, y] = Baku::Input::GetMousePosition();
            auto width = Baku::Application::Get().GetWindow().GetWidth();
            auto height = Baku::Application::Get().GetWindow().GetHeight();

            auto bounds = m_CameraController.GetBounds();
            auto pos = m_CameraController.GetCamera().GetPosition();
            x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
            y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
            m_Particle.Position = { x + pos.x, y + pos.y };
            for (int i = 0; i < 5; i++)
                m_ParticleSystem.Emit(m_Particle);
        }

        Baku::Renderer2D::BeginScene(m_CameraController.GetCamera());

        Baku::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, m_TextureBarbarian);
        Baku::Renderer2D::DrawQuad({ 5.0f, 0.0f, 0.0f }, { 1.0f, 3.0f }, m_TexturePillar);

        Baku::Renderer2D::EndScene();

        m_ParticleSystem.OnUpdate(ts);
        m_ParticleSystem.OnRender(m_CameraController.GetCamera());

	}
}

void Sandbox2D::OnImGuiRender()
{
    BK_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

    ImGui::Text("Renderer2D Stats:");

    auto stats = Baku::Renderer2D::GetStats();
    ImGui::Text("Draw Calls: %d", stats.DrawCalls);
    ImGui::Text("Quad Count: %d", stats.QuadCount);
    ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
    ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	ImGui::End();
}

void Sandbox2D::OnEvent(Baku::Event& e)
{
	m_CameraController.OnEvent(e);
}
