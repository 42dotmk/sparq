option(SPARQ_ENABLE_ESP32 "Build the sparq ESP32 ESP-IDF component" ON)

if(NOT SPARQ_ENABLE_ESP32)
    return()
endif()

idf_component_register(
    SRCS
        placeholder.cpp
    INCLUDE_DIRS
        .
    REQUIRES
        driver
        esp_system
        freertos
)
