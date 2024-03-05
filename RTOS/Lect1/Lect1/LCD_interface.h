/*
 * LCD_interface.h
 *
 * Created: 11/10/2023 3:06:48 AM
 *  Author: mostafa
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void HLCD_vsendData(u8 LCD_DATA);

void HLCD_vShowInt(u32 number);
void HLCD_vsendCommand(u8 LCD_COMMAND);

void HLCD_vInit(void);

void HLCD_vWriteNextChar(void);
void HLCD_vClearDisplay(void);
void HLCD_vShowString(u8 const * const str);

#endif /* LCD_INTERFACE_H_ */