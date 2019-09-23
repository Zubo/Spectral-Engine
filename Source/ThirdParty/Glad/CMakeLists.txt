cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(Glad_external STATIC ${ThirdParty_Glad_ALL})

set_target_properties(Glad_external PROPERTIES FOLDER ExternalProjectTargets/Glad_external)

target_include_directories(Glad_external PUBLIC ${ThirdParty_Glad_Include_Directories})

target_link_libraries(Glad_external KHR)
