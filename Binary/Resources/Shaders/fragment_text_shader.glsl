#version 330 core

in vec2 TexCoord;
out vec4 color;

uniform sampler2D textu;
uniform vec3 TextColor;

void main()
{
	vec4 sampled = vec4(1.0F, 1.0F, 1.0F, texture(textu, TexCoord).r);
	color = sampled * vec4(vec3(1.0F), 1.0F);
}
