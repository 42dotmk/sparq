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

        /// @brief Get the logical state of the pin(Active / Inactive) checked between the raw electrical state and the user defined electrical state
        ///@return sparqCommon::LogicalState
        virtual sparqCommon::LogicalState getLogicalState() = 0;

        /// @brief Set the logical state of the pin (Active / Inactive) checked between the raw electrical state and the user defined electrical state
        ///@return sparqCommon::ErrorCodes
        virtual sparqCommon::ErrorCodes setLogicalState(sparqCommon::LogicalState) = 0;

        /// @brief Toggle between logical states (Active / Inactive)
        /// @return sparqCommon::ErrorCodes
        virtual sparqCommon::ErrorCodes toggleLogicalState() = 0;
    };
}
