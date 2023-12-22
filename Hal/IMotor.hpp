// File: IMotor.hpp
//
// Author: Vasilaki Tocili
//
// Date: 20.12.23
//
// Version: 1.0
//
// Description: Interface for motor control of the robot arm and the robot base motors.
//

#pragma once

#include <cstdint>

namespace Robot4e::Hal
{
    class IMotor
    {
    public:
        virtual ~IMotor() = default;

        virtual void Initialize() = 0;

        virtual void RotateClockwise(std::int16_t Steps) = 0;
        virtual void RotateCounterClockwise(std::int16_t Steps) = 0;

        virtual void SetAngle(std::int16_t Angle) = 0;
    };
}