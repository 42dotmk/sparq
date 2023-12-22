// File: StepperMotor.cpp
//
// Author: Vasilaki Tocili
//
// Date: 20.12.23
//
// Version: 1.0
//
// Description: This is the implementation file for the StepperMotor class. It contains the function definitions.
//

#include "StepperMotor.hpp"

Robot4e::Pal::Esp32::StepperMotor::StepperMotor(std::uint8_t Pin1, std::uint8_t Pin2, std::uint8_t Pin3, std::uint8_t Pin4, std::int16_t StepsPerRevolution)
: m_28BYJ48(Pin1, Pin2, Pin3, Pin4, StepsPerRevolution)
{
}

void Robot4e::Pal::Esp32::StepperMotor::Initialize()
{
    m_28BYJ48.Initialize();
}

void Robot4e::Pal::Esp32::StepperMotor::RotateClockwise(std::int16_t Steps)
{
    m_28BYJ48.RotateClockwise(Steps);
}

void Robot4e::Pal::Esp32::StepperMotor::RotateCounterClockwise(std::int16_t Steps)
{
    m_28BYJ48.RotateCounterClockwise(Steps);
}

void Robot4e::Pal::Esp32::StepperMotor::SetAngle(std::int16_t Angle)
{
    m_28BYJ48.SetAngle(Angle);
}