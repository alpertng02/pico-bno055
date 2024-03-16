#include "pico/stdlib.h"
#include "bno055.h"

#include <stdio.h>

typedef struct bno055_t bno055_t;
typedef struct bno055_accel_float_t bno055_accel_float_t;
typedef struct bno055_euler_float_t bno055_euler_float_t;

int main() {
    
    stdio_init_all();
    sleep_ms(2000);

    const uint sda_pin = 4;
    const uint scl_pin = 5;

    gpio_init(sda_pin);
    gpio_init(scl_pin);
    gpio_set_function(sda_pin, GPIO_FUNC_I2C);
    gpio_set_function(scl_pin, GPIO_FUNC_I2C);
    gpio_pull_up(sda_pin);
    gpio_pull_up(scl_pin);
    i2c_init(i2c_default, 400 * 1000);

    bno055_t bno;
    int8_t res = bno055_pico_init(&bno, i2c_default, BNO055_I2C_ADDR1);
    if (res) {
        res = bno055_pico_init(&bno, i2c_default, BNO055_I2C_ADDR2);
    }
    if (res) {
        printf("BNO055 inilization failed!\n");
    }
    sleep_ms(100);

    res = bno055_set_power_mode(BNO055_POWER_MODE_NORMAL);
    if (res) {
        printf("BNO055 power mode set failed!\n");
    }
    sleep_ms(100);

    res = bno055_set_operation_mode(BNO055_OPERATION_MODE_NDOF);
    if (res) {
        printf("BNO055 operation mode set failed!\n");
    }
    sleep_ms(100);

    while (true) {
        uint8_t calibrationStatus;
        bno055_get_sys_calib_stat(&calibrationStatus);
        printf("Calibration Status: %u\n", calibrationStatus);

        bno055_accel_float_t accelData;
        bno055_convert_float_accel_xyz_msq(&accelData);
        printf("x: %3.2f,   y: %3.2f,   z: %3.2f\n", accelData.x, accelData.y, accelData.z);

        bno055_euler_float_t eulerAngles;
        bno055_convert_float_euler_hpr_deg(&eulerAngles);
        printf("h: %3.2f,   p: %3.2f,   r: %3.2f\n\n", eulerAngles.h, eulerAngles.p, eulerAngles.r);
        sleep_ms(100);
    }

    return 0;
}