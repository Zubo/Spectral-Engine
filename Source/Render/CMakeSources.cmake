set(SpectralEngine_Render_NoFilter_SRC
    "src/RenderEngine.cpp"
    "src/RenderContext.cpp"
    "src/Mesh.cpp"
    "src/MeshContainer.cpp"
    "src/RenderData.cpp"
    "src/RenderDataContainer.cpp"
    "src/Texture.cpp"
    "src/TextureManager.cpp"
    "src/CameraData.cpp"
    "src/LightData.cpp"
    "src/LightDataContainer.cpp"
    "src/TextRenderer.cpp")
    
set(SpectralEngine_Render_NoFilter_HEADER
    "include/Render/RenderEngine.h"
    "include/Render/RenderContext.h"
    "include/Render/RenderFunctions.h"
    "include/Render/Mesh.h"
    "include/Render/MeshContainer.h"
    "include/Render/RenderData.h"
    "include/Render/RenderDataContainer.h"
    "include/Render/Texture.h"
    "include/Render/TextureManager.h"
    "include/Render/CameraData.h"
    "include/Render/LightData.h"
    "include/Render/LightDataContainer.h"
    "include/Render/TextRenderer.h")

set(SpectralEngine_Render_Shader_SRC
    "src/Shader/ShaderCompilationException.cpp"
    "src/Shader/ShaderProgramLinkingException.cpp"
    "src/Shader/Shader.cpp"
    "src/Shader/ShaderProgram.cpp")

set(SpectralEngine_Render_Shader_HEADER
    "include/Render/Shader/ShaderCompilationException.h"
    "include/Render/Shader/ShaderProgramLinkingException.h"
    "include/Render/Shader/Shader.h"
    "include/Render/Shader/ShaderProgram.h")

set(SpectralEngine_Render_Font_SRC
    "src/UI/Font/Character.cpp"
    "src/UI/Font/Font.cpp"
	"src/UI/Font/FreeTypeHelper.cpp")

set(SpectralEngine_Render_Font_HEADER
    "include/Render/UI/Font/Character.h"
    "include/Render/UI/Font/Font.h"
	"include/Render/UI/Font/FreeTypeHelper.h")

set(SpectralEngine_Render_Enum_HEADER
    "include/Render/Enum/LightType.h")

source_group("src\\" FILES ${SpectralEngine_Render_NoFilter_SRC})
source_group("include\\Render\\" FILES ${SpectralEngine_Render_NoFilter_HEADER})
source_group("src\\Shader" FILES ${SpectralEngine_Render_Shader_SRC})
source_group("include\\Render\\Shader" FILES ${SpectralEngine_Render_Shader_HEADER})
source_group("src\\UI\\Font" FILES ${SpectralEngine_Render_Font_SRC})
source_group("include\\Render\\UI\\Font" FILES ${SpectralEngine_Render_Font_HEADER})
source_group("include\\Render\\Enum" FILES ${SpectralEngine_Render_Enum_HEADER})

set(SpectralEngine_Render_SRC
    ${SpectralEngine_Render_NoFilter_SRC}
    ${SpectralEngine_Render_NoFilter_HEADER}
    ${SpectralEngine_Render_Shader_SRC}
    ${SpectralEngine_Render_Shader_HEADER}
	${SpectralEngine_Render_Font_SRC}
	${SpectralEngine_Render_Font_HEADER}
    ${SpectralEngine_Render_Enum_HEADER})