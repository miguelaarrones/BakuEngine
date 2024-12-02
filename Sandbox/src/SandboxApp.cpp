#include <Baku.h>

#include "imgui/imgui.h"

class ExampleLayer : public Baku::Layer
{
public:
    ExampleLayer()
        : Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
    { 
        m_VertexArray.reset(Baku::VertexArray::Create());
        m_VertexArray->Bind();

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };

        std::shared_ptr<Baku::VertexBuffer> vertexBuffer;
        vertexBuffer.reset(Baku::VertexBuffer::Create(vertices, sizeof(vertices)));
        Baku::BufferLayout layout = {
            { Baku::ShaderDataType::Float3, "a_Position" },
            { Baku::ShaderDataType::Float4, "a_Color" }
        };

        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        uint32_t indices[3] = { 0, 1, 2 };
        std::shared_ptr<Baku::IndexBuffer> indexBuffer;
        indexBuffer.reset(Baku::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        m_SquareVA.reset(Baku::VertexArray::Create());

        float squareVertices[3 * 4] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
        };

        std::shared_ptr<Baku::VertexBuffer> squareVB;
        squareVB.reset(Baku::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

        squareVB->SetLayout({
            { Baku::ShaderDataType::Float3, "a_Position" },
        });
        m_SquareVA->AddVertexBuffer(squareVB);

        uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
        std::shared_ptr<Baku::IndexBuffer> squareIB;
        squareIB.reset((Baku::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t))));

        m_SquareVA->SetIndexBuffer(squareIB);

        std::string vertexSrc = R"(
            #version 450 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;

            out vec3 v_Position;
            out vec4 v_Color;

            void main()
            {
                gl_Position = u_ViewProjection * vec4(a_Position, 1.0f);
                v_Position = a_Position;
                v_Color = a_Color;
            }
        )";

        std::string fragmentSrc = R"(
            #version 450 core
            
            layout(location = 0) out vec4 color;

            in vec3 v_Position;
            in vec4 v_Color;

            void main()
            {
                color = vec4(v_Position * 0.5f + 0.5f, 1.0f);
                color = v_Color;
            }
        )";

        m_Shader.reset(new Baku::Shader(vertexSrc, fragmentSrc));

        std::string blueShaderVertexSrc = R"(
            #version 450 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;

            out vec3 v_Position;

            void main()
            {
                gl_Position = u_ViewProjection * vec4(a_Position, 1.0f);
                v_Position = a_Position;
            }
        )";

        std::string blueShaderFragmentSrc = R"(
            #version 450 core
            
            layout(location = 0) out vec4 color;

            in vec3 v_Position;

            void main()
            {
                color = vec4(0.2f, 0.3f, 0.8f, 1.0f);
            }
        )";

        m_BlueShader.reset(new Baku::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
    }

    void OnUpdate(Baku::Timestep ts) override
    {
        if (Baku::Input::IsKeyPressed(BK_KEY_LEFT))
            m_CameraPosition.x -= m_CameraMoveSpeed * ts;
        else if (Baku::Input::IsKeyPressed(BK_KEY_RIGHT))
            m_CameraPosition.x += m_CameraMoveSpeed * ts;

        if (Baku::Input::IsKeyPressed(BK_KEY_UP))
            m_CameraPosition.y += m_CameraMoveSpeed * ts;
        else if (Baku::Input::IsKeyPressed(BK_KEY_DOWN))
            m_CameraPosition.y -= m_CameraMoveSpeed * ts;

        if (Baku::Input::IsKeyPressed(BK_KEY_Q))
            m_CameraRotation += m_CameraRotationSpeed * ts;
        else if (Baku::Input::IsKeyPressed(BK_KEY_E))
            m_CameraRotation -= m_CameraRotationSpeed * ts;


        Baku::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        Baku::RenderCommand::Clear();

        m_Camera.SetPosition(m_CameraPosition);
        m_Camera.SetRotation(m_CameraRotation);

        Baku::Renderer::BeginScene(m_Camera);

        Baku::Renderer::Submit(m_BlueShader, m_SquareVA);
        Baku::Renderer::Submit(m_Shader, m_VertexArray);

        Baku::Renderer::EndScene();
    }   

    virtual void OnImGuiRender() override
    {

    }

    void OnEvent(Baku::Event& event) override
    {

    }
private:
    std::shared_ptr<Baku::Shader> m_Shader;
    std::shared_ptr<Baku::VertexArray> m_VertexArray;

    std::shared_ptr<Baku::Shader> m_BlueShader;
    std::shared_ptr<Baku::VertexArray> m_SquareVA;

    Baku::OrthographicCamera m_Camera;
    glm::vec3 m_CameraPosition;
    float m_CameraMoveSpeed = 5.0f;

    float m_CameraRotation = 0.0f;
    float m_CameraRotationSpeed = 180.0f;
};

class Sandbox : public Baku::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }
    ~Sandbox()
    {

    }
};

Baku::Application* Baku::CreateApplication()
{
    return new Sandbox();
}