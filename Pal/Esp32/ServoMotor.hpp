// File: ServoMotor.hpp
//
// Author: Vasilaki Tocili
//
// Date: 20.12.23
//
// Version: 1.0
//
// Description: ServoMotor class for Esp32 platform implementation.
//

#pragma once
#include "IServoMotor.hpp"


namespace Robot4e::Pal::Esp32
{
    class ServoMotor: public Hal::IServoMotor
    {
    public:
        ServoMotor();
        ~ServoMotor() override = default;

        void SetAngle(std::int16_t Angle) final;
    };
}
