///
///@file IDigitalInputPin.hpp
///@brief HAL Interface for digital input pin
///
#pragma once

#include <Common/ErrorCodes.hpp>
#include <Common/Types.hpp>

#include <cstdint>

namespace sparqHal
{
    class IDigitalInputPin
    {
        virtual ~IDigitalInputPin() = default;

        ///@brief Get the Logical State from the input pin, checked between the raw and user defined electrical states
        ///@return sparqCommon::LogicalState
        virtual sparqCommon::LogicalState getLogicalState() = 0;

        ///@brief Get the Pin Number
        ///@return std::uint8_t
        virtual std::uint8_t getPinNumber() = 0;

        ///@brief initialization method, where different configs for different platforms can be set
        ///@return sparqCommon::ErrorCodes
        virtual sparqCommon::ErrorCodes initialization() = 0;
    };
}
