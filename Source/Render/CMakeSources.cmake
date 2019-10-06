set(SpectralEngine_Render_NoFilter_SRC
    "RenderData.cpp"
    "RenderDataContainer.cpp"
	"Texture.cpp")
    
set(SpectralEngine_Render_NoFilter_HEADER
    "RenderData.h"
    "RenderDataContainer.h"
	"Texture.h")

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

set(SpectralEngine_Vertex_Shaders_SRC
    "ShaderFiles/vertex_shader.glsl"
    "ShaderFiles/vertex_lighting_shader.glsl"
    "ShaderFiles/vertex_text_shader.glsl")

set(SpectralEngine_Fragment_Shaders_SRC
    "ShaderFiles/fragment_shader.glsl"
    "ShaderFiles/fragment_lighting_shader.glsl"
    "ShaderFiles/fragment_lamp_shader.glsl"
    "ShaderFiles/fragment_text_shader.glsl")

source_group("Source Files\\" FILES ${SpectralEngine_Render_NoFilter_SRC})
source_group("Header Files\\" FILES ${SpectralEngine_Render_NoFilter_HEADER})
source_group("Source Files\\Shader" FILES ${SpectralEngine_Render_Shader_SRC})
source_group("Header Files\\Shader" FILES ${SpectralEngine_Render_Shader_HEADER})
source_group("Source Files\\UI\\Font" FILES ${SpectralEngine_Render_Font_SRC})
source_group("Header Files\\UI\\Font" FILES ${SpectralEngine_Render_Font_HEADER})
source_group("Shader Files\\Vertex" FILES ${SpectralEngine_Vertex_Shaders_SRC})
source_group("Shader Files\\Fragment" FILES ${SpectralEngine_Fragment_Shaders_SRC})

set(SpectralEngine_Render_SRC
    ${SpectralEngine_Render_NoFilter_SRC}
    ${SpectralEngine_Render_NoFilter_HEADER}
    ${SpectralEngine_Render_Shader_SRC}
    ${SpectralEngine_Render_Shader_HEADER}
	${SpectralEngine_Render_Font_SRC}
	${SpectralEngine_Render_Font_HEADER}
    ${SpectralEngine_Vertex_Shaders_SRC}
    ${SpectralEngine_Fragment_Shaders_SRC})