/*
 * LCD_interface.h
 *
 * Created: 11/10/2023 3:06:48 AM
 *  Author: mostafa
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void HLCD_vsendData(u8 LCD_DATA);

void HLCD_vShowInt(u16 number);
void HLCD_vsendCommand(u8 LCD_COMMAND);

void HLCD_vInit(void);

void HLCD_vWriteNextChar(void);
void HLCD_vClearDisplay(void);
void HLCD_vShowString(u8 const * const str);
u8 HLCD_u8GotoXY(u8 copy_u8LineNumber, u8 copy_u8Location);

#endif /* LCD_INTERFACE_H_ */