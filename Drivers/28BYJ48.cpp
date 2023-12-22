// File: 28BYJ48.cpp
//
// Author: Vasilaki Tocili
//
// Date: 22.12.23
//
// Version: 1.0
//
// Description: Source file for the 28BYJ48 stepper motor driver. This driver is used to control the stepper motors of the robot arm.
//

#include "28BYJ48.hpp"

namespace Robot4e::Drivers
{
    _28BYJ48::_28BYJ48(std::uint8_t Pin1, std::uint8_t Pin2, std::uint8_t Pin3, std::uint8_t Pin4, std::int16_t StepsPerRevolution)
    {
        m_Pin1 = Pin1;
        m_Pin2 = Pin2;
        m_Pin3 = Pin3;
        m_Pin4 = Pin4;

        m_StepsPerRevolution = StepsPerRevolution;
        m_StepDelay = 1000 / StepsPerRevolution;
    }

    _28BYJ48::~_28BYJ48()
    = default;

    void _28BYJ48::Initialize()
    {

    }

    void _28BYJ48::RotateClockwise(std::int16_t Steps)
    {
        for (std::int16_t i = 0; i < Steps; i++)
        {
            StepMotor( i % 4 );
        }
    }

    void _28BYJ48::RotateCounterClockwise(std::int16_t Steps)
    {
        for (std::int16_t i = Steps; i > 0; i--)
        {
            StepMotor( i % 4 );
        }
    }

    void _28BYJ48::SetAngle(std::int16_t Angle)
    {
        std::int16_t const Steps = m_StepsPerRevolution * Angle / (std::int16_t)360;

        if (Steps > 0)
        {
            RotateClockwise(Steps);
        }
        else
        {
            RotateCounterClockwise(-Steps);
        }
    }

    void _28BYJ48::StepMotor(const std::int16_t Step)
    {

    }

}