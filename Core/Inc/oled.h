//
// Created by Water_bros on 2025-05-13.
//

#ifndef OLED_H
#define OLED_H

#include "u8g2.h"

#define OLED_ADDRESS 0x78

uint8_t u8x8_byte_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

uint8_t u8x8_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

void u8g2_Init(u8g2_t *u8g2);

//void Show_Text(u8g2_t *u8g2, char *text, uint8_t x, uint8_t y);


#endif //OLED_H
