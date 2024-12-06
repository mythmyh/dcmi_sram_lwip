#include "stm32f4xx_hal.h"
#ifndef _OV2640_H
#define _OV2640_H

//for not open-drain bus
/*
 * SIOC: PB0
 * SIOD: PB1
 * VSYNC: PB7
 * HREF: PA4
 * PCLK: PA6
 * XCLK: PA8  //24MHz, optional to use
 * D7: PC6
 * D6: PC7
 * D5: PE0
 * D4: PE1
 * D3: PE4
 * D2: PB6
 * D1: PE5
 * D0: PE6
 * RESET: PD10
 * PWDN: PD11
 *
 *
 *
 * SIOC: PD6
 * SIOD: PD7
 * VSYNC: PB7
 * HREF: PA4
 * PCLK: PA6
 * XCLK: PA8  //24MHz, optional to use
 * D7: PE6
 * D6: PE5
 * D5: PB6
 * D4: PC11
 * D3: PC9
 * D2: PC8
 * D1: PC7
 * D0: PC6
 * RESET: PG15
 * PWDN: PD3
 *
 *
 */
#define SCCB_SCL_L    		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET)
#define SCCB_SCL_H    		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET)
#define SCCB_SDA_L    		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_RESET)
#define SCCB_SDA_H    		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET)

#define SCCB_READ_SDA    	HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_7)
#define SCCB_ID_W   	    0X60  			//OV2640 ID for Write
#define SCCB_ID_R   	    0X61  			//OV2640 ID for Read

#define OV2640_PWDN           HAL_GPIO_WritePin(GPIOD,GPIO_PIN_3,GPIO_PIN_SET)
#define OV2640_PWUP           HAL_GPIO_WritePin(GPIOD,GPIO_PIN_3,GPIO_PIN_RESET)
#define OV2640_RST  	      HAL_GPIO_WritePin(GPIOG,GPIO_PIN_15,GPIO_PIN_RESET)
#define OV2640_RUN  	      HAL_GPIO_WritePin(GPIOG,GPIO_PIN_15,GPIO_PIN_SET)
#define OV2640_VSYNC 	      HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7)
#define OV2640_HREF  	      HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)
#define OV2640_PCLK  	      HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)


#define OV2640_MID				0X7FA2
#define OV2640_PID				0X2642


#define OV2640_DSP_R_BYPASS     0x05
#define OV2640_DSP_Qs           0x44
#define OV2640_DSP_CTRL         0x50
#define OV2640_DSP_HSIZE1       0x51
#define OV2640_DSP_VSIZE1       0x52
#define OV2640_DSP_XOFFL        0x53
#define OV2640_DSP_YOFFL        0x54
#define OV2640_DSP_VHYX         0x55
#define OV2640_DSP_DPRP         0x56
#define OV2640_DSP_TEST         0x57
#define OV2640_DSP_ZMOW         0x5A
#define OV2640_DSP_ZMOH         0x5B
#define OV2640_DSP_ZMHH         0x5C
#define OV2640_DSP_BPADDR       0x7C
#define OV2640_DSP_BPDATA       0x7D
#define OV2640_DSP_CTRL2        0x86
#define OV2640_DSP_CTRL3        0x87
#define OV2640_DSP_SIZEL        0x8C
#define OV2640_DSP_HSIZE2       0xC0
#define OV2640_DSP_VSIZE2       0xC1
#define OV2640_DSP_CTRL0        0xC2
#define OV2640_DSP_CTRL1        0xC3
#define OV2640_DSP_R_DVP_SP     0xD3
#define OV2640_DSP_IMAGE_MODE   0xDA
#define OV2640_DSP_RESET        0xE0
#define OV2640_DSP_MS_SP        0xF0
#define OV2640_DSP_SS_ID        0x7F
#define OV2640_DSP_SS_CTRL      0xF8
#define OV2640_DSP_MC_BIST      0xF9
#define OV2640_DSP_MC_AL        0xFA
#define OV2640_DSP_MC_AH        0xFB
#define OV2640_DSP_MC_D         0xFC
#define OV2640_DSP_P_STATUS     0xFE
#define OV2640_DSP_RA_DLMT      0xFF

//当选择传感器地址(0XFF=0X01)时,OV2640的DSP寄存器地址映射表
#define OV2640_SENSOR_GAIN       0x00
#define OV2640_SENSOR_COM1       0x03
#define OV2640_SENSOR_REG04      0x04
#define OV2640_SENSOR_REG08      0x08
#define OV2640_SENSOR_COM2       0x09
#define OV2640_SENSOR_PIDH       0x0A
#define OV2640_SENSOR_PIDL       0x0B
#define OV2640_SENSOR_COM3       0x0C
#define OV2640_SENSOR_COM4       0x0D
#define OV2640_SENSOR_AEC        0x10
#define OV2640_SENSOR_CLKRC      0x11
#define OV2640_SENSOR_COM7       0x12
#define OV2640_SENSOR_COM8       0x13
#define OV2640_SENSOR_COM9       0x14
#define OV2640_SENSOR_COM10      0x15
#define OV2640_SENSOR_HREFST     0x17
#define OV2640_SENSOR_HREFEND    0x18
#define OV2640_SENSOR_VSTART     0x19
#define OV2640_SENSOR_VEND       0x1A
#define OV2640_SENSOR_MIDH       0x1C
#define OV2640_SENSOR_MIDL       0x1D
#define OV2640_SENSOR_AEW        0x24
#define OV2640_SENSOR_AEB        0x25
#define OV2640_SENSOR_W          0x26
#define OV2640_SENSOR_REG2A      0x2A
#define OV2640_SENSOR_FRARL      0x2B
#define OV2640_SENSOR_ADDVSL     0x2D
#define OV2640_SENSOR_ADDVHS     0x2E
#define OV2640_SENSOR_YAVG       0x2F
#define OV2640_SENSOR_REG32      0x32
#define OV2640_SENSOR_ARCOM2     0x34
#define OV2640_SENSOR_REG45      0x45
#define OV2640_SENSOR_FLL        0x46
#define OV2640_SENSOR_FLH        0x47
#define OV2640_SENSOR_COM19      0x48
#define OV2640_SENSOR_ZOOMS      0x49
#define OV2640_SENSOR_COM22      0x4B
#define OV2640_SENSOR_COM25      0x4E
#define OV2640_SENSOR_BD50       0x4F
#define OV2640_SENSOR_BD60       0x50
#define OV2640_SENSOR_REG5D      0x5D
#define OV2640_SENSOR_REG5E      0x5E
#define OV2640_SENSOR_REG5F      0x5F
#define OV2640_SENSOR_REG60      0x60
#define OV2640_SENSOR_HISTO_LOW  0x61
#define OV2640_SENSOR_HISTO_HIGH 0x62





void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
uint8_t SCCB_WR_Byte(uint8_t data);
uint8_t SCCB_RD_Byte(void);
uint8_t SCCB_WR_Reg(uint8_t reg,uint8_t data);
uint8_t SCCB_RD_Reg(uint8_t reg);
uint32_t tickdelay;

void SCCB_SDA_IN(void);
void SCCB_SDA_OUT(void);

#define ticknumber 12*10

void SCCB_Rst(void);

typedef enum
{
  BMP_QQVGA             =   0x00,	    /* BMP Image QQVGA 160x120 Size */
  BMP_QVGA              =   0x01,           /* BMP Image QVGA 320x240 Size */
  JPEG_160x120          =   0x02,	    /* JPEG Image 160x120 Size */
  JPEG_176x144          =   0x03,	    /* JPEG Image 176x144 Size */
  JPEG_320x240          =   0x04,	    /* JPEG Image 320x240 Size */
  JPEG_352x288          =   0x05,	    /* JPEG Image 352x288 Size */
  JPEG_800x600			=   0x06
}ImageFormat_TypeDef;
/***********************************/
void OV2640_Auto_Exposure(uint8_t level);
void OV2640_Light_Mode(uint8_t mode);
void OV2640_Color_Saturation(uint8_t sat);
void OV2640_Brightness(uint8_t bright);
void OV2640_Contrast(uint8_t contrast);
void OV2640_Special_Effects(uint8_t eft);
void OV2640_Color_Bar(uint8_t sw);
void OV2640_Window_Set(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);
uint8_t OV2640_OutSize_Set(uint16_t width,uint16_t height);
uint8_t OV2640_ImageWin_Set(uint16_t offx,uint16_t offy,uint16_t width,uint16_t height);
uint8_t OV2640_ImageSize_Set(uint16_t width,uint16_t height);
void OV2640_RGB565_Mode(void);
void OV2640_JPEG_Mode(void);
void OV2640_SVGA_Init(void);
uint8_t OV2640_Init(void);
void OV2640_UXGA_Init(void);
void OV2640_JPEGConfig(ImageFormat_TypeDef ImageFormat);
   
#endif
