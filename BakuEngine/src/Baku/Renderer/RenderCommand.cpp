#include "bkpch.h"
#include "Baku/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Baku
{
    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}