// File: motorDemo.cpp
//
// Author: Vasilaki Tocili
//
// Date: 22.12.23
//
// Version: 1.0
//
// Description:  Demo application for the 28BYJ48 stepper motor driver. This driver is used to control the stepper motors of the robot arm.
//

#include "../Pal/Esp32/StepperMotor.hpp"

#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17
constexpr std::int8_t StepsPerRevolution = 2048;

Robot4e::Pal::Esp32::StepperMotor myStepper(IN1, IN2, IN3, IN4, StepsPerRevolution);

void setup()
{
    myStepper.Initialize();
}

void loop()
{
    myStepper.RotateClockwise(StepsPerRevolution);
    myStepper.RotateCounterClockwise(StepsPerRevolution);
}

[[noreturn]] int main(int argc, char * const argv[])
{
    setup();
    while(true)
    {
        loop();
    }
}

