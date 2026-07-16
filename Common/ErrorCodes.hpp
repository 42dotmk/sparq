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
        /// @brief No error
        OK = 0,
        /// @brief Overriden GPIO set level fail error code from platforms
        GPIO_SET_LEVEL_FAIL = 1,
        /// @brief Overriden GPIO config error
        GPIO_CONFIG_ERROR = 2,
    };
}
