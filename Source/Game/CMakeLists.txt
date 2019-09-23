cmake_minimum_required(VERSION 3.8)

include(CmakeSources.cmake)

add_library(Game STATIC ${SpectralEngine_Game_SRC})

target_link_libraries(Game Render)
target_link_libraries(Game Glad_external)
target_link_libraries(Game KHR)
