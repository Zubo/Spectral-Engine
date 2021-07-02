set(SpectralEngine_Scene_include_Scene_Components
	"include/Scene/Components/Camera.hpp"
	"include/Scene/Components/CameraInputHandler.hpp"
	"include/Scene/Components/CameraTransform.hpp"
	"include/Scene/Components/FPSCounter.hpp"
	"include/Scene/Components/GameObjectComponent.hpp"
	"include/Scene/Components/LightSource.hpp"
	"include/Scene/Components/Material.hpp"
	"include/Scene/Components/PositionOscilator.hpp"
	"include/Scene/Components/Renderer.hpp"
	"include/Scene/Components/Rotator.hpp"
	"include/Scene/Components/Transform.hpp"
)

source_group("include/Scene/Components" FILES ${SpectralEngine_Scene_include_Scene_Components})

set(SpectralEngine_Scene_include_Scene_Components_Interface
	"include/Scene/Components/Interface/IRenderer.hpp"
	"include/Scene/Components/Interface/ITransformChangeObserver.hpp"
)

source_group("include/Scene/Components/Interface" FILES ${SpectralEngine_Scene_include_Scene_Components_Interface})

set(SpectralEngine_Scene_include_Scene_GameObject
	"include/Scene/GameObject/GameObject.hpp"
)

source_group("include/Scene/GameObject" FILES ${SpectralEngine_Scene_include_Scene_GameObject})

set(SpectralEngine_Scene_include_Scene
	"include/Scene/Initializers.hpp"
	"include/Scene/Vertices.hpp"
)

source_group("include/Scene" FILES ${SpectralEngine_Scene_include_Scene})

set(SpectralEngine_Scene_include_Scene_Scene
	"include/Scene/Scene/Scene.hpp"
)

source_group("include/Scene/Scene" FILES ${SpectralEngine_Scene_include_Scene_Scene})

set(SpectralEngine_Scene_src_Components
	"src/Components/Camera.cpp"
	"src/Components/CameraInputHandler.cpp"
	"src/Components/CameraTransform.cpp"
	"src/Components/FPSCounter.cpp"
	"src/Components/GameObjectComponent.cpp"
	"src/Components/LightSource.cpp"
	"src/Components/Material.cpp"
	"src/Components/PositionOscilator.cpp"
	"src/Components/Renderer.cpp"
	"src/Components/Rotator.cpp"
	"src/Components/Transform.cpp"
)

source_group("src/Components" FILES ${SpectralEngine_Scene_src_Components})

set(SpectralEngine_Scene_src_GameObject
	"src/GameObject/GameObject.cpp"
)

source_group("src/GameObject" FILES ${SpectralEngine_Scene_src_GameObject})

set(SpectralEngine_Scene_src_Scene
	"src/Scene/Scene.cpp"
)

source_group("src/Scene" FILES ${SpectralEngine_Scene_src_Scene})

set(Scene_ALL_SRC
	${SpectralEngine_Scene_include_Scene_Components}
	${SpectralEngine_Scene_include_Scene_Components_Interface}
	${SpectralEngine_Scene_include_Scene_GameObject}
	${SpectralEngine_Scene_include_Scene}
	${SpectralEngine_Scene_include_Scene_Scene}
	${SpectralEngine_Scene_src_Components}
	${SpectralEngine_Scene_src_GameObject}
	${SpectralEngine_Scene_src_Scene}
)
