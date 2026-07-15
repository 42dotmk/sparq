#include <PlatformAbstractionLayer/Esp32/DigitalInputPin.hpp>

#include <Common/ErrorCodes.hpp>
#include <Common/Types.hpp>

namespace sparqPal::esp32::gpio
{
    DigitalInputPin::DigitalInputPin(gpio_num_t pinNumber, sparqCommon::UserDefinedElectricalState userDefinedElectricalState)
        : this->pinNumber{pinNumber},
    this->userDefinedElectricalState{userDefinedElectricalState}
    {
    }

    sparqCommon::LogicalState DigitalInputPin::getLogicalState()
    {
        auto rawElectricalState = gpio_get_level(this->pinNumber);

        if ((rawElectricalState && userDefinedElectricalState) || (!rawElectricalState && !userDefinedElectricalState))
        {
            return sparqCommon::LogicalState::Active;
        }
        else
        {
            return sparqCommon::LogicalState::Inactive;
        }
    }
} // namespace sparqPal::esp32::gpio
