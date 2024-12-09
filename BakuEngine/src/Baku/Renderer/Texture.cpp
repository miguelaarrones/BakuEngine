#include "bkpch.h"
#include "Baku/Renderer/Texture.h"
#include "Baku/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLTexture.h"

namespace Baku
{
    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                BK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!")
                    return nullptr;
            case RendererAPI::API::OpenGL:
                return CreateRef<OpenGLTexture2D>(width, height);
        }

        BK_CORE_ASSERT(false, "Unknown RendererAPI!")
            return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                BK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!")
                    return nullptr;
            case RendererAPI::API::OpenGL:
                return CreateRef<OpenGLTexture2D>(path);
        }

        BK_CORE_ASSERT(false, "Unknown RendererAPI!")
            return nullptr;
    }
}
