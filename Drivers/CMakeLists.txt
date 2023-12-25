add_library(DriversLib 28BYJ48.cpp)

target_include_directories(DriversLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(DriversLib PUBLIC HalLib)