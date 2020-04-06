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
#include "Game/Components/UI/TextRenderer.h"
#include "Game/Components/PositionOscilator.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Vertices.h"
#include "Render/MeshContainer.h"
#include "Render/Enum/LightType.h"
#include "Game/Components/Rotator.h"
#include "Render/UI/Font/Font.h"
#include "Core/Math/Radian.h"

namespace sp {
	constexpr unsigned int SCR_WIDTH = 800;
	constexpr unsigned int SCR_HEIGHT = 600;
	std::default_random_engine generator{ (unsigned int)time(0) };
	std::uniform_real_distribution<float> distribution{ 0.0F, 1.0F };

	void createText(SpString const & text, SpString const & fontPath) {
		GameObject * textGameObject = new GameObject;
		std::weak_ptr<Transform> transformWeak = textGameObject->addComponent<Transform>();

		if (auto transformShared = transformWeak.lock()) {
			transformShared->setScale(sp::Vector2::getVectorOne() * 0.6F);
		}

		std::weak_ptr<TextRenderer> const textRendererWeak = textGameObject->addComponent<TextRenderer>();
		
		if (std::shared_ptr<TextRenderer> const textRendererShared = textRendererWeak.lock()) {
			textRendererShared->setFont(fontPath);
		}

		textGameObject->addComponent<FPSCounter>();
	}

	void setRandomColors(std::weak_ptr<Material> materialWeak) {
		if (auto materialShared = materialWeak.lock()) {
			Vector3 ambient{ 0.2F };
			materialShared->setAmbient(ambient);
		
			Vector3 diffuse{ distribution(generator) };
			materialShared->setDiffuse(diffuse);

			Vector3 specular{ distribution(generator) };
			materialShared->setSpecular(specular);

			float shininess{ 1.0F + 31 * distribution(generator) };
			materialShared->setShinines(shininess);
		}
	}

	GameObject * createLight(SpString const & shadersFolderPath, SpString const texturePathArray[], int const lightSourceIndex) {
		GameObject * lightSourceGameObject = new GameObject;

		std::weak_ptr<Transform> lightSourceTransformWeak = lightSourceGameObject->addComponent<Transform>();
		if (auto transformShared = lightSourceTransformWeak.lock()) {
			transformShared->setPosition(cubePositions[lightSourceIndex]);
			transformShared->setScale(Vector3{ 0.1F });
		}

		std::weak_ptr<Renderer> rendererWeak = lightSourceGameObject->addComponent<Renderer>();
		if (auto rendererShared = rendererWeak.lock()) {
			unsigned int const meshId = MeshContainer::createMesh(verticesUV, (int)(sizeof(verticesUV) / sizeof(float)), indices, (int)sizeof(indices), true, false);
			rendererShared->initRenderer(meshId);
		}

		SpString const vertexLightingShaderPath{ shadersFolderPath + SpString{ "/vertex_shader.glsl" } };
		SpString const fragmentLightingShaderPath{ shadersFolderPath + SpString{ "/fragment_lamp_shader.glsl" } };
		std::weak_ptr<Material> material = lightSourceGameObject->addComponent<Material>();
		if (auto materialShared = material.lock()) {
			materialShared->initMaterial(vertexLightingShaderPath, fragmentLightingShaderPath);
			const int numberOfTextures = 2;
			materialShared->initMaterial(vertexLightingShaderPath, fragmentLightingShaderPath);
		}

		std::weak_ptr<LightSource> pointLightSourceWeak = lightSourceGameObject->addComponent<LightSource>();
		if (std::shared_ptr<LightSource> lightSourceShared = pointLightSourceWeak.lock()) {
			lightSourceShared->initLightSource(LightType::Point);
		}

		lightSourceGameObject->addComponent<PositionOscilator>();
		lightSourceGameObject->addComponent<Rotator>();
		std::weak_ptr<LightSource> directionalLightSourceWeak = lightSourceGameObject->addComponent<LightSource>();
		if (std::shared_ptr<LightSource> directionalLightSourceShared = directionalLightSourceWeak.lock()) {
			directionalLightSourceShared->initLightSource(LightType::Directional);
		}

		return lightSourceGameObject;
	}

	void createBoxObjects(
		SpString const & bigBoxTexture, SpString const & specularMapTexturePath, SpString const & diffuseMapTexturePath, SpString const & vertexShaderPath,
		SpString const & fragmentShaderPath, int numberOfBoxes, std::weak_ptr<Transform> cameraTransformWeak, std::weak_ptr<Transform> lightSourceTrnasformWeak) {

		GameObject * boxObjects = new GameObject[numberOfBoxes];

		for (int i = 0; i < numberOfBoxes; ++i) {

			std::weak_ptr<Renderer> renderer = boxObjects[i].addComponent<Renderer>();
			if (auto rendererShared = renderer.lock()) {
				unsigned int const meshId = MeshContainer::createMesh(verticesUVNormals,
					(int)(sizeof(verticesUVNormals) / sizeof(float)), indices, (int)(sizeof(indices) / sizeof(int)), true, true);
				rendererShared->initRenderer(meshId);
			}

			std::weak_ptr<Material> material = boxObjects[i].addComponent<Material>();

			if (auto materialShared = material.lock()) {
				materialShared->initMaterial(vertexShaderPath, fragmentShaderPath);
				if (i == 0) {
					materialShared->setDiffuseMap(bigBoxTexture);
					materialShared->setSpecularMap(bigBoxTexture);
				}
				materialShared->setDiffuseMap(diffuseMapTexturePath);
				materialShared->setSpecularMap(specularMapTexturePath);
			}

			setRandomColors(material);

			if (i % 2) {
				boxObjects[i].addComponent<Rotator>();
			}


			std::weak_ptr<Transform> transform = boxObjects[i].addComponent<Transform>();
			if (auto transformShared = transform.lock()) {
				transformShared->setPosition(cubePositions[i]);
				if (i == 0) {
					transformShared->setScale(Vector3{ 50.0F });
				}
			}
		}
	}

	void initScene(SpString const & executablePath) {
		GameObject * const cameraGameObject = new GameObject();
		auto cameraTransformWeak = cameraGameObject->addComponent<CameraTransform>();
		auto cameraWeak = cameraGameObject->addComponent<Camera>();
		cameraGameObject->addComponent<CameraInputHandler>();

		std::weak_ptr<LightSource> cameraFlashlightWeak = cameraGameObject->addComponent<LightSource>();
		if (std::shared_ptr<LightSource> cameraFlashlightShared = cameraFlashlightWeak.lock()) {
			cameraFlashlightShared->initLightSource(LightType::Directional);
		}
		if (auto cameraShared = cameraWeak.lock()) {
			cameraShared->initCamera(45.0F, SCR_WIDTH, SCR_HEIGHT);
			Camera::setMainCamera(cameraShared);
		}

		SpString const rootPath{ executablePath.substr(0, executablePath.find_last_of("\\")) };
		SpString const shadersFolderPath{ rootPath + SpString{"/../../../Source/Render/ShaderFiles"} };
		SpString const vertexShaderPath{ shadersFolderPath + SpString{ "/vertex_lighting_shader.glsl" } };
		SpString const fragmentShaderPath{ shadersFolderPath + SpString{ "/fragment_lighting_shader.glsl" } };
		SpString const resourcesFolderPath{ rootPath + SpString{ "/../../../Resources/Resources" } };
		SpString const diffuseMapPath = resourcesFolderPath + SpString{ "/Art/container.png" };
		SpString const specularMapPath = resourcesFolderPath + SpString{ "/Art/specular_map_container.png" };
		SpString const texturePathArray[2]{
			resourcesFolderPath + SpString{ "/Art/wall.png" },
			resourcesFolderPath + SpString{ "/Art/awesomeface.png" }
		};

		SpString const fontPath = resourcesFolderPath + SpString{ "/Fonts/JingJing.ttf" };
		//createText("This is sample text", fontPath);


		constexpr int numberOfObjects = (sizeof(cubePositions) / sizeof(cubePositions[0]));
		GameObject * lightSourceGameObject = createLight(shadersFolderPath, texturePathArray, numberOfObjects - 1);

		int const numberOfBoxes = numberOfObjects - 1;
		std::weak_ptr<Transform> lightSourceTransformWeak = lightSourceGameObject->getComponent<Transform>();
		createBoxObjects(texturePathArray[0], specularMapPath, diffuseMapPath, vertexShaderPath, fragmentShaderPath, numberOfBoxes, cameraTransformWeak, lightSourceTransformWeak);
	}
}
