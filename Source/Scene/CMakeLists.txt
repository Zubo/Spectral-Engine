cmake_minimum_required(VERSION 3.8)

include(CmakeSources.cmake)

add_library(Scene STATIC ${SpectralEngine_Game_SRC})

target_link_libraries(Scene PRIVATE Render)
target_link_libraries(Scene PRIVATE Core)
target_link_libraries(Scene PRIVATE glad)
target_link_libraries(Scene PRIVATE khr)

if(MSVC)
	target_compile_options(Scene PRIVATE /W4 /WX)
else()
	target_compile_options(Scene PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
