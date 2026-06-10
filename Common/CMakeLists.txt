# Common CMake
add_library(sparqCommon INTERFACE)

target_include_directories(sparqCommon
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/Common>
)
