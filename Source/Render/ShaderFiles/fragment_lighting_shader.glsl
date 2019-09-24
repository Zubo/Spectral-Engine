#version 330 core

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

uniform Material material;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;
uniform vec3 cameraDir;

vec3 getLightDir()
{
	return (lightPos - FragPos);
}

float getAtentuation(float distance) {
	return 1 / (1.0F + 0.1 * distance + 0.01 * distance * distance);
}

vec3 getDiffuseLight() 
{	
	vec3 lightDir = getLightDir();
	vec3 lightDirNormalized = normalize(lightDir);
	vec3 normalNormalized = normalize(Normal);
	float lightNormalDot =  dot(normalNormalized, lightDirNormalized);
	

	float diffuseIntensity = max(0, lightNormalDot) * getAtentuation(length(getLightDir()));

	vec3 diffuseLight = diffuseIntensity * vec3(texture(material.diffuseMapTex, TexCoords)) * lightColor;
	return diffuseLight;
}

vec3 getSpecular()
{
	vec3 lightDir = getLightDir();
	vec3 viewDir = (cameraPos - FragPos);
	vec3 reflectedDir = reflect(-lightDir, Normal);

	float viewReflectedDot = dot(normalize(reflectedDir), normalize(viewDir));
	float specIntensity = pow(max(0, viewReflectedDot), material.shininess);

	return specIntensity * material.specular * lightColor * vec3(texture(material.specularMapTex, TexCoords));
}

vec3 getFlashlightValue() {
	vec3 lightDirNormalized = normalize(FragPos - cameraPos);
	vec3 viewDirNormalized = -normalize(cameraDir);
	float dotProd = dot(lightDirNormalized, viewDirNormalized);

	if (dotProd < 0.95) {
		return vec3(0.0F, 0.0F, 0.0F);
	}

	float reducer = (dotProd - 0.95) / (1.0F - 0.95);	// normalize dotProd
	float atentuation = getAtentuation(length(FragPos - cameraPos));

	return atentuation * vec3(texture(material.diffuseMapTex, TexCoords)) * reducer;
}

void main()
{
	vec3 diffuseLight = getDiffuseLight();
	vec3 specular = getSpecular();
	vec3 ambientColor = material.ambient * vec3(texture(material.diffuseMapTex, TexCoords)) * getAtentuation(length(getLightDir()));
	vec3 totalLight = (ambientColor + diffuseLight + specular + getFlashlightValue());
	FragColor = vec4(totalLight, 1.0F);
}