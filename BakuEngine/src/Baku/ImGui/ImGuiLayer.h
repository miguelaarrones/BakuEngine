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

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };
}

