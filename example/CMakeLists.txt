add_executable(bno_test main.c)

target_link_libraries(bno_test
    pico_stdlib
    pico_bno055
)

pico_enable_stdio_usb(bno_test 1)
pico_enable_stdio_uart(bno_test 0)

pico_add_extra_outputs(bno_test)    