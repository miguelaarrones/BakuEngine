#include "bkpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Baku
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_windowHandle(windowHandle)
    {
        BK_CORE_ASSERT(windowHandle, "Window handle is null!")
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_windowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        BK_CORE_ASSERT(status, "Failed to initialize Glad!");

        BK_CORE_INFO("OpenGL Info:");
        BK_CORE_INFO("   Vendor: {0}", (const char*)glGetString(GL_VENDOR));
        BK_CORE_INFO("   Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        BK_CORE_INFO("   Version: {0}", (const char*)glGetString(GL_VERSION));

#ifdef BK_ENABLE_ASSERTS
        int versionMajor;
        int versionMinor;
        glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
        glGetIntegerv(GL_MINOR_VERSION, &versionMinor);
        BK_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Hazel requires at least OpenGL version 4.5!");
#endif
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_windowHandle);
    }
}