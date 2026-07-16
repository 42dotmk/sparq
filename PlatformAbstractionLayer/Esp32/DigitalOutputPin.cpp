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

    sparqCommon::ErrorCodes setLogicalState(sparqCommon::LogicalState logicalState)
    {
        if ((logicalState && userDefinedElectricalState) ||
            (!logicalState && !userDefinedElectricalState))
        {
            if (gpio_set_level(this->pinNumber, 1) != ESP_OK)
            {
                return sparqCommon::ErrorCodes::GPIO_SET_LEVEL_FAIL;
            }
            return sparqCommon::ErrorCodes::OK;
        }
        else
        {
            if (gpio_set_level(this->pinNumber, 0) != ESP_OK)
            {
                return sparqCommon::ErrorCodes::GPIO_SET_LEVEL_FAIL;
            }
            return sparqCommon::ErrorCodes::OK;
        }
    }

    sparqCommon::ErrorCodes toggleLogicalState()
    {
        sparqCommon::LogicalState currentState = this->getLogicalState();
        if (currentState == sparqCommon::LogicalState::Inactive)
        {
            this->setLogicalState(sparqCommon::LogicalState::Active);
            return sparqCommon::ErrorCodes::OK;
        }
        else
        {
            this->setLogicalState(sparqCommon::LogicalState::Inactive);
            return sparqCommon::ErrorCodes::OK;
        }
    }
}
