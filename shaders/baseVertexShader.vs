#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aTextureCoord;

uniform vec3 u_baseColor;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec3 ourColor;
out vec2 TexCoord;

void main()
{
    //Aquí indicamos la posición del vertice
    gl_Position = u_projection * u_view * u_model * vec4(aPos, 1.0);
    //Aquñi seteamos las UV Coords
    TexCoord = vec2(aTextureCoord);
    //Aquñi seteamos el color base
    ourColor = u_baseColor;
}