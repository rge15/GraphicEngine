#version core 330
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTextCoords;

out vec2 oTextCoords;

void main()
{
	gl_Position = vec4(aPosition, 1.0);
	oTextCoords = aTextCoords;
}