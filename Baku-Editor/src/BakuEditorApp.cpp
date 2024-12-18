#include <Baku.h>
#include <Baku/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Baku
{
    class BakuEditor : public Application
    {
    public:
        BakuEditor()
            : Application("Baku Editor")
        {
            PushLayer(new EditorLayer());
        }
        ~BakuEditor()
        {

        }
    };

    Application* CreateApplication()
    {
        return new BakuEditor();
    }
}

