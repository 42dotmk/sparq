# sparq root CMake
cmake_minimum_required(VERSION 3.23...4.0)

project(sparq VERSION 0.0.2 LANGUAGES CXX)

option(SPARQ_BUILD_HOST "Build host targets" ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# ============================
# ESP-IDF ENTRY POINT
# ============================
if(ESP_PLATFORM)
    # ESP-IDF is driving the build, let it build its component natively
    add_subdirectory(PlatformAbstractionLayer/Esp32)
    return()
endif()

# ============================
# HOST CONFIGURATION
# ============================
if(NOT SPARQ_BUILD_HOST)
    return()
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Common)
add_subdirectory(HardwareAbstractionLayer)
add_subdirectory(PlatformAbstractionLayer)

add_library(sparq INTERFACE)
target_link_libraries(sparq
    INTERFACE
        sparqPal
)

install(TARGETS
    sparq
    sparqCommon
    sparqHal
    sparqPal
    EXPORT sparqTargets
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/HardwareAbstractionLayer
)

install(DIRECTORY Common/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Common FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
install(DIRECTORY PlatformAbstractionLayer/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/PlatformAbstractionLayer FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/sparq-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/sparq-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sparq
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/sparq-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/sparq-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/sparq-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sparq
)

install(EXPORT sparqTargets
    NAMESPACE sparq::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sparq
)
