#pragma once

#include "Core.h"

#include "Window.h"
#include "Baku/LayerStack.h"
#include "Baku/Events/Event.h"
#include "Baku/Events/ApplicationEvent.h"

#include "Baku/ImGui/ImGuiLayer.h"

#include "Baku/Renderer/Shader.h"

namespace Baku
{
    class BAKU_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        inline static Application& Get() { return *s_Instance; }

        inline Window& GetWindow() { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

        std::unique_ptr<Shader> m_Shader;
    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}

