cmake_minimum_required(VERSION 3.8)

include(CmakeSources.cmake)

add_library(Game STATIC ${SpectralEngine_Game_SRC})

target_link_libraries(Game PRIVATE Render)
target_link_libraries(Game PRIVATE Core)
target_link_libraries(Game PRIVATE glad)
target_link_libraries(Game PRIVATE khr)

if(MSVC)
	target_compile_options(Game PRIVATE /W4 /WX)
else()
	target_compile_options(Game PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
