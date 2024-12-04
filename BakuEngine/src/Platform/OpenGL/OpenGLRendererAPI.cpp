#include "bkpch.h"
#include "OpenGLRendererAPI.h"

#include "glad/glad.h"

namespace Baku
{
    void Baku::OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Baku::OpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    }

    void Baku::OpenGLRendererAPI::DrawIndex(const Ref<VertexArray>& vertexArray)
    {
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
    }
}
