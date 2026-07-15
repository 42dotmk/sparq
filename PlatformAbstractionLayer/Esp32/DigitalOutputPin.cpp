#include <PlatformAbstractionLayer/Esp32/DigitalOutputPin.hpp>

#include <Common/ErrorCodes.hpp>
#include <Common/Types.hpp>

namespace sparqPal::esp32::gpio
{
    DigitalOutputPin(gpio_num_t pinNumber, sparqCommon::UserDefinedElectricalState userDefinedElectricalState, sparqCommon::LogicalState logicalState)
        : this->pinNumber{pinNumber},
    this->userDefinedElectricalState{userDefinedElectricalState},
    {
        gpio_reset_pin(this->pinNumber);
        gpio_set_direction(this->pinNumber, GPIO_INPUT_OUTPUT);
        this->setLogicalState(logicalState);
    }

    sparqCommon::LogicalState getLogicalState()
    {
        auto rawElectricalState = gpio_get_level(this->pinNumber);

        if ((rawElectricalState && userDefinedElectricalState) ||
            (!rawElectricalState && !userDefinedElectricalState))
        {
            return sparqCommon::LogicalState::Active;
        }
        else
        {
            return sparqCommon::LogicalState::Inactive;
        }
    }

    sparqCommon::ErrorCodes setRawElectricalState(sparqCommon::RawElectricalState rawElectricalState)
    {
        auto rawElectricalLevelHigh = rawElectricalState == sparqCommon::RawElectricalState::HIGH ? 1 : 0;
        auto userDefinedElectricalLevelHigh = this->userDefinedElectricalState == sparqCommon::UserDefinedElectricalState::ActiveHigh ? 1 : 0;

        if ((rawElectricalLevelHigh && userDefinedElectricalStateHigh) ||
            (!rawElectricalLevelHigh && !userDefinedElectricalStateHigh))
        {
            gpio_set_level(this->pinNumber, LOGIC_HIGH);
            return sparqCommon::ErrorCodes::OK;
        }
        else if ((rawElectricalLevelHigh && !userDefinedElectricalStateHigh) ||
                 (!rawElectricalLevelHigh && userDefinedElectricalStateHigh))
        {
            gpio_set_level(this->pinNumber, LOGIC_LOW);
            return sparqCommon::ErrorCodes::OK;
        }
        else
        {
            return sparqCommon::ErrorCodes::UNDEFINED_ELECTRICAL_LEVEL;
        }
    }

    sparqCommon::ErrorCodes toggleLogicalState()
    {
        sparqCommon::LogicalState currentState = this->getLogicalState();
        if (currentState == sparqCommon::LogicalState::Inactive)
        {
            this->setRawElectricalState(sparqCommon::RawElectricalState::HIGH);
            return sparqCommon::ErrorCodes::OK;
        }
        else if (currentState == sparqCommon::RawElectricalState::HIGH)
        {
            this->setRawElectricalState(sparqCommon::RawElectricalState::LOW);
            return sparqCommon::ErrorCodes::OK;
        }
        else
        {
            this->setRawElectricalState(sparqCommon::RawElectricalState::UNDEFINED);
            return sparqCommon::ErrorCodes::UNDEFINED_ELECTRICAL_LEVEL;
        }
    }
}
