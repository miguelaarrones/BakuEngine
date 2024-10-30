#include "bkpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Baku
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}