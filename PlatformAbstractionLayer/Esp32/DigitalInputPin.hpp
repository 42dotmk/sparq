///
///@file DigitalInputPin.hpp
///@brief ESP Implementation header of the HAL Interface IDigitalInputPin
///
///
#pragma once

#include <HardwareAbstractionLayer/IDigitalInputPin.hpp>

#include <Common/ErrorCodes.hpp>
#include <Common/Types.hpp>

#include "driver/gpio.h"

#include <cstdint>

namespace sparqPal::esp32::gpio
{
    class DigitalInputPin : public sparqHal::IDigitalInputPin
    {
    public:
        /// @brief Constructor of the ESP32 DigitalInputPin
        /// @param pinNumber
        /// @param userDefinedElectricalState
        DigitalInputPin(gpio_num_t pinNumber, sparqCommon::UserDefinedElectricalState userDefinedElectricalState);
        /// @brief Default desctructor of DigitalInputPin
        virtual ~DigitalInputPin() = default;

        ///
        ///@brief Get the Raw Electrical State object
        ///
        ///@return sparqCommon::RawElectricalState
        sparqCommon::RawElectricalState getRawElectricalState() = 0;

        ///
        ///@brief Get the Pin Number object
        ///
        ///@return std::uint8_t
        virtual std::uint8_t getPinNumber() = 0;

        ///
        ///@brief initialization for ESP-IDF
        ///
        virtual void initialization() = 0;

    private:
        const gpio_num_t pinNumber;
        const sparqCommon::UserDefinedElectricalState userDefinedElectricalState;
    };
}
