# Operating Systems CMake
add_library(sparqOS STATIC
    placeholder.cpp
)

target_include_directories(sparqOS
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/OperatingSystems>
)

target_link_libraries(sparqOS
    PUBLIC
        sparqOsal
)
