# Drivers CMake
add_library(sparqDrivers
    STATIC
        placeholder.cpp
)

target_include_directories(sparqDrivers 
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/Drivers>
)

target_link_libraries(sparqDrivers
    PUBLIC 
        sparqHal
)
