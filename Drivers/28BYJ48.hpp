// File: 28BYJ48.hpp
//
// Author: Vasilaki Tocili
//
// Date: 22.12.23
//
// Version: 1.0
//
// Description: Header file for the 28BYJ48 stepper motor driver. This driver is used to control the stepper motors of the robot arm.
//

#pragma once

#include "IStepperMotor.hpp"

namespace Robot4e::Drivers
{
    class _28BYJ48: public Hal::IStepperMotor
    {
    public:
        _28BYJ48(std::uint8_t Pin1, std::uint8_t Pin2, std::uint8_t Pin3, std::uint8_t Pin4, std::int16_t StepsPerRevolution);
        ~_28BYJ48() override;

        void Initialize() override;

        void RotateClockwise(std::int16_t Steps) override;
        void RotateCounterClockwise(std::int16_t Steps) override;

        void SetAngle(std::int16_t Angle) override;

    private:
        std::uint8_t m_Pin1;
        std::uint8_t m_Pin2;
        std::uint8_t m_Pin3;
        std::uint8_t m_Pin4;

        std::int16_t m_StepsPerRevolution;
        std::int16_t m_StepDelay;

        static void StepMotor(std::int16_t Step);
    };
}
