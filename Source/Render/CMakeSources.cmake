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
    "src/LightDataContainer.cpp")
    
set(SpectralEngine_Render_NoFilter_HEADER
    "include/Render/RenderEngine.hpp"
    "include/Render/RenderContext.hpp"
    "include/Render/RenderFunctions.hpp"
    "include/Render/Mesh.hpp"
    "include/Render/MeshContainer.hpp"
    "include/Render/RenderData.hpp"
    "include/Render/RenderDataContainer.hpp"
    "include/Render/Texture.hpp"
    "include/Render/TextureManager.hpp"
    "include/Render/CameraData.hpp"
    "include/Render/LightData.hpp"
    "include/Render/LightDataContainer.hpp")

set(SpectralEngine_Render_Shader_SRC
    "src/Shader/ShaderCompilationException.cpp"
    "src/Shader/ShaderProgramLinkingException.cpp"
    "src/Shader/Shader.cpp"
    "src/Shader/ShaderProgram.cpp")

set(SpectralEngine_Render_Shader_HEADER
    "include/Render/Shader/ShaderCompilationException.hpp"
    "include/Render/Shader/ShaderProgramLinkingException.hpp"
    "include/Render/Shader/Shader.hpp"
    "include/Render/Shader/ShaderProgram.hpp")

set(SpectralEngine_Render_GUI_SRC
    "src/GUI/GUIDrawCallDataContainer.cpp"
    "src/GUI/TextRenderer.cpp")

set(SpectralEngine_Render_GUI_HEADER
    "include/Render/GUI/GUIDrawCallDataContainer.hpp"
    "include/Render/GUI/TextRenderer.hpp")

set(SpectralEngine_Render_Font_SRC
    "src/GUI/Font/Character.cpp"
    "src/GUI/Font/Font.cpp"
	"src/GUI/Font/FreeTypeHelper.cpp")

set(SpectralEngine_Render_Font_HEADER
    "include/Render/GUI/Font/Character.hpp"
    "include/Render/GUI/Font/Font.hpp"
    "include/Render/GUI/Font/FreeTypeHelper.hpp")
    
set(SpectralEngine_Render_DrawCallData_SRC
    "src/GUI/DrawCallData/TextDrawCallData.cpp")

set(SpectralEngine_Render_DrawCallData_HEADER
    "include/Render/GUI/DrawCallData/GUIDrawCallData.hpp"
    "include/Render/GUI/DrawCallData/TextDrawCallData.hpp")

set(SpectralEngine_Render_Enum_HEADER
    "include/Render/Enum/LightType.hpp")

source_group("src" FILES ${SpectralEngine_Render_NoFilter_SRC})
source_group("include\\Render" FILES ${SpectralEngine_Render_NoFilter_HEADER})
source_group("src\\Shader" FILES ${SpectralEngine_Render_Shader_SRC})
source_group("include\\Render\\Shader" FILES ${SpectralEngine_Render_Shader_HEADER})
source_group("src\\GUI" FILES ${SpectralEngine_Render_GUI_SRC})
source_group("include\\Render\\GUI" FILES ${SpectralEngine_Render_GUI_HEADER})
source_group("src\\GUI\\Font" FILES ${SpectralEngine_Render_Font_SRC})
source_group("include\\Render\\UI\\Font" FILES ${SpectralEngine_Render_Font_HEADER})
source_group("src\\GUI\\DrawCallData" FILES ${SpectralEngine_Render_DrawCallData_SRC})
source_group("include\\Render\\UI\\DrawCallData" FILES ${SpectralEngine_Render_DrawCallData_HEADER})
source_group("include\\Render\\Enum" FILES ${SpectralEngine_Render_Enum_HEADER})

set(SpectralEngine_Render_SRC
    ${SpectralEngine_Render_NoFilter_SRC}
    ${SpectralEngine_Render_NoFilter_HEADER}
    ${SpectralEngine_Render_Shader_SRC}
    ${SpectralEngine_Render_Shader_HEADER}
    ${SpectralEngine_Render_GUI_SRC}
    ${SpectralEngine_Render_GUI_HEADER}
	${SpectralEngine_Render_Font_SRC}
    ${SpectralEngine_Render_Font_HEADER}
    ${SpectralEngine_Render_DrawCallData_SRC}
    ${SpectralEngine_Render_DrawCallData_HEADER}
    ${SpectralEngine_Render_Enum_HEADER})
