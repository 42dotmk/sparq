// File: StepperMotor.hpp
//
// Author: Vasilaki Tocili
//
// Date: 20.12.23
//
// Version: 1.0
//
// Description: StepperMotor class for Esp32 platform implementation.
//

#pragma once

#include "28BYJ48.hpp"
#include "IStepperMotor.hpp"

namespace Robot4e::Pal::Esp32
{
    class StepperMotor final : public Hal::IStepperMotor
    {
    public:
        StepperMotor(std::uint8_t Pin1, std::uint8_t Pin2, std::uint8_t Pin3, std::uint8_t Pin4, std::int16_t StepsPerRevolution);
        ~StepperMotor() override = default;

        void Initialize() final;

        void RotateClockwise(std::int16_t Steps) final;
        void RotateCounterClockwise(std::int16_t Steps) final;

        void SetAngle(std::int16_t Angle) final;

    private:
        Robot4e::Drivers::_28BYJ48 m_28BYJ48;
    };
}
