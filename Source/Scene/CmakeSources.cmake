set(SpectralEngine_Game_NoFilter_HEADER
    "include/Scene/Initializers.hpp"
    "include/Scene/Vertices.hpp")

set(SpectralEngine_Game_Components_SRC
    "src/Components/GameObjectComponent.cpp"
    "src/Components/Camera.cpp"
    "src/Components/Material.cpp"
    "src/Components/Renderer.cpp" 
    "src/Components/Transform.cpp"
    "src/Components/Rotator.cpp"
    "src/Components/PositionOscilator.cpp"
    "src/Components/CameraInputHandler.cpp"
    "src/Components/FPSCounter.cpp"
    "src/Components/CameraTransform.cpp"
    "src/Components/LightSource.cpp")

set(SpectralEngine_Game_Components_HEADER
    "include/Scene/Components/GameObjectComponent.hpp"
    "include/Scene/Components/Camera.hpp"
    "include/Scene/Components/Material.hpp"
    "include/Scene/Components/Renderer.hpp"
    "include/Scene/Components/Transform.hpp"
    "include/Scene/Components/Rotator.hpp"
    "include/Scene/Components/PositionOscilator.hpp"
    "include/Scene/Components/CameraInputHandler.hpp"
    "include/Scene/Components/FPSCounter.hpp"
    "include/Scene/Components/CameraTransform.hpp"
    "include/Scene/Components/LightSource.hpp")
    
set(SpectralEngine_Game_Scene_SRC
    "src/Scene/Scene.cpp")

set(SpectralEngine_Game_Scene_HEADER
    "include/Scene/Scene/Scene.hpp")

set(SpectralEngine_Game_Components_Interface_HEADER
    "include/Scene/Components/Interface/IRenderer.hpp"
    "include/Scene/Components/Interface/ITransformChangeObserver.hpp")

set(SpectralEngine_Game_GameObject_SRC
    "src/GameObject/GameObject.cpp")

set(SpectralEngine_Game_GameObject_HEADER
    "include/Scene/GameObject/GameObject.hpp")

source_group("include\\Scene" FILES ${SpectralEngine_Game_NoFilter_HEADER})
source_group("src\\Components" FILES ${SpectralEngine_Game_Components_SRC})
source_group("include\\Scene\\Components" FILES ${SpectralEngine_Game_Components_HEADER})
source_group("include\\Scene\\Scene" FILES ${SpectralEngine_Game_Scene_HEADER})
source_group("src\\Scene" FILES ${SpectralEngine_Game_Scene_SRC})
source_group("include\\Scene\\Components\\Interface" FILES ${SpectralEngine_Game_Components_Interface_HEADER})
source_group("src\\Components\\UI" FILES ${SpectralEngine_Game_Components_UI_SRC})
source_group("include\\Scene\\Components\\UI" FILES ${SpectralEngine_Game_Components_UI_HEADER})
source_group("include\\Scene\\GameObject" FILES ${SpectralEngine_Game_GameObject_HEADER})
source_group("src\\GameObject" FILES ${SpectralEngine_Game_GameObject_SRC})

set(SpectralEngine_Game_SRC
    ${SpectralEngine_Game_NoFilter_HEADER}
	${SpectralEngine_Game_Components_SRC}
	${SpectralEngine_Game_Components_HEADER}
	${SpectralEngine_Game_Scene_SRC}
	${SpectralEngine_Game_Scene_HEADER}
	${SpectralEngine_Game_Components_Interface_HEADER}
    ${SpectralEngine_Game_GameObject_HEADER}
    ${SpectralEngine_Game_GameObject_SRC})