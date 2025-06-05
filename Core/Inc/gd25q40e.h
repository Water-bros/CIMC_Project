#ifndef GD25Q40E_H
#define GD25Q40E_H

#include "stm32f4xx.h"
#include "spi.h"

#define    WriteEnable                           0x06
#define    WriteDisable                          0x04
#define    Read_Status_Register_1                0x05
#define    Read_Status_Register_2                0x35
#define    Write_Status_Register                 0x01
#define    Page_Program                          0x02
#define    Quad_Page_Program                     0x32
#define    Block_Erase_64KB                      0xD8
#define    Block_Erase_32KB                      0x52
#define    Sector_Erase_4KB                      0x20
#define    Chip_Erase                            0xC7
#define    Erase_Suspend                         0x75
#define    Erase_Resume                          0x7A
#define    Power_down                            0xB9
#define    High_Performance_Mode                 0xA3
#define    Continuous_Read_ModeReset             0xFF
#define    Release_Power_down                    0xAB
#define    HPM_OR_Device_ID                      0xAB
#define    Manufacturer_OR_Device_ID             0x90
#define    JEDEC_ID                              0x9F

#define    Read_Data                             0x03
#define    Fast_Read                             0x0B
#define    Fast_Read_Dual_Output                 0x3B
#define    Fast_Read_Dual_I_O                    0xBB
#define    Fast_Read_Quad_Output                 0x6B
#define    Fast_Read_Quad_I_O                    0xEB
#define    Octal_Word Read_Quad_I_O              0xE3

#define    Dummy_Byte                            0xFF
/**************************************************************/



#define GD25Q40_OK            ((uint8_t)0x00)
#define GD25Q40_ERROR         ((uint8_t)0x01)
#define GD25Q40_BUSY          ((uint8_t)0x02)
#define GD25Q40_TIMEOUT                ((uint8_t)0x03)


/* Flag Status Register */
//#define W25Q128FV_FSR_BUSY                    ((uint8_t)0x01)    /*!< busy */
//#define W25Q128FV_FSR_WREN                    ((uint8_t)0x02)    /*!< write enable */
//#define W25Q128FV_FSR_QE                      ((uint8_t)0x02)    /*!< quad enable */


#define GD25Q40_CS_GPIO_Port        FLASH_CS_GPIO_Port
#define GD25Q40_CS_Pin              FLASH_CS_Pin

#define GD25Q40_CS_LOW()            HAL_GPIO_WritePin(GD25Q40_CS_GPIO_Port, GD25Q40_CS_Pin, GPIO_PIN_RESET)
#define GD25Q40_CS_HIGH()           HAL_GPIO_WritePin(GD25Q40_CS_GPIO_Port, GD25Q40_CS_Pin, GPIO_PIN_SET)

#define GD25Q40_TIMEOUT_VALUE            1000
#define PageSize                        256


uint16_t GD25Q40_Read_ID(void);

void GD25Q40_Write_Enable(void);

void GD25Q40_Wait_Busy(void);

void GD25Q40_Erase_Sector(uint32_t SectorAddr);

void GD25Q40_Write_Page(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);

void GD25Q40_Read(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);

#endif


