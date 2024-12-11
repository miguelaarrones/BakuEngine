// Basic texture shader.

#type vertex
#version 450 core
            
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoord;

uniform mat4 u_ViewProjection;
uniform float u_TilingFactor;

out vec2 v_TexCoord;
out vec4 v_Color;

void main()
{
    v_Color = a_Color;
    v_TexCoord = a_TexCoord * u_TilingFactor;
    gl_Position = u_ViewProjection * vec4(a_Position, 1.0f);
}

#type fragment
#version 450 core
            
layout(location = 0) out vec4 color;

in vec4 v_Color;
in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
    // color = texture(u_Texture, v_TexCoord) * u_Color;
    color = v_Color;
}