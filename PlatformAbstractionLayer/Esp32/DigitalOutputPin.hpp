///
///@file DigitalOutputPin.hpp
///@brief ESP32 Implementation header of the HAL Interface IDigitalOutputPin
///

#pragma once

#include <HardwareAbstractionLayer/IDigitalOutputPin.hpp>

#include <Common/ErrorCodes.hpp>
#include <Common/Types.hpp>

#include "driver/gpio.h"

#include <cstdint>

namespace sparqPal::esp32::gpio
{
    class DigitalOutputPin : public sparqHal::IDigitalOutputPin
    {
    public:
        /// @brief Constructor of the ESP32 DigitalOutputPin
        /// @param pinNumber
        /// @param userDefinedElectricalState
        /// @param logicalState
        DigitalOutputPin(gpio_num_t pinNumber, sparqCommon::UserDefinedElectricalState userDefinedElectricalState, sparqCommon::LogicalState logicalState);
        ~DigitalOutputPin() = default;

        sparqCommon::LogicalState getLogicalState() override final;
        sparqCommon::ErrorCodes setLogicalState(sparqCommon::LogicalState) override final;
        sparqCommon::ErrorCodes toggleLogicalState() override final;

    private:
        const gpio_num_t pinNumber;
        const sparqCommon::UserDefinedElectricalState userDefinedElectricalState;
    };
}