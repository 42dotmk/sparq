add_library(HalLib INTERFACE)

target_include_directories(HalLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(HalLib PROPERTIES LINKER_LANGUAGE CXX)
