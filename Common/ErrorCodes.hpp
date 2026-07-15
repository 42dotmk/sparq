///
///@file ErrorCodes.hpp
///@brief Custom sparq ErrorCodes for handling different errors
///
///

#pragma once

namespace sparqCommon
{
    ///
    ///@brief Custom error code values
    ///
    enum class ErrorCodes
    {
        ///
        ///@brief No error
        ///
        OK = 0,
        ///
        ///@brief Undefined Electrical level, usually used when you get an illegal (unusable) arguments when setting an electrical state
        ///
        UNDEFINED_ELECTRICAL_LEVEL = 1,

    };
}
