#include "GT30L24A3W.h"
#include "stdint.h"
#include "Arduino.h"

#include "SPI.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
SemaphoreHandle_t xSPIlMutex = NULL;///<SPI互斥锁 

unsigned char gt_read_data(unsigned char* sendbuf , unsigned char sendlen , unsigned char* receivebuf, unsigned int receivelen)
{
  unsigned int i;
  xSemaphoreTake(xSPIlMutex, portMAX_DELAY);
  digitalWrite(FONTCS, 1);
  for (i = 0; i < sendlen; i++)
  {
    SPI1.transfer(sendbuf[i]);
  }
  for (i = 0; i < receivelen; i++)
  {
    receivebuf[i] = SPI1.transfer(0x00);
  }
  digitalWrite(FONTCS, 0);
  xSemaphoreGive(xSPIlMutex);
  return 1;
}

unsigned long r_dat_bat(unsigned long address, unsigned long DataLen, unsigned char *pBuff) {
  uint16_t i ;
  xSemaphoreTake(xSPIlMutex, portMAX_DELAY);
  digitalWrite(FONTCS, 1);                     ///<使能器件
  SPI1.transfer(0x03);         ///<发送读取命令
  SPI1.transfer((uint8_t)((address) >> 16)); ///<发送24bit地址
  SPI1.transfer((uint8_t)((address) >> 8));
  SPI1.transfer((uint8_t)address);
  for (i = 0; i < DataLen; i++)
  {
    pBuff[i] = SPI1.transfer(0XFF); ///<循环读数
  }
  digitalWrite(FONTCS, 0);
  xSemaphoreGive(xSPIlMutex);
  return  pBuff[0];
}

int GT_UID_MD5_FLAG = 1;
uint32_t GBCODE_5139;
int GT_Font_Init(void){
  pinMode(FONTCS, OUTPUT);
  SPI1.begin(44,41,42,-1);
  SPI1.setFrequency(20000000);
  return 1;
}

static int Uncompress(unsigned char* result, unsigned char *a2)
{
  for ( uint8_t i = 0; i <= 5u; ++i )
  {
    *(uint8_t *)(result + 4 * i) = a2[3 * i];
    *(uint8_t *)(result + 4 * i + 1) = a2[3 * i + 1] & 0xF0;
    *(uint8_t *)(result + 4 * i + 2) = a2[3 * i + 2];
    *(uint8_t *)(result + 4 * i + 3) = 16 * a2[3 * i + 1];
  }
  return 1;
}

// Function removed as it was unused

unsigned char  ASCII_GetData(unsigned char asc,unsigned long ascii_kind,unsigned char *DZ_Data){
  if ( !GT_UID_MD5_FLAG )
    return 0;
  if ( asc <= 0x1Fu || asc > 0x7Eu )
    return 0;
  switch ( ascii_kind )
  {
    case 1u:
      r_dat_bat(8 * (asc + 259932), 8u, DZ_Data);
      break;
    case 2u:
      r_dat_bat(8 * (asc + 260028), 8u, DZ_Data);
      break;
    case 3u:
      r_dat_bat(12 * asc + 2080864, 0xCu, DZ_Data);
      break;
    case 4u:
      r_dat_bat(26 * asc + 2090144 + 2, 0x18u, DZ_Data);
      break;
    case 5u:
      r_dat_bat(16 * (asc + 130174), 0x10u, DZ_Data);
      break;
    case 6u:
      r_dat_bat(48 * asc + 1543800, 0x30u, DZ_Data);
      break;
    case 7u:
      r_dat_bat(48 * asc + 1549944, 0x30u, DZ_Data);
      break;
    case 8u:
      r_dat_bat(((asc + 67108832) << 6) + 2084832, 0x40u, DZ_Data);
      break;
    case 9u:
      r_dat_bat(34 * asc + 2092384 +2, 0x20u, DZ_Data);
      break;
    case 0xAu:
      r_dat_bat(74 * asc + 1559864 + 2, 0x48u, DZ_Data);
      break;
    case 0xBu:
      r_dat_bat(130 * asc + 2092576, 0x82u, DZ_Data);
      break;
    default:
      return 1;
  }
  return 1;
}


unsigned char ASCII_GetInterval(unsigned char asc,unsigned long ascii_kind){
  unsigned char data[2];
    if ( !GT_UID_MD5_FLAG )
    return 0;
  if ( asc <= 0x1Fu || asc > 0x7Eu )
    return 0;
  switch ( ascii_kind )
  {
    case 1u:
      r_dat_bat(8 * (asc + 259932), 2u, data);
      break;
    case 2u:
      r_dat_bat(8 * (asc + 260028), 2u, data);
      break;
    case 3u:
      r_dat_bat(12 * asc + 2080864, 2u, data);
      break;
    case 4u:
      r_dat_bat(26 * asc + 2090144 , 2u, data);
      break;
    case 5u:
      r_dat_bat(16 * (asc + 130174), 2u, data);
      break;
    case 6u:
      r_dat_bat(48 * asc + 1543800, 2u, data);
      break;
    case 7u:
      r_dat_bat(48 * asc + 1549944, 2u, data);
      break;
    case 8u:
      r_dat_bat(((asc + 67108832) << 6) + 2084832, 2u, data);
      break;
    case 9u:
      r_dat_bat(34 * asc + 2092384, 2u, data);
      break;
    case 0xAu:
      r_dat_bat(74 * asc + 1559864 , 2u, data);
      break;
    case 0xBu:
      r_dat_bat(130 * asc + 2092576, 2u, data);
      break;
    default:
      break;
  }
  return data[1];
}


void gt_12_GetData (unsigned char MSB,unsigned char LSB,unsigned char *DZ_Data){
  unsigned char pBuff[20];
  int offset;
  unsigned int address = 0; // Initialize address to prevent uninitialized use

  offset = 2109216;
  if ( GT_UID_MD5_FLAG )
  {
    if ( MSB != 169 || LSB <= 0xA3u )
    {
      if ( MSB <= 0xA0u || MSB > 0xA3u || LSB <= 0xA0u )
      {
        if ( MSB > 0xAFu && MSB <= 0xF7u && LSB > 0xA0u )
          address = 18 * (94 * MSB + LSB) + offset - 294246;
      }
      else
      {
        address = 18 * (94 * MSB + LSB) + offset - 275310;
      }
    }
    else
    {
      address = 18 * LSB + offset + 2124;
    }
    r_dat_bat(address, 0x12u, pBuff);
    Uncompress(DZ_Data, pBuff);
  }
}


unsigned long GBK_24_GetData (unsigned char c1, unsigned char c2,unsigned char *DZ_Data){
  unsigned char temp; 
  int address;

  temp = c2;
  address = 0;
  if ( !GT_UID_MD5_FLAG )
    return 0;
  if ( c2 == 127 )
    address = 0;
  if ( c1 <= 0xA0u || c1 > 0xA3u || c2 <= 0xA0u )
  {
    if ( c1 != 166 || c2 <= 0xA0u )
    {
      if ( c1 == 169 && c2 > 0xA0u )
        address = 94 * c1 + c2 - 15671;
    }
    else
    {
      address = 94 * c1 + c2 - 15483;
    }
  }
  else
  {
    address = 94 * c1 + c2 - 15295;
  }
  if ( c1 <= 0xAFu || c1 > 0xF7u || c2 <= 0xA0u )
  {
    if ( c1 > 0xA0u || c1 <= 0x80u || c2 <= 0x3Fu )
    {
      if ( c1 > 0xA9u && c2 <= 0xA0u )
      {
        if ( (c2 & 0x80u) != 0 )
          temp = c2 - 1;
        address = 96 * c1 + temp - 3081;
      }
    }
    else
    {
      if ( (c2 & 0x80u) != 0 )
        temp = c2 - 1;
      address = 190 * c1 + temp - 17351;
    }
  }
  else
  {
    address = 94 * c1 + c2 - 16250;
  }
  r_dat_bat(72 * address, 0x48u, DZ_Data);
  return 72 * address;
}


unsigned long  U2G(unsigned int  unicode){
  unsigned char pBuff[2];
  int offset;
  unsigned int address = 0; // Initialize address to prevent uninitialized use

  offset = 2517590;
  if ( !GT_UID_MD5_FLAG )
    return 0;
  if ( unicode > 0x451 || unicode <= 0x9F )
  {
    if ( unicode > 0x2642 || unicode <= 0x200F )
    {
      if ( unicode > 0x33D5 || unicode < 0x3000 )
      {
        if ( unicode > 0x9FA5 || unicode < 0x4E00 )
        {
          if ( unicode > 0xFE6B || unicode <= 0xFE2F )
          {
            if ( unicode > 0xFF5E || unicode <= 0xFF00 )
            {
              if ( unicode > 0xFFE5 || unicode <= 0xFFDF )
              {
                if ( unicode > 0xFA29 || unicode <= 0xF92B )
                {
                  if ( unicode > 0xE864 || unicode <= 0xE815 )
                  {
                    if ( unicode > 0x2ECA || unicode <= 0x2E80 )
                    {
                      if ( unicode > 0x49B7 || unicode <= 0x4946 )
                      {
                        if ( unicode > 0x4DAE || unicode <= 0x4C76 )
                        {
                          if ( unicode > 0x3CE0 || unicode <= 0x3446 )
                          {
                            if ( unicode <= 0x478D && unicode > 0x4054 )
                            {
                              address = 2 * (unicode + 2147467178) + 55380;
                            }
                          }
                          else
                          {
                            address = 2 * (unicode + 2147470265) + 50976;
                          }
                        }
                        else
                        {
                          address = 2 * (unicode + 2147464073) + 50352;
                        }
                      }
                      else
                      {
                        address = 2 * (unicode + 2147464889) + 50126;
                      }
                    }
                    else
                    {
                      address = 2 * (unicode + 2147471743) + 49978;
                    }
                  }
                  else
                  {
                    address = 2 * (unicode + 2147424234) + 49820;
                  }
                }
                else
                {
                  address = 2 * (unicode + 2147419860) + 49312;
                }
              }
              else
              {
                address = 2 * (unicode + 2147418144) + 49142;
              }
            }
            else
            {
              address = 2 * (unicode + 2147418367) + 48954;
            }
          }
          else
          {
            address = 2 * (unicode + 2147418576) + 48834;
          }
        }
        else
        {
          address = 2 * (unicode + 2147463680) + 7030;
        }
      }
      else
      {
        address = 2 * (unicode + 2147471360) + 5066;
      }
    }
    else
    {
      address = 2 * (unicode + 2147475440) + 1892;
    }
  }
  else
  {
    address = 2 * (unicode + 2147483488);
  }
  address += offset;
  r_dat_bat(address, 2u, pBuff);
  return (pBuff[0] << 8) + pBuff[1];
}