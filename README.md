# Raspberry Pi Pico port for Bosch Sensortec BNO-055 driver. 

To add to your project:
- Copy BNO055_driver folder to your project. 
- Add "pico_bno055" to your target_link_libraries in CMake.

Added convenience function: 
- Use bno055_pico_init() to initiliaze the sensor struct so that you don't have to manually set function pointers to i2c functions.