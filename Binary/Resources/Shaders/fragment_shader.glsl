#version 330 core
out vec4 FragColor;
in vec2 texCoordinates;

uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
    FragColor = mix(texture(tex0, texCoordinates), texture(tex1, texCoordinates), 0.75);
}
