add_library(HalLib IMotor.hpp IServoMotor.hpp IStepperMotor.hpp)

target_include_directories(HalLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(HalLib PROPERTIES LINKER_LANGUAGE CXX)
