# Testing CMake
add_library(sparqTesting STATIC
    placeholder.cpp
)

target_include_directories(sparqTesting
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(sparqTesting
    PRIVATE
        sparqPal
)