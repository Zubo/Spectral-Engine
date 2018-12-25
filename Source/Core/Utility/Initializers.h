#pragma once

#include <memory>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Core/Shader/Shader.h"
#include "Core/Utility/Vertices.h"
#include "Core/Components/Material.h"
#include "Core/Components/Transform.h"
#include "Core/Components/Renderer.h"


constexpr unsigned int SCR_WIDTH = 800;
constexpr unsigned int SCR_HEIGHT = 600;

GLFWwindow * initGLFWwindow();

void initScene(std::string const & executablePath) {
	GameObject * const cameraGameObject = new GameObject();
	cameraGameObject->addComponent<Transform>();
	auto cameraWeak = cameraGameObject->addComponent<Camera>();

	if (auto cameraShared = cameraWeak.lock()) {
		cameraShared->initCamera(glm::radians(45.0F), SCR_WIDTH, SCR_HEIGHT);
		Camera::setMainCamera(cameraShared);
	}

	std::string const rootPath{ executablePath.substr(0, executablePath.find_last_of("\\")) };
	std::string const resourcesFolderPath{ rootPath + std::string{ "/../../../Resources/Resources" } };
	std::string const vertexShaderPath{ resourcesFolderPath + std::string{ "/Shaders/vertex_shader.txt" } };
	std::string const fragmentShaderPath{ resourcesFolderPath + std::string{ "/Shaders/fragment_shader.txt" } };
	std::string const texturePathArray[2]{
		resourcesFolderPath + std::string{ "/Art/wall.png" },
		resourcesFolderPath + std::string{ "/Art/awesomeface.png" }
	};

	constexpr int numberOfObjects = (sizeof(cubePositions) / sizeof(cubePositions[0]));
	GameObject * gameObjects = new GameObject[numberOfObjects];

	for (int i = 0; i < numberOfObjects; ++i) {
		std::weak_ptr<Material> material = gameObjects[i].addComponent<Material>();
		if (auto materialShared = material.lock()) {
			constexpr int numberOfTextures = sizeof(texturePathArray) / sizeof(std::string);
			materialShared->initMaterial(vertexShaderPath, fragmentShaderPath, texturePathArray, numberOfTextures);
		}

		std::weak_ptr<Renderer> renderer = gameObjects[i].addComponent<Renderer>();
		if (auto rendererShared = renderer.lock()) {
			rendererShared->initRenderer(vertices, sizeof(vertices), indices, sizeof(indices));
		}

		std::weak_ptr<Transform> transform = gameObjects[i].addComponent<Transform>();
		if (auto transformShared = transform.lock()) {
			transformShared->setPosition(cubePositions[i]);
		}
	}
}

GLFWwindow * setupWindow() {
	auto window = initGLFWwindow();

	if (window == NULL) {
		std::cout << "Failed to create GLFW window." << std::endl;
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD." << std::endl;
		return nullptr;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window,
		[](GLFWwindow * window, int width, int height) {
		glViewport(0, 0, width, height);
	});

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	return window;
}

GLFWwindow * initGLFWwindow() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window = glfwCreateWindow(800, 600, "Opengl tutorial", NULL, NULL);

	return window;
}
