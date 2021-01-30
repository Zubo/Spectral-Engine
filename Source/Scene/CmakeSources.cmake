set(SpectralEngine_Game_NoFilter_HEADER
    "include/Scene/Initializers.h"
    "include/Scene/Vertices.h")

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
    "include/Scene/Components/GameObjectComponent.h"
    "include/Scene/Components/Camera.h"
    "include/Scene/Components/Material.h"
    "include/Scene/Components/Renderer.h"
    "include/Scene/Components/Transform.h"
    "include/Scene/Components/Rotator.h"
    "include/Scene/Components/PositionOscilator.h"
    "include/Scene/Components/CameraInputHandler.h"
    "include/Scene/Components/FPSCounter.h"
    "include/Scene/Components/CameraTransform.h"
    "include/Scene/Components/LightSource.h")
    
set(SpectralEngine_Game_Scene_SRC
    "src/Scene/Scene.cpp")

set(SpectralEngine_Game_Scene_HEADER
    "include/Scene/Scene/Scene.h")

set(SpectralEngine_Game_Components_Interface_HEADER
    "include/Scene/Components/Interface/IRenderer.h"
    "include/Scene/Components/Interface/ITransformChangeObserver.h")

set(SpectralEngine_Game_GameObject_SRC
    "src/GameObject/GameObject.cpp")

set(SpectralEngine_Game_GameObject_HEADER
    "include/Scene/GameObject/GameObject.h")

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