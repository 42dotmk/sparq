///
///@file Types.hpp
///@brief Custom sparq types
///
///
#pragma once

namespace sparqCommon
{
    /// @brief  Electrical state when the user wants to specify what will be low or high, e.g. press of button is low but user wants it to be represented as high
    enum class UserDefinedElectricalState
    {
        ActiveLow = 0,
        ActiveHigh = 1,
    };

    /// @brief Outcome of the check between the raw electrical state and the user defined electrical state
    /// If user wants active high and raw is high, then logical state is active, if user wants active low and raw is low, then logical state is active, otherwise logical is inactive
    enum class LogicalState
    {
        LOW = 0,
        HIGH = 1,
        UNDEFINED = 2,
    };
}
