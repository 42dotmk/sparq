cmake_minimum_required(VERSION 3.23)

project(robot4e VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Application)
add_subdirectory(Drivers)
add_subdirectory(Hal)
add_subdirectory(Pal/Esp32)

target_link_libraries(motorDemo PRIVATE HalLib PalLib DriversLib)