#pragma once

#include "Baku/Core/Layer.h"
#include "Baku/Events/MouseEvent.h"
#include "Baku/Events/KeyEvent.h"
#include "Baku/Events/ApplicationEvent.h"

namespace Baku
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnEvent(Event& e) override;

        void Begin();
        void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }
    private:
        bool m_BlockEvents = true;
        float m_Time = 0.0f;
    };
}

