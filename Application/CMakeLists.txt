add_executable(motorDemo motorDemo.cpp)

target_link_libraries(motorDemo PRIVATE HalLib PalLib DriversLib)

target_include_directories(motorDemo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
