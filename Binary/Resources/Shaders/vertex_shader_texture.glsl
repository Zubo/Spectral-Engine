#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aUV;

out vec2 uV;

uniform mat4 modelMatrix;

void main()
{
    uV = aUV;

    gl_Position = modelMatrix * vec4(aPos, 1.0F);
}