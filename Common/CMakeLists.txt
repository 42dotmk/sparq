# Common CMake
add_library(sparqCommon INTERFACE)

target_include_directories(sparqCommon
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
