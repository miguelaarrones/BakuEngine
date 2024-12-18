#pragma once

#include "Baku/Core/Core.h"

#include "Baku/Core/Window.h"
#include "Baku/Core/LayerStack.h"
#include "Baku/Events/Event.h"
#include "Baku/Events/ApplicationEvent.h"

#include "Baku/ImGui/ImGuiLayer.h"

#include "Baku/Core/Timestep.h"

int main(int argc, char** argv);

namespace Baku
{
    class Application
    {
    public:
        Application(const std::string& name = "Baku App");
        virtual ~Application();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        void Close();

        ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

        static Application& Get() { return *s_Instance; }

        Window& GetWindow() { return *m_Window; }
    private:
        void Run();

        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);
    private:
        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;
        float m_LastFrameTime = 0.0f;
    private:
        static Application* s_Instance;
        friend int ::main(int argc, char** argv);
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}

