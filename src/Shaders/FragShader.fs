#version core 330
out vec4 FragColor;

in vec2 oTextCoords;

uniform sampler2D texture1;

void main()
{
	FragColor = texture(texture1, oTextCoords);
}