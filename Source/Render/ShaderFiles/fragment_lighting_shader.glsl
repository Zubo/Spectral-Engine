#version 330 core

#define LightTypePoint 1
#define LightTypeDirectional 2

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;


struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
	sampler2D diffuseMapTex;
	sampler2D specularMapTex;
};

struct Light {
	int lightType;
	vec3 color;
	vec3 position;
	vec3 direction;
};

uniform Material material;
uniform Light lightArray[10];
uniform int numberOfLights;
uniform vec3 cameraPos;
uniform vec3 cameraDir;

vec3 getLightDir(Light light)
{
	if (light.lightType == LightTypePoint)
	{
		return (FragPos - light.position);
	}
	else if (light.lightType == LightTypeDirectional)
	{
		return light.direction;
	}
}

float getAtentuation(float distance) {
	return 1 / (1.0F + 0.1 * distance + 0.01 * distance * distance);
}

vec3 getDiffuseLight(Light light) 
{	
	vec3 lightDir = getLightDir(light);
	vec3 lightDirNormalized = normalize(lightDir);
	vec3 normalNormalized = normalize(Normal);
	float lightNormalDot =  dot(normalNormalized, -lightDirNormalized);

	float diffuseIntensity = max(0, lightNormalDot) / length(FragPos - light.position);

	diffuseIntensity *= getAtentuation(length(getLightDir(light)));

	vec3 diffuseLight = diffuseIntensity *
						vec3(texture(material.diffuseMapTex, TexCoords)) *
						material.diffuse *
						light.color;
						
	return diffuseLight;
}

vec3 getSpecular(Light light)
{
	vec3 lightDir = getLightDir(light);
	vec3 viewDir = (FragPos - cameraPos);
	vec3 reflectedDir = reflect(lightDir, Normal);

	float viewReflectedDot = dot(normalize(reflectedDir), -normalize(viewDir));
	float specIntensity = max(0, viewReflectedDot);

	return specIntensity *
		material.specular *
		light.color *
		vec3(texture(material.specularMapTex, TexCoords));
}

vec3 getDirectionalLight(Light light) {
	vec3 lightDirNormalized = normalize(light.position - FragPos);
	vec3 viewDirNormalized = -normalize(light.direction);

	float dotProd = dot(lightDirNormalized, viewDirNormalized);
	if (dotProd < 0.95) {
		return vec3(0.0F, 0.0F, 0.0F);
	}

	float reducer = (dotProd - 0.95) / (1.0F - 0.95);	// normalize dotProd

	return vec3(texture(material.diffuseMapTex, TexCoords)) * reducer;
}

void main()
{
	vec3 totalLight;

	for (int i = 0; i < numberOfLights; ++i)
	{
		Light light = lightArray[i];

		if (light.lightType == LightTypePoint)
		{
			vec3 diffuseLight = getDiffuseLight(light);
			vec3 specularLight = getSpecular(light);
			totalLight += (diffuseLight + specularLight);
		}
		else if (light.lightType == LightTypeDirectional)
		{
			totalLight += getDirectionalLight(light);
		}
	}

	vec3 ambientColor = material.ambient *
						vec3(texture(material.diffuseMapTex, TexCoords));
	totalLight += ambientColor;
	
	FragColor = vec4(totalLight, 1.0F);
}
