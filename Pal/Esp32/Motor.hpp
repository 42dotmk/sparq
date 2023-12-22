// File: Motor.hpp
//
// Author: Vasilaki Tocili
//
// Date: 20.12.23
//
// Version: 1.0
//
// Description: Motor class for Esp32 platform implementation.
//

#pragma once
#include "../../Hal/IMotor.hpp"

namespace Robot4e::Pal::Esp32
{
    class Motor: public Hal::IMotor
    {
    public:
        Motor();
        ~Motor() override = default;

        void SetAngle(std::int16_t Angle) override;
    };
}
