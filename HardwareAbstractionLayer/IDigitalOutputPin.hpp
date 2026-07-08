///
///@file IDigitalOutputPin.hpp
///@brief HAL Interface for digital output pin
///

#pragma once

#include <Common/ErrorCodes.hpp>
#include <Common/Types.hpp>

namespace sparqHal
{
    class IDigitalOutputPin
    {
    public:
        virtual ~IDigitalOutputPin() = default;

        virtual sparqCommon::RawElectricalState getRawElectricalState() = 0;
        virtual sparqCommon::ErrorCodes setRawElectricalState(sparqCommon::RawElectricalState) = 0;
        virtual sparqCommon::ErrorCodes toggleRawElectricalState() = 0;
    };
}
