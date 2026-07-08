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

        ///
        ///@brief Get the Raw Electrical State object
        ///
        ///@return sparqCommon::RawElectricalState
        virtual sparqCommon::RawElectricalState getRawElectricalState() = 0;

        ///
        ///@brief Set the Raw Electrical State object
        ///
        ///@return sparqCommon::ErrorCodes
        virtual sparqCommon::ErrorCodes setRawElectricalState(sparqCommon::RawElectricalState) = 0;

        ///
        ///@brief
        ///
        ///@return sparqCommon::ErrorCodes
        virtual sparqCommon::ErrorCodes toggleRawElectricalState() = 0;
    };
}
