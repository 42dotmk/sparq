// File: IServoMotor.hpp
//
// Author: Vasilaki Tocili
//
// Date: 20.12.23
//
// Version: 1.0
//
// Description: Interface for servo motor control of the robot arm and the robot base motors.
//

#pragma once
#include "IMotor.hpp"

namespace Robot4e::Hal
{
    class IServoMotor: public IMotor
    {
    public:
        ~IServoMotor() override = default;
    };
}
