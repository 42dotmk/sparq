# sparq root CMake
cmake_minimum_required(VERSION 3.23)

project(sparq LANGUAGES CXX)

option(SPARQ_BUILD_HOST "Build host targets" ON)

# ============================
# ESP-IDF ENTRY POINT
# ============================
if(ESP_PLATFORM)
    # ESP-IDF will take over from here
    return()
endif()

# ============================
# HOST CONFIGURATION
# ============================
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Common)
add_subdirectory(Drivers)
add_subdirectory(HardwareAbstractionLayer)
add_subdirectory(OperatingSystemAbstractionLayer)
add_subdirectory(OperatingSystems)
add_subdirectory(PlatformAbstractionLayer)
add_subdirectory(Testing)
