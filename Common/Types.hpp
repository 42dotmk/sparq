
#pragma once

namespace sparqCommon
{
    enum class UserDefinedElectricalState
    {
        ActiveLow = 0,
        ActiveHigh = 1,
    };

    enum class RawElectricalState
    {
        LOW = 0,
        HIGH = 1,
        UNDEFINED = 2,
    };
}
