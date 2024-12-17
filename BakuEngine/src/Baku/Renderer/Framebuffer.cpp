#include "bkpch.h"
#include "Framebuffer.h"

#include "Baku/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Baku
{
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                BK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!")
                    return nullptr;
            case RendererAPI::API::OpenGL:
                return CreateRef<OpenGLFramebuffer>(spec);
        }

        BK_CORE_ASSERT(false, "Unknown RendererAPI!")
            return nullptr;
	}
}
