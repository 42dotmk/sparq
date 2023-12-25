add_library(PalLib Motor.cpp ServoMotor.cpp StepperMotor.cpp)

target_include_directories(PalLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(PalLib PUBLIC HalLib)
target_link_libraries(PalLib PUBLIC DriversLib)