#include "bkpch.h"
#include "Scene.h"

#include "Components.h"
#include "Baku/Renderer/Renderer2D.h"

#include <glm/glm.hpp>

namespace Baku
{
	Scene::Scene()
	{
		
#if ENTT_EXAMPLE_CODE
		entt::entity entity = m_Registry.create();

		auto& transform = m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));
		auto& mesh = m_Registry.emplace<MeshComponent>(entity);

		transform = glm::mat4(4.0f);

		// TransformComponent& transform = m_Registry.get<TransformComponent>(entity);

		if (m_Registry.try_get<TransformComponent>(entity))
		{
			TransformComponent& transform = m_Registry.get<TransformComponent>(entity);
		}

		auto view = m_Registry.view<TransformComponent>();
		for (auto entity : view)
		{
			TransformComponent& transform = view.get<TransformComponent>(entity);
		}

		auto group = m_Registry.group(entt::get<MeshComponent, TransformComponent>);
		for (auto entity : group)
		{
			auto[transform, mesh] = group.get<TransformComponent, MeshComponent>(entity);
		}

		m_Registry.remove<TransformComponent>(entity);
		m_Registry.clear();
#endif

	}

	Scene::~Scene()
	{

	}

	entt::entity Scene::CreateEntity()
	{
		return m_Registry.create();
	}

	void Scene::OnUpdate(Timestep ts)
	{
		auto group = m_Registry.group(entt::get<TransformComponent, SpriteRendererComponent>);
		for (auto entity : group)
		{
			auto [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

			Renderer2D::DrawQuad(transform, sprite.Color);
		}
	}
}