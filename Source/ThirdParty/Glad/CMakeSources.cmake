set(ThirdParty_Glad_SRC
    "glad.c")

set(ThirdParty_Glad_HEADER
    "include/glad/glad.h")

set(ThirdParty_Glad_Include_Directories
    "include")

source_group("Source Files" ${ThirdParty_Glad_SRC})
source_group("Header Files" ${ThirdParty_Glad_HEADER})

set(ThirdParty_Glad_ALL
    ${ThirdParty_Glad_SRC}
    ${ThirdParty_Glad_HEADER})