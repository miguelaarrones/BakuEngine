#pragma once

#include "Baku/Layer.h"
#include "Baku/Events/MouseEvent.h"
#include "Baku/Events/KeyEvent.h"
#include "Baku/Events/ApplicationEvent.h"

namespace Baku
{
    class BAKU_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };
}

