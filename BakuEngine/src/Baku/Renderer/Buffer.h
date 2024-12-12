#pragma once

namespace Baku
{
    enum class ShaderDataType
    {
        None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
    };

    static uint32_t ShaderDataTypeSize(ShaderDataType type)
    {
        switch (type)
        {
            case Baku::ShaderDataType::Float:    return 4;
            case Baku::ShaderDataType::Float2:   return 4 * 2;
            case Baku::ShaderDataType::Float3:   return 4 * 3;
            case Baku::ShaderDataType::Float4:   return 4 * 4;
            case Baku::ShaderDataType::Mat3:     return 3 * 3 * 3;
            case Baku::ShaderDataType::Mat4:     return 4 * 4 * 4;
            case Baku::ShaderDataType::Int:      return 4;
            case Baku::ShaderDataType::Int2:     return 4 * 2;
            case Baku::ShaderDataType::Int3:     return 4 * 3;
            case Baku::ShaderDataType::Int4:     return 4 * 4;
            case Baku::ShaderDataType::Bool:     return 1;
        }

        BK_CORE_ASSERT(false, "Unknow ShaderDataType!");
        return 0;
    }

    struct BufferElement
    {
        ShaderDataType Type;
        std::string Name;
        uint32_t Size;
        size_t Offset;
        bool Normalized;

        BufferElement() = default;

        BufferElement(ShaderDataType type, const std::string name, bool normalized = false)
            : Type(type), Name(name), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized)
        {
        }

        uint32_t GetComponentCount() const
        {
            switch (Type)
            {
                case Baku::ShaderDataType::Float:    return 1;
                case Baku::ShaderDataType::Float2:   return 2;
                case Baku::ShaderDataType::Float3:   return 3;
                case Baku::ShaderDataType::Float4:   return 4;
                case Baku::ShaderDataType::Mat3:     return 3;// 3 * float3;
                case Baku::ShaderDataType::Mat4:     return 4;// 4 * float4;
                case Baku::ShaderDataType::Int:      return 1;
                case Baku::ShaderDataType::Int2:     return 2;
                case Baku::ShaderDataType::Int3:     return 3;
                case Baku::ShaderDataType::Int4:     return 4;
                case Baku::ShaderDataType::Bool:     return 1;
            }

            BK_CORE_ASSERT(false, "Unknow ShaderDataType!");
            return 0;
        }
    };

    class BufferLayout
    {
    public:
        BufferLayout() = default;

        BufferLayout(const std::initializer_list<BufferElement>& elements)
            : m_Elements(elements) 
        {
            CalculateOffsetAndStride();
        }

        uint32_t GetStride() const { return m_Stride; }
        const std::vector<BufferElement>& GetElements() const { return m_Elements; }

        std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
        std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
        std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
        std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }
    private:
        void CalculateOffsetAndStride()
        {
            size_t offset = 0;
            m_Stride = 0;
            for (auto& element : m_Elements)
            {
                element.Offset = offset;
                offset += element.Size;
                m_Stride += element.Size;
            }
        }
    private:
        std::vector<BufferElement> m_Elements;
        uint32_t m_Stride;
    };

    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual const BufferLayout& GetLayout() const = 0;
        virtual void SetLayout(const BufferLayout& layout) = 0;

        virtual void SetData(const void* data, uint32_t size) = 0;

        static Ref<VertexBuffer> Create(uint32_t size);
        static Ref<VertexBuffer> Create(float* vertices, uint32_t size);
    };

    // Currently Baku only supports 32-bit index buffers
    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual uint32_t GetCount() const = 0;

        static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);
    };
}
