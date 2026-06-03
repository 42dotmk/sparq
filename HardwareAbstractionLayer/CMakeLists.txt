# Hardware Abstraction Layer CMake
add_library(sparqHal INTERFACE)

target_sources(sparqHal
    INTERFACE FILE_SET HEADERS
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
            placeholder.hpp
)

target_include_directories(sparqHal
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/HardwareAbstractionLayer>
)

target_link_libraries(sparqHal
    INTERFACE
        sparqCommon
)
