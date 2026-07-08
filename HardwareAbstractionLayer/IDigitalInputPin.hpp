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
        virtual sparqCommon::RawElectricalState getRawElectricalState() = 0;
        virtual std::uint8_t getPinNumber() = 0;
        ///
        ///@brief initialization for ESP-IDF
        ///
        virtual void initialization() = 0;
    };
}
