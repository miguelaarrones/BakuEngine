#pragma once

#include "Core.h"

#include "Window.h"
#include "Baku/LayerStack.h"
#include "Baku/Events/Event.h"
#include "Baku/Events/ApplicationEvent.h"

#include "Baku/ImGui/ImGuiLayer.h"

#include "Baku/Renderer/OrthographicCamera.h"

namespace Baku
{
    class Application
    {
    public:
        Application();
        virtual ~Application() = default;

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
    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}

