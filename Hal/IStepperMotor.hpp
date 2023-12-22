// File: IStepperMotor.hpp
//
// Author: Vasilaki Tocili
//
// Date: 20.12.23
//
// Version: 1.0
//
// Description: Interface for stepper motor control of the robot arm and the robot base motors.
//

#pragma once
#include "IMotor.hpp"


namespace Robot4e::Hal
{
    class IStepperMotor: public Hal::IMotor
    {
    public:
        ~IStepperMotor() override = default;
    };
}
