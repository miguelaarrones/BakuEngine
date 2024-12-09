#include "bkpch.h"
#include "Baku/Renderer/VertexArray.h"
#include "Baku/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Baku
{
    Ref<VertexArray> VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                BK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!")
                return nullptr;
            case RendererAPI::API::OpenGL:
                return CreateRef<OpenGLVertexArray>();
        }

        BK_CORE_ASSERT(false, "Unknown RendererAPI!")
            return nullptr;
    }
}