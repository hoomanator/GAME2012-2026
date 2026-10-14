#version 330
layout (location = 0) in vec2 vPos;
layout (location = 1) in vec3 vCol;
out vec3 color;

uniform mat4 u_mvp;     // world * view * proj

void main()
{
    vec4 pos = vec4(vPos, 0.0, 1.0);

    color = vCol;

    gl_Position = u_mvp * pos;
}
