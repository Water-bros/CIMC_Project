//
// Created by Water_bros on 2025-05-13.
//

#ifndef GUI_H
#define GUI_H

#include "oled.h"
#include "math.h"

#define bool uint8_t
#define true 1
#define false 0

void ui_Init(u8g2_t *u8g2);

void animation(float *a, float *a_trg, uint8_t n);

void Window_Pop(u8g2_t *u8g2);

void Draw_Indicator(u8g2_t *u8g2);

void Dark_Mode(u8g2_t *u8g2);

void LED_Output(uint8_t led, uint8_t state);

void List_Show(u8g2_t *u8g2);

void Diagram_Show(u8g2_t *u8g2);

void Tile_Show(u8g2_t *u8g2);

void ADC_Proc(u8g2_t *u8g2);

void LED_Proc(u8g2_t *u8g2);

void RTC_Proc(u8g2_t *u8g2);

void Flash_Proc(u8g2_t *u8g2);

void TF_Proc(u8g2_t *u8g2);

void Info_Proc(u8g2_t *u8g2);

void Setting_Proc(u8g2_t *u8g2);

void Cube_Proc(u8g2_t *u8g2);

void ui_Proc(u8g2_t *u8g2);

void Scan_Key(void);

void Genshin(u8g2_t *u8g2);

#endif //GUI_H
