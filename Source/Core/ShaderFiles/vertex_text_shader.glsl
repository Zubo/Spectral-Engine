#version 330 core

layout (location = 0) in vec4 vertex;
out vec2 TexCoord;

uniform mat4 projection;

void main()
{
	gl_position = projection * (vec4(vertex.xy, 0.0F, 1.0F));
	TexCoord = vertex.zw;
}