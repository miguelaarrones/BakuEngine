#include "bkpch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Baku
{
    Shader* Shader::Create(const std::string& filePath)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                BK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!")
                    return nullptr;
            case RendererAPI::API::OpenGL:
                return new OpenGLShader(filePath);
        }

        BK_CORE_ASSERT(false, "Unknown RendererAPI!")
            return nullptr;
    }

    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                BK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!")
                    return nullptr;
            case RendererAPI::API::OpenGL:
                return new OpenGLShader(vertexSrc, fragmentSrc);
        }

        BK_CORE_ASSERT(false, "Unknown RendererAPI!")
            return nullptr;
    }
}