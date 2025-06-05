//
// Created by Water_bros on 2025-05-12.
//
#include "gd25q40e.h"

uint16_t GD25Q40_Read_ID(void) {
    uint8_t buffer[2];
    uint16_t id = 0;
    uint8_t Read_Unique_ID[4] = {0x90, 0x00, 0x00, 0x00};

    GD25Q40_CS_LOW();

    HAL_SPI_Transmit(&hspi2, Read_Unique_ID, 4, GD25Q40_TIMEOUT_VALUE);
    HAL_SPI_Receive(&hspi2, buffer, 2, GD25Q40_TIMEOUT_VALUE);
    id = buffer[0] << 8 | buffer[1];

    GD25Q40_CS_HIGH();

    return id;
}

void GD25Q40_Write_Enable(void) {
    uint8_t cmd = WriteEnable;

    GD25Q40_CS_LOW();

    HAL_SPI_Transmit(&hspi2, &cmd, 1, GD25Q40_TIMEOUT_VALUE);

    GD25Q40_CS_HIGH();
}

void GD25Q40_Wait_Busy(void) {
    uint8_t wait_byte = 0,
            cmd = Read_Status_Register_1;
    GD25Q40_CS_LOW();
    do {
        HAL_SPI_Transmit(&hspi2, &cmd, 1, GD25Q40_TIMEOUT_VALUE);
        HAL_SPI_Receive(&hspi2, &wait_byte, 1, GD25Q40_TIMEOUT_VALUE);
    } while ((wait_byte & 0x01) == 1);
    GD25Q40_CS_HIGH();
}

void GD25Q40_Erase_Sector(uint32_t SectorAddr) {
    uint8_t cmd[4];
    SectorAddr *= 4096;
    cmd[0] = Sector_Erase_4KB;
    cmd[1] = (uint8_t) (SectorAddr >> 16);
    cmd[2] = (uint8_t) (SectorAddr >> 8);
    cmd[3] = (uint8_t) (SectorAddr);

    GD25Q40_Write_Enable();
    GD25Q40_Wait_Busy();

    GD25Q40_CS_LOW();

    HAL_SPI_Transmit(&hspi2, cmd, 4, GD25Q40_TIMEOUT_VALUE);

    GD25Q40_CS_HIGH();

    GD25Q40_Wait_Busy();
}

void GD25Q40_Write_Page(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite) {
    uint8_t cmd = 0x02,
            addr[3] = {(WriteAddr >> 16) & 0xFF, (WriteAddr >> 8) & 0xFF, WriteAddr & 0xFF};

    GD25Q40_Erase_Sector(WriteAddr / 4096);
    GD25Q40_Wait_Busy();
    GD25Q40_Write_Enable();

    GD25Q40_CS_LOW();

    HAL_SPI_Transmit(&hspi2, &cmd, 1, GD25Q40_TIMEOUT_VALUE);
    HAL_SPI_Transmit(&hspi2, addr, 3, GD25Q40_TIMEOUT_VALUE);
    HAL_SPI_Transmit(&hspi2, pBuffer, NumByteToWrite, GD25Q40_TIMEOUT_VALUE);

    GD25Q40_Wait_Busy();

    GD25Q40_CS_HIGH();
}

void GD25Q40_Read(uint8_t *pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead) {
    uint8_t cmd = 0x03,
            addr[3] = {(ReadAddr >> 16) & 0xFF, (ReadAddr >> 8) & 0xFF, ReadAddr & 0xFF};

    GD25Q40_CS_LOW();

    HAL_SPI_Transmit(&hspi2, &cmd, 1, GD25Q40_TIMEOUT_VALUE);
    HAL_SPI_Transmit(&hspi2, addr, 3, GD25Q40_TIMEOUT_VALUE);

    HAL_SPI_Receive(&hspi2, pBuffer, NumByteToRead, GD25Q40_TIMEOUT_VALUE);

    GD25Q40_CS_HIGH();
}