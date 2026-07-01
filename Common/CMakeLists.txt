# Common CMake
add_library(sparqCommon INTERFACE)

target_sources(sparqCommon
    INTERFACE FILE_SET HEADERS
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
            ErrorCodes.hpp
            Types.hpp
)

target_include_directories(sparqCommon
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/Common>
)
