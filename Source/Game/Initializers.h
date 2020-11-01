/****************************************
**
**	FOR TESTING PURPOSES - WILL BE REMOVED WHEN THE SCENE SERIALIZATION SYSTEM
**	IS IMPLEMENTED
**
*****************************************/

#pragma once
#include <memory>
#include <random>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <time.h>

#include "Render/Shader/Shader.h"
#include "Game/Components/CameraTransform.h"
#include "Game/Components/Material.h"
#include "Game/Components/Transform.h"
#include "Game/Components/Renderer.h"
#include "Game/Components/Camera.h"
#include "Game/Components/CameraInputHandler.h"
#include "Game/Components/FPSCounter.h"
#include "Game/Components/LightSource.h"
#include "Game/Components/PositionOscilator.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Vertices.h"
#include "Render/MeshContainer.h"
#include "Render/Enum/LightType.h"
#include "Game/Components/Rotator.h"
#include "Render/UI/Font/Font.h"
#include "Core/Math/Radian.h"

namespace sp {
	constexpr SpUnsigned SCR_WIDTH = 800;
	constexpr SpUnsigned SCR_HEIGHT = 600;
	std::default_random_engine generator{ (SpUnsigned)time(0) };
	std::uniform_real_distribution<float> distribution{ 0.0F, 1.0F };

	void setRandomColors(Material & material) {
		Vector3 ambient{ 0.2F };
		material.setAmbient(ambient);

		Vector3 diffuse{ distribution(generator) };
		material.setDiffuse(diffuse);

		Vector3 specular{ distribution(generator) };
		material.setSpecular(specular);

		SpFloat shininess{ 1.0F + 31 * distribution(generator) };
		material.setShinines(shininess);
	}

	GameObject * createLight(SpString const & shadersFolderPath, SpString const texturePathArray[], SpInt const lightSourceIndex) {
		GameObject * lightSourceGameObject = new GameObject;

		OptionalRef<Transform> transformOptionalRef = lightSourceGameObject->addComponent<Transform>();
		if (transformOptionalRef.HasRef()) {
			transformOptionalRef->setPosition(cubePositions[lightSourceIndex]);
			transformOptionalRef->setScale(Vector3{ 0.1F });
		}

		OptionalRef<Renderer> rendererOptionalRef = lightSourceGameObject->addComponent<Renderer>();
		if (rendererOptionalRef.HasRef()) {
			SpUnsigned const meshId = MeshContainer::createMesh(verticesUV, (int)(sizeof(verticesUV) / sizeof(float)), indices, (int)sizeof(indices), true, false);
			rendererOptionalRef->initRenderer(meshId);
		}

		SpString const vertexLightingShaderPath{ shadersFolderPath + SpString{ "/vertex_shader.glsl" } };
		SpString const fragmentLightingShaderPath{ shadersFolderPath + SpString{ "/fragment_lamp_shader.glsl" } };
		OptionalRef<Material> material = lightSourceGameObject->addComponent<Material>();
		if (material.HasRef()) {
			material->initMaterial(vertexLightingShaderPath, fragmentLightingShaderPath);
			const SpInt numberOfTextures = 2;
			material->initMaterial(vertexLightingShaderPath, fragmentLightingShaderPath);
		}

		OptionalRef<LightSource> pointLightSourceRef = lightSourceGameObject->addComponent<LightSource>();
		if (pointLightSourceRef.HasRef()) {
			pointLightSourceRef->initLightSource(LightType::Point);
		}

		lightSourceGameObject->addComponent<PositionOscilator>();
		lightSourceGameObject->addComponent<Rotator>();
		OptionalRef<LightSource> directionalLightSourceRef = lightSourceGameObject->addComponent<LightSource>();
		if (directionalLightSourceRef.HasRef()) {
			directionalLightSourceRef->initLightSource(LightType::Directional);
		}

		return lightSourceGameObject;
	}

	void createBoxObjects(
		SpString const & bigBoxTexture, SpString const & specularMapTexturePath, SpString const & diffuseMapTexturePath, SpString const & vertexShaderPath,
		SpString const & fragmentShaderPath, SpInt const numberOfBoxes, Transform & cameraTransform, Transform & lightSourceTrnasform) {

		GameObject * boxObjects = new GameObject[numberOfBoxes];

		for (SpInt i = 0; i < numberOfBoxes; ++i) {

			OptionalRef<Renderer> renderer = boxObjects[i].addComponent<Renderer>();
			if (renderer.HasRef()) {
				SpUnsigned const meshId = MeshContainer::createMesh(verticesUVNormals,
					(int)(sizeof(verticesUVNormals) / sizeof(float)), indices, (int)(sizeof(indices) / sizeof(int)), true, true);
				renderer->initRenderer(meshId);
			}

			OptionalRef<Material> materialRef = boxObjects[i].addComponent<Material>();

			if (materialRef.HasRef()) {
				materialRef->initMaterial(vertexShaderPath, fragmentShaderPath);
				if (i == 0) {
					materialRef->setDiffuseMap(bigBoxTexture);
					materialRef->setSpecularMap(bigBoxTexture);
				}
				else {
					materialRef->setDiffuseMap(diffuseMapTexturePath);
					materialRef->setSpecularMap(specularMapTexturePath);
				}
			}

			setRandomColors(materialRef);

			if (i % 2) {
				boxObjects[i].addComponent<Rotator>();
			}


			OptionalRef<Transform> transform = boxObjects[i].addComponent<Transform>();
			if (transform.HasRef()) {
				transform->setPosition(cubePositions[i]);
				if (i == 0) {
					transform->setScale(Vector3{ 50.0F });
				}
			}
		}
	}

	void initScene() {
		GameObject * const cameraGameObject = new GameObject();
		auto cameraTransformRef = cameraGameObject->addComponent<CameraTransform>();
		OptionalRef<Camera> cameraRef = cameraGameObject->addComponent<Camera>();
		cameraGameObject->addComponent<CameraInputHandler>();

		OptionalRef<LightSource> cameraFlashlightRef = cameraGameObject->addComponent<LightSource>();
		if (cameraFlashlightRef.HasRef()) {
			cameraFlashlightRef->initLightSource(LightType::Directional);
		}
		if (cameraRef.HasRef()) {
			cameraRef->initCamera(45.0F, SCR_WIDTH, SCR_HEIGHT);
			Camera::setMainCamera(cameraRef);
		}

		SpString const shadersFolderPath{ ResourcesPathProvider::getShaderFilesDirectoryPath() };
		SpString const vertexShaderPath{ shadersFolderPath + SpString{ "/vertex_lighting_shader.glsl" } };
		SpString const fragmentShaderPath{ shadersFolderPath + SpString{ "/fragment_lighting_shader.glsl" } };
		SpString const resourcesFolderPath{ ResourcesPathProvider::getResourcesDirectoryPath() };
		SpString const diffuseMapPath = resourcesFolderPath + SpString{ "/Art/container.png" };
		SpString const specularMapPath = resourcesFolderPath + SpString{ "/Art/specular_map_container.png" };
		SpString const texturePathArray[2]{
			resourcesFolderPath + SpString{ "/Art/stone-wall.png" },
			resourcesFolderPath + SpString{ "/Art/awesomeface.png" }
		};

		constexpr SpInt numberOfObjects = (sizeof(cubePositions) / sizeof(cubePositions[0]));
		GameObject * lightSourceGameObject = createLight(shadersFolderPath, texturePathArray, numberOfObjects - 1);

		SpInt const numberOfBoxes = numberOfObjects - 1;
		OptionalRef<Transform> lightSourceTransformRef = lightSourceGameObject->getComponent<Transform>();
		createBoxObjects(texturePathArray[0], specularMapPath, diffuseMapPath, vertexShaderPath, fragmentShaderPath, numberOfBoxes, cameraTransformRef, lightSourceTransformRef);
	}
}
