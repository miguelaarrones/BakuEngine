#include "bkpch.h"
#include "Baku/Renderer/GraphicsContext.h"
#include "Baku/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLContext.h"

namespace Baku
{
	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    BK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		BK_CORE_ASSERT(false, "Unknown RendererAPI!");
		
		return nullptr;
	}
}