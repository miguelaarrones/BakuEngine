#include "bkpch.h"
#include "Baku/Core/Application.h"

#include "Baku/Core/Log.h"
#include "Baku/Core/Input.h"
#include "Baku/Renderer/Renderer.h"

#include <GLFW/glfw3.h>

namespace Baku
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        BK_PROFILE_FUNCTION();

        BK_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = Window::Create();
        m_Window->SetEventCallback(BK_BIND_EVENT_FN(Application::OnEvent));

        Renderer::Init();

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    Application::~Application() 
    {
        BK_PROFILE_FUNCTION();

        Renderer::Shutdown();
    }

    void Application::PushLayer(Layer* layer)
    {
        BK_PROFILE_FUNCTION();

        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* overlay)
    {
        BK_PROFILE_FUNCTION();

        m_LayerStack.PushLayer(overlay);
        overlay->OnAttach();
    }

    void Application::OnEvent(Event& e)
    {
        BK_PROFILE_FUNCTION();

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BK_BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(BK_BIND_EVENT_FN(Application::OnWindowResize));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    void Application::Run()
    {
        BK_PROFILE_FUNCTION();

        while (m_Running)
        {
            BK_PROFILE_FUNCTION("Run Loop");

            float time = (float)glfwGetTime();
            Timestep timestep = time - m_LastFrameTime;
            m_LastFrameTime = time;

            if (!m_Minimized)
            {
                {
                    BK_PROFILE_SCOPE("LayerStack OnUpdate");

                    for (Layer* layer : m_LayerStack)
                        layer->OnUpdate(timestep);
                }
                
                m_ImGuiLayer->Begin();
                {
                    BK_PROFILE_SCOPE("LayerStack OnImGuiRender");

                    for (Layer* layer : m_LayerStack)
                        layer->OnImGuiRender();
                }
                m_ImGuiLayer->End();
            }

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        BK_PROFILE_FUNCTION();

        if (e.GetWidth() == 0 || e.GetHeight() == 0)
        {
            m_Minimized = true;
            return false;
        }

        m_Minimized = false;
        Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

        return false;
    }
}
