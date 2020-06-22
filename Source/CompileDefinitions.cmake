if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    # 64 bit
    add_compile_definitions(COMPILE_64_BIT)
elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
    # 32 bit
    add_compile_definitions(COMPILE_32_BIT)
else()
    message(FATAL_ERROR "The engine should be compiled in either 64 or 32 bit.")
endif()
