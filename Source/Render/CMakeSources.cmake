set(SpectralEngine_Render_NoFilter_SRC
    "Mesh.cpp"
    "MeshContainer.cpp"
    "RenderDataUpdate.cpp"
    "RenderData.cpp"
    "RenderDataContainer.cpp"
    "Render.cpp"
    "Texture.cpp"
    "TextureManager.cpp"
    "CameraData.cpp"
    "LightData.cpp"
    "LightDataContainer.cpp"
    "TextRenderer.cpp")
    
set(SpectralEngine_Render_NoFilter_HEADER
    "Mesh.h"
    "MeshContainer.h"
    "RenderDataUpdate.h"
    "RenderData.h"
    "RenderDataContainer.h"
    "Render.h"
    "Texture.h"
    "TextureManager.h"
    "CameraData.h"
    "LightData.h"
    "LightDataContainer.h"
    "TextRenderer.h")

set(SpectralEngine_Render_Shader_SRC
    "Shader/ShaderCompilationException.cpp"
    "Shader/ShaderProgramLinkingException.cpp"
    "Shader/Shader.cpp"
    "Shader/ShaderProgram.cpp")

set(SpectralEngine_Render_Shader_HEADER
    "Shader/ShaderCompilationException.h"
    "Shader/ShaderProgramLinkingException.h"
    "Shader/Shader.h"
    "Shader/ShaderProgram.h")

set(SpectralEngine_Render_Font_SRC
    "UI/Font/Character.cpp"
    "UI/Font/Font.cpp"
	"UI/Font/FreeTypeHelper.cpp")

set(SpectralEngine_Render_Font_HEADER
    "UI/Font/Character.h"
    "UI/Font/Font.h"
	"UI/Font/FreeTypeHelper.h")

set(SpectralEngine_Render_Enum_HEADER
    "Enum/LightType.h")

source_group("Source Files\\" FILES ${SpectralEngine_Render_NoFilter_SRC})
source_group("Header Files\\" FILES ${SpectralEngine_Render_NoFilter_HEADER})
source_group("Source Files\\Shader" FILES ${SpectralEngine_Render_Shader_SRC})
source_group("Header Files\\Shader" FILES ${SpectralEngine_Render_Shader_HEADER})
source_group("Source Files\\UI\\Font" FILES ${SpectralEngine_Render_Font_SRC})
source_group("Header Files\\UI\\Font" FILES ${SpectralEngine_Render_Font_HEADER})
source_group("Header Files\\Enum" FILES ${SpectralEngine_Render_Enum_HEADER})

set(SpectralEngine_Render_SRC
    ${SpectralEngine_Render_NoFilter_SRC}
    ${SpectralEngine_Render_NoFilter_HEADER}
    ${SpectralEngine_Render_Shader_SRC}
    ${SpectralEngine_Render_Shader_HEADER}
	${SpectralEngine_Render_Font_SRC}
	${SpectralEngine_Render_Font_HEADER}
    ${SpectralEngine_Render_Enum_HEADER})