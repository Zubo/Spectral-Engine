set(SpectralEngine_Render_include_Render_BasicShapes
	"include/Render/BasicShapes/Quad.hpp"
)

source_group("include/Render/BasicShapes" FILES ${SpectralEngine_Render_include_Render_BasicShapes})

set(SpectralEngine_Render_include_Render
	"include/Render/CameraData.hpp"
	"include/Render/LightData.hpp"
	"include/Render/LightDataContainer.hpp"
	"include/Render/Mesh.hpp"
	"include/Render/MeshContainer.hpp"
	"include/Render/RenderContext.hpp"
	"include/Render/RenderData.hpp"
	"include/Render/RenderDataContainer.hpp"
	"include/Render/RenderEngine.hpp"
	"include/Render/RenderFunctions.hpp"
	"include/Render/Texture.hpp"
	"include/Render/TextureManager.hpp"
)

source_group("include/Render" FILES ${SpectralEngine_Render_include_Render})

set(SpectralEngine_Render_include_Render_Enum
	"include/Render/Enum/LightType.hpp"
)

source_group("include/Render/Enum" FILES ${SpectralEngine_Render_include_Render_Enum})

set(SpectralEngine_Render_include_Render_GUI_DrawCallData
	"include/Render/GUI/DrawCallData/GUIDrawCallData.hpp"
	"include/Render/GUI/DrawCallData/TextDrawCallData.hpp"
	"include/Render/GUI/DrawCallData/TextureDrawCallData.hpp"
)

source_group("include/Render/GUI/DrawCallData" FILES ${SpectralEngine_Render_include_Render_GUI_DrawCallData})

set(SpectralEngine_Render_include_Render_GUI_Elements
	"include/Render/GUI/Elements/GUIButton.hpp"
)

source_group("include/Render/GUI/Elements" FILES ${SpectralEngine_Render_include_Render_GUI_Elements})

set(SpectralEngine_Render_include_Render_GUI_Elements_Settings
	"include/Render/GUI/Elements/Settings/GUIButtonSettings.hpp"
)

source_group("include/Render/GUI/Elements/Settings" FILES ${SpectralEngine_Render_include_Render_GUI_Elements_Settings})

set(SpectralEngine_Render_include_Render_GUI_Font
	"include/Render/GUI/Font/Character.hpp"
	"include/Render/GUI/Font/Font.hpp"
	"include/Render/GUI/Font/FreeTypeHelper.hpp"
)

source_group("include/Render/GUI/Font" FILES ${SpectralEngine_Render_include_Render_GUI_Font})

set(SpectralEngine_Render_include_Render_GUI
	"include/Render/GUI/GUIDrawCallDataContainer.hpp"
	"include/Render/GUI/ImGUIContext.hpp"
	"include/Render/GUI/ImGUIId.hpp"
	"include/Render/GUI/TextRenderer.hpp"
	"include/Render/GUI/TextureRenderer.hpp"
)

source_group("include/Render/GUI" FILES ${SpectralEngine_Render_include_Render_GUI})

set(SpectralEngine_Render_include_Render_GUI_Settings
	"include/Render/GUI/Settings/TextAlignment.hpp"
	"include/Render/GUI/Settings/TextRenderSettings.hpp"
)

source_group("include/Render/GUI/Settings" FILES ${SpectralEngine_Render_include_Render_GUI_Settings})

set(SpectralEngine_Render_include_Render_Shader
	"include/Render/Shader/Shader.hpp"
	"include/Render/Shader/ShaderCompilationException.hpp"
	"include/Render/Shader/ShaderProgram.hpp"
	"include/Render/Shader/ShaderProgramLinkingException.hpp"
)

source_group("include/Render/Shader" FILES ${SpectralEngine_Render_include_Render_Shader})

set(SpectralEngine_Render_src
	"src/CameraData.cpp"
	"src/LightData.cpp"
	"src/LightDataContainer.cpp"
	"src/Mesh.cpp"
	"src/MeshContainer.cpp"
	"src/RenderContext.cpp"
	"src/RenderData.cpp"
	"src/RenderDataContainer.cpp"
	"src/RenderEngine.cpp"
	"src/Texture.cpp"
	"src/TextureManager.cpp"
)

source_group("src" FILES ${SpectralEngine_Render_src})

set(SpectralEngine_Render_src_GUI_DrawCallData
	"src/GUI/DrawCallData/TextDrawCallData.cpp"
	"src/GUI/DrawCallData/TextureDrawCallData.cpp"
)

source_group("src/GUI/DrawCallData" FILES ${SpectralEngine_Render_src_GUI_DrawCallData})

set(SpectralEngine_Render_src_GUI_Elements
	"src/GUI/Elements/GUIButton.cpp"
)

source_group("src/GUI/Elements" FILES ${SpectralEngine_Render_src_GUI_Elements})

set(SpectralEngine_Render_src_GUI_Elements_Settings
	"src/GUI/Elements/Settings/GUIButtonSettings.cpp"
)

source_group("src/GUI/Elements/Settings" FILES ${SpectralEngine_Render_src_GUI_Elements_Settings})

set(SpectralEngine_Render_src_GUI_Font
	"src/GUI/Font/Font.cpp"
	"src/GUI/Font/FreeTypeHelper.cpp"
)

source_group("src/GUI/Font" FILES ${SpectralEngine_Render_src_GUI_Font})

set(SpectralEngine_Render_src_GUI
	"src/GUI/GUIDrawCallDataContainer.cpp"
	"src/GUI/ImGUIId.cpp"
	"src/GUI/TextRenderer.cpp"
	"src/GUI/TextureRenderer.cpp"
)

source_group("src/GUI" FILES ${SpectralEngine_Render_src_GUI})

set(SpectralEngine_Render_src_Shader
	"src/Shader/Shader.cpp"
	"src/Shader/ShaderCompilationException.cpp"
	"src/Shader/ShaderProgram.cpp"
	"src/Shader/ShaderProgramLinkingException.cpp"
)

source_group("src/Shader" FILES ${SpectralEngine_Render_src_Shader})

set(Render_ALL_SRC
	${SpectralEngine_Render_include_Render_BasicShapes}
	${SpectralEngine_Render_include_Render}
	${SpectralEngine_Render_include_Render_Enum}
	${SpectralEngine_Render_include_Render_GUI_DrawCallData}
	${SpectralEngine_Render_include_Render_GUI_Elements}
	${SpectralEngine_Render_include_Render_GUI_Elements_Settings}
	${SpectralEngine_Render_include_Render_GUI_Font}
	${SpectralEngine_Render_include_Render_GUI}
	${SpectralEngine_Render_include_Render_GUI_Settings}
	${SpectralEngine_Render_include_Render_Shader}
	${SpectralEngine_Render_src}
	${SpectralEngine_Render_src_GUI_DrawCallData}
	${SpectralEngine_Render_src_GUI_Elements}
	${SpectralEngine_Render_src_GUI_Elements_Settings}
	${SpectralEngine_Render_src_GUI_Font}
	${SpectralEngine_Render_src_GUI}
	${SpectralEngine_Render_src_Shader}
)
