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

    std::uint8_t DigitalInputPin::getPinNumber()
    {
        return static_cast<std::uint8_t>(this->pinNumber);
    }

    sparqCommon::ErrorCodes DigitalInputPin::initialization()
    {
        gpio_config_t config = {};

        config.pin_bit_mask = BIT(this->pinNumber);
        config.mode = GPIO_MODE_INPUT;
        config.intr_type = GPIO_INTR_DISABLE;

        auto gpioConfigError = gpio_config(&config);

        if (gpioConfigError != ESP_OK)
        {
            return sparqCommon::ErrorCodes::GPIO_CONFIG_ERROR;
        }
    }
} // namespace sparqPal::esp32::gpio
