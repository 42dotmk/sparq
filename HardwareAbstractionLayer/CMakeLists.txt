# Hardware Abstraction Layer CMake
add_library(sparqHal INTERFACE)

target_sources(sparqHal
    INTERFACE
        placeholder.hpp
)

target_include_directories(sparqHal
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(sparqHal
    INTERFACE
        sparqCommon
)
