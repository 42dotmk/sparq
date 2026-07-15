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

    /// @brief Raw electrical state from the pin, e.g. button is pressed and is low and the raw will be low, same for high when a sensor picks up something and activates, undefined is when the pin is not connected and has high impedance
    enum class RawElectricalState
    {
        LOW = 0,
        HIGH = 1,
        UNDEFINED = 2,
    };
}
