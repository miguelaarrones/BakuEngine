#include <Baku.h>
#include <Baku/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public Baku::Layer
{
public:
    ExampleLayer()
        : Layer("Example"), m_CameraController(1280.0f / 720.0f, true)
    { 
        m_VertexArray = Baku::VertexArray::Create();
        m_VertexArray->Bind();

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };

        Baku::Ref<Baku::VertexBuffer> vertexBuffer;
        vertexBuffer = Baku::VertexBuffer::Create(vertices, sizeof(vertices));
        Baku::BufferLayout layout = {
            { Baku::ShaderDataType::Float3, "a_Position" },
            { Baku::ShaderDataType::Float4, "a_Color" }
        };

        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        uint32_t indices[3] = { 0, 1, 2 };
        Baku::Ref<Baku::IndexBuffer> indexBuffer;
        indexBuffer = Baku::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        m_SquareVA = Baku::VertexArray::Create();

        float squareVertices[5 * 4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
        };

        Baku::Ref<Baku::VertexBuffer> squareVB;
        squareVB = Baku::VertexBuffer::Create(squareVertices, sizeof(squareVertices));

        squareVB->SetLayout({
            { Baku::ShaderDataType::Float3, "a_Position" },
            { Baku::ShaderDataType::Float2, "a_TextCoord" }
        });
        m_SquareVA->AddVertexBuffer(squareVB);

        uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
        Baku::Ref<Baku::IndexBuffer> squareIB;
        squareIB = (Baku::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

        m_SquareVA->SetIndexBuffer(squareIB);

        std::string vertexSrc = R"(
            #version 450 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec3 v_Position;
            out vec4 v_Color;

            void main()
            {
                v_Position = a_Position;
                v_Color = a_Color;
                gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0f);
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

        std::string flatColorShaderVertexSrc = R"(
            #version 450 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec3 v_Position;

            void main()
            {
                v_Position = a_Position;
                gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0f);
            }
        )";

        std::string flatColorShaderFragmentSrc = R"(
            #version 450 core
            
            layout(location = 0) out vec4 color;

            in vec3 v_Position;

            uniform vec3 u_Color;

            void main()
            {
                color = vec4(u_Color, 1.0f);
            }
        )";

        m_Shader = Baku::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);
        m_FlatColorShader = Baku::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);
        auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

        m_Texture = Baku::Texture2D::Create("assets/textures/Checkerboard.png");
        m_LogoTexture = Baku::Texture2D::Create("assets/textures/Logo.png");

        std::dynamic_pointer_cast<Baku::OpenGLShader>(textureShader)->Bind();
        std::dynamic_pointer_cast<Baku::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
    }

    void OnUpdate(Baku::Timestep ts) override
    {
        // Update
        m_CameraController.OnUpdate(ts);

        // Render
        Baku::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        Baku::RenderCommand::Clear();

        Baku::Renderer::BeginScene(m_CameraController.GetCamera());

        glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

        std::dynamic_pointer_cast<Baku::OpenGLShader>(m_FlatColorShader)->Bind();
        std::dynamic_pointer_cast<Baku::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

        for (int y = 0; y < 20; y++)
        {
            for (int x = 0; x < 20; x++)
            {
                glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
                glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
                Baku::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
            }
        }

        auto textureShader = m_ShaderLibrary.Get("Texture");

        m_Texture->Bind();
        Baku::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
        
        m_LogoTexture->Bind();
        Baku::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

        // Triangle
        // Baku::Renderer::Submit(m_Shader, m_VertexArray);

        Baku::Renderer::EndScene();
    }   

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Settings");

        ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));

        ImGui::End();
    }

    void OnEvent(Baku::Event& e) override
    {
        m_CameraController.OnEvent(e);
    }
private:
    Baku::ShaderLibrary m_ShaderLibrary;
    Baku::Ref<Baku::Shader> m_Shader;
    Baku::Ref<Baku::VertexArray> m_VertexArray;

    Baku::Ref<Baku::Shader> m_FlatColorShader;
    Baku::Ref<Baku::VertexArray> m_SquareVA;

    Baku::Ref<Baku::Texture2D> m_Texture, m_LogoTexture;

    Baku::OrthographicCameraController m_CameraController;

    glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Baku::Application
{
public:
    Sandbox()
    {
        // PushLayer(new ExampleLayer());
        PushLayer(new Sandbox2D());
    }
    ~Sandbox()
    {

    }
};

Baku::Application* Baku::CreateApplication()
{
    return new Sandbox();
}