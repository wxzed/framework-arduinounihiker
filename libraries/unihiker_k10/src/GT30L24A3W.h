
#ifndef _GT30L24A3W_H_
#define _GT30L24A3W_H_


#define ASCII_5X7              1
#define ASCII_7X8              2
#define ASCII_6X12             3
#define ASCII_12_A 	           4 //12 * 16
#define ASCII_8X16             5
#define ASCII_12X24_A          6
#define ASCII_12X24_P          7
#define ASCII_16X32            8
#define ASCII_16_A             9
#define ASCII_24_B            10
#define ASCII_32_B            11


#define FONTCS 40

extern unsigned long r_dat_bat(unsigned long address,unsigned long DataLen,unsigned char *pBuff);
extern unsigned char gt_read_data(unsigned char* sendbuf , unsigned char sendlen , unsigned char* receivebuf, unsigned int receivelen);

/* ----------------------------------------------------------- */
int GT_Font_Init(void);
/* ----------------------------------------------------------- */

unsigned char  ASCII_GetData(unsigned char asc,unsigned long ascii_kind,unsigned char *DZ_Data);
void gt_12_GetData (unsigned char MSB,unsigned char LSB,unsigned char *DZ_Data);
unsigned long GBK_24_GetData (unsigned char c1, unsigned char c2,unsigned char *DZ_Data) ;
unsigned long  U2G(unsigned int  unicode);
unsigned char ASCII_GetInterval(unsigned char asc,unsigned long ascii_kind);///<获取字符间距
#endif
