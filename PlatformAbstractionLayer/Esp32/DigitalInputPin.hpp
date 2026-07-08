///
///@file DigitalInputPin.hpp
///@brief ESP Implementation header of the HAL Interface IDigitalInputPin
///
///
#pragma once

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
        sparqCommon::RawElectricalState getRawElectricalState() = 0;
        virtual std::uint8_t getPinNumber() = 0;

        ///
        ///@brief initialization for ESP-IDF
        ///
        virtual void initialization() = 0;
    };
}
