#pragma once

#include "Core.h"

#include "Window.h"
#include "Baku/LayerStack.h"
#include "Baku/Events/Event.h"
#include "Baku/Events/ApplicationEvent.h"

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
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}

