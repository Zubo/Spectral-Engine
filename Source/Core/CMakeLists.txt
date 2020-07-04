cmake_minimum_required (VERSION 3.8)

include(CMakeSources.cmake)

add_library(Core STATIC ${SpectralEngine_Core_SRC})

if(MSVC)
	target_compile_options(Core PRIVATE /W4 /WX)
else()
	target_compile_options(Core PRIVATE -Wall -Wextra -pedantic -Werror)
endif()