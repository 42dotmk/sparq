add_library(PalLib Motor.cpp ServoMotor.cpp StepperMotor.cpp Motor.hpp ServoMotor.hpp StepperMotor.hpp)

target_include_directories(PalLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
