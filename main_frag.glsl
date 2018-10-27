#version 330 core

in vec2 TexCoords;
out vec4 FragColor;

uniform sampler2D texture1;

void main()
{
	FragColor = vec4(texture(texture1, TexCoords));
}