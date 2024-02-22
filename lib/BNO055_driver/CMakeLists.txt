add_library(pico_bno055 
    bno055.c bno055.h
)

target_include_directories(pico_bno055
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(pico_bno055
        hardware_gpio
        hardware_i2c
)