#version 330 core

in vec3 position;

uniform samplerCube u_cubemap;

out vec4 FragColor;

void main()
{
    //FragColor = vec4(tcoord, 0.0, 1.0);
    FragColor = texture(u_cubemap, position);
}
