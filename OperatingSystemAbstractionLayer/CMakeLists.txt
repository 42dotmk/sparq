# Operating Systems Abstraction Layer CMake
add_library(sparqOsal STATIC
    placeholder.cpp
)

target_include_directories(sparqOsal
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/OperatingSystemAbstractionLayer>
)

target_link_libraries(sparqOsal
    PUBLIC
        sparqHal
)
