# Testing CMake
add_library(sparqTesting STATIC
    placeholder.cpp
)

target_include_directories(sparqTesting
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/Testing>
)

target_link_libraries(sparqTesting
    PRIVATE
        sparqPal
)