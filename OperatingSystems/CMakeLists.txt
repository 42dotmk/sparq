# Operating Systems CMake
add_library(sparqOS STATIC
    placeholder.cpp
)

target_include_directories(sparqOS
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(sparqOS
    PUBLIC
        sparqOsal
)
