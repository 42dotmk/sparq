# Drivers CMake
add_library(sparqDrivers
    STATIC
        placeholder.cpp
)

target_include_directories(sparqDrivers 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(sparqDrivers
    PUBLIC 
        sparqHal
)
