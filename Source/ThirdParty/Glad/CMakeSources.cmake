set(SpectralEngine_Glad_
	"glad.c"
)

source_group("" FILES ${SpectralEngine_Glad_})

set(SpectralEngine_Glad_include_glad
	"include/glad/glad.h"
)

source_group("include/glad" FILES ${SpectralEngine_Glad_include_glad})

set(Glad_ALL_SRC
	${SpectralEngine_Glad_}
	${SpectralEngine_Glad_include_glad}
)
