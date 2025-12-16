# Operating Systems Abstraction Layer CMake
add_library(sparqOsal STATIC
    placeholder.cpp
)

target_include_directories(sparqOsal
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(sparqOsal
    PUBLIC
        sparqHal
)
