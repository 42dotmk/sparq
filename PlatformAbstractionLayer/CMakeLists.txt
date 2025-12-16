# Platform Abstraction Layer CMake
add_library(sparqPal STATIC
    placeholder.cpp
)

target_include_directories(sparqPal
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(sparqPal
    PUBLIC
        sparqOS
        sparqCommon
)

# ESP32 implementation (ESP-IDF only)
if(ESP_PLATFORM)
    add_subdirectory(Esp32)
endif()
