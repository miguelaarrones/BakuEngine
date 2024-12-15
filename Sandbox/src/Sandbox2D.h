#pragma once

#include "Baku.h"

#include "ParticleSystem.h"

class Sandbox2D : public Baku::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Baku::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Baku::Event& e) override;
private:
	Baku::OrthographicCameraController m_CameraController;

	// Temp
	Baku::Ref<Baku::Shader> m_FlatColorShader;
	Baku::Ref<Baku::VertexArray> m_SquareVA;

	Baku::Ref<Baku::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};
