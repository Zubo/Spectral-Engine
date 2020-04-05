set(SpectralEngine_Game_NoFilter_HEADER
    "Initializers.h"
    "Vertices.h")

set(SpectralEngine_Game_Components_SRC
    "Components/Camera.cpp"
    "Components/GameObjectComponent.cpp"
    "Components/Material.cpp"
    "Components/Renderer.cpp" 
    "Components/Transform.cpp"
    "Components/Rotator.cpp"
    "Components/PositionOscilator.cpp"
    "Components/CameraInputHandler.cpp"
    "Components/FPSCounter.cpp"
    "Components/CameraTransform.cpp"
    "Components/LightSource.cpp")

set(SpectralEngine_Game_Components_HEADER
    "Components/Camera.h"
    "Components/GameObjectComponent.h"
    "Components/Material.h"
    "Components/Renderer.h"
    "Components/Transform.h"
    "Components/Rotator.h"
    "Components/PositionOscilator.h"
    "Components/CameraInputHandler.h"
    "Components/FPSCounter.h"
    "Components/CameraTransform.h"
    "Components/LightSource.h")
    
set(SpectralEngine_Game_Components_UI_SRC
    "Components/UI/TextRenderer.cpp")

set(SpectralEngine_Game_Components_UI_HEADER
    "Components/UI/TextRenderer.h")

set(SpectralEngine_Game_Components_Interface_HEADER
    "Components/Interface/IRenderer.h"
    "Components/Interface/ITransformChangeObserver.h")

set(SpectralEngine_Game_GameObject_SRC
    "GameObject/GameObject.cpp")

set(SpectralEngine_Game_GameObject_HEADER
    "GameObject/GameObject.h")

source_group("Header Files" FILES ${SpectralEngine_Game_NoFilter_HEADER})
source_group("Source Files\\Components" FILES ${SpectralEngine_Game_Components_SRC})
source_group("Header Files\\Components" FILES ${SpectralEngine_Game_Components_HEADER})
source_group("Header Files\\Components\\Interface" FILES ${SpectralEngine_Game_Components_Interface_HEADER})
source_group("Source Files\\Components\\UI" FILES ${SpectralEngine_Game_Components_UI_SRC})
source_group("Header Files\\Components\\UI" FILES ${SpectralEngine_Game_Components_UI_HEADER})
source_group("Header Files\\GameObject" FILES ${SpectralEngine_Game_GameObject_HEADER})
source_group("Source Files\\GameObject" FILES ${SpectralEngine_Game_GameObject_SRC})

set(SpectralEngine_Game_SRC
    ${SpectralEngine_Game_NoFilter_HEADER}
	${SpectralEngine_Game_Components_SRC}
	${SpectralEngine_Game_Components_HEADER}
	${SpectralEngine_Game_Components_Interface_HEADER}
	${SpectralEngine_Game_Components_UI_SRC}
    ${SpectralEngine_Game_Components_UI_HEADER}
    ${SpectralEngine_Game_GameObject_HEADER}
    ${SpectralEngine_Game_GameObject_SRC})