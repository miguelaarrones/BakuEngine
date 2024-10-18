#include "bkpch.h"
#include "Layer.h"

namespace Baku
{
    Baku::Layer::Layer(const std::string& name)
        : m_DebugName(name)
    {
    }

    Layer::~Layer()
    {
    }
}