///
///@file IDigitalInputPin.hpp
///@brief
///
///
#pragma once

#include <cstdint>
#include <Common/Types.hpp>

namespace sparqHal
{
    class IDigitalInputPin
    {
        virtual ~IDigitalInputPin() = default;
        ///
        ///@brief Get the Raw Electrical State object
        ///
        ///@return sparqCommon::RawElectricalState
        virtual sparqCommon::RawElectricalState getRawElectricalState() = 0;
        ///
        ///@brief Get the Pin Number object
        ///
        ///@return std::uint8_t
        virtual std::uint8_t getPinNumber() = 0;
        ///
        ///@brief initialization for ESP-IDF
        ///
        virtual void initialization() = 0;
    };
}
