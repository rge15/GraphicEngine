#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture flags
uniform int textureFlag;
// texture samplers
uniform sampler2D texture1;

void main()
{
	if( textureFlag == 1)
	{
    	FragColor = texture(texture1, TexCoord);
	}else
	{
		FragColor = vec4( ourColor, 1.0 );
	}
}