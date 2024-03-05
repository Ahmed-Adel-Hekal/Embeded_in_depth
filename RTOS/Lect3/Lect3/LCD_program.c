/*
 * LCD_PROGRAM.c
 *
 * Created: 11/10/2023 3:08:22 AM
 *  Author: mostafa
 */ 
#include "std_types.h"
#include "bit_math.h"
#define F_CPU 16000000ul
#include "util/delay.h"


#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"



void HLCD_vsendData(u8 LCD_DATA){
	
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (LCD_DATA & 0xF0);

	SET_BIT(LCD_CONTROL_PORT, LCD_BS);
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_RW);
	
	SET_BIT(LCD_CONTROL_PORT, LCD_E);
	_delay_ms(1);
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_E);
	
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((LCD_DATA & 0x0F)<<4);
	SET_BIT(LCD_CONTROL_PORT, LCD_BS);
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_RW);
	
	SET_BIT(LCD_CONTROL_PORT, LCD_E);
	_delay_ms(1);
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_E);



}

void HLCD_vShowInt(u16 number)
{
	u8 str[10];
	s8 i = 0;
	if (number != 0)
	{
		for(;number != 0;i++)
		{
			str[i] = '0' + (number % 10) ;
			number = number / 10;
			/*HLCD_vSendData(str[i]);*/
		}
		i--;
		for (int j = 0;j <= i;i--)
		{
			HLCD_vsendData(str[i]);
		}
	}
	else
	{
		HLCD_vsendData('0');
	}
	
}

void HLCD_vsendCommand(u8 LCD_COMMAND){
	
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (LCD_COMMAND & 0xF0);
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_BS);
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_RW);
	
	SET_BIT(LCD_CONTROL_PORT, LCD_E);
	_delay_ms(1);
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_E);
	
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((LCD_COMMAND & 0x0F)<<4);
// 	LCD_DATA_PORT &= 0x0F;
// 	LCD_DATA_PORT |= (LCD_COMMAND && 0x0F) << 4;
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_BS);
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_RW);
	
	SET_BIT(LCD_CONTROL_PORT, LCD_E);
	_delay_ms(1);
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_E);
	
	
}

void HLCD_vWriteNextChar(void){
	HLCD_vsendCommand(0x06);
	_delay_us(40);
	HLCD_vsendCommand(0x0f);
}

void HLCD_vshowString(u8 * chars){
	HLCD_vClearDisplay();
	
	
}

void HLCD_vClearDisplay(void){
	HLCD_vsendCommand(0x01);
	_delay_ms(2);

}
void HLCD_vShowString(u8 const *  str){
	u8 i = 0;
	while(str[i]!=0){
		HLCD_vsendData(str[i]);
		_delay_ms(1);
		i++;
	}
	
}

void HLCD_vInit(void){
	
	DDRB = 0x0f;
	DDRA = 0xf0;
	_delay_ms(40);
	HLCD_vsendCommand(LCD_FUNCTION_SET_COMMAND|LCD_FUNCTION_SET_F_COMMAND);// FUNCtion set
	LCD_FUNCTION_SET_COMMAND_DELAY;
	HLCD_vsendCommand(LCD_RETURN_HOME_COMMAND);
	LCD_RETURN_HOME_COMMAND_DELAY;
 	HLCD_vsendCommand(LCD_ENTRY_MODE_COMMAND|LCD_ENTRY_MODE_ID_CURSOR_COMMAND);
	LCD_ENTRY_MODE_COMMAND_DELAY;
	HLCD_vsendCommand(LCD_DISPLAY_ON_OFF_CONTROL_COMMAND|LCD_DISPLAY_ON_OFF_CONTROL_D_COMMAND|LCD_DISPLAY_ON_OFF_CONTROL_C_COMMAND|LCD_DISPLAY_ON_OFF_CONTROL_B_COMMAND);
	HLCD_vsendCommand(LCD_CURSOR_DISPLAY_SHIFT_COMMAND|LCD_CURSOR_DISPLAY_SHIFT_RL_COMMAND);
	LCD_CURSOR_DISPLAY_SHIFT_COMMAND_DELAY;
	HLCD_vsendCommand(LCD_CLEAR_DISPLAY_COMMAND);
	LCD_CLEAR_DISPLAY_COMMAND_DELAY;
	
	
}



u8 HLCD_u8GotoXY(u8 copy_u8LineNumber, u8 copy_u8Location){
    /*Function Args : copy_u8LineNumber --> line to print on options LCD_u8LINE1 or LCD_u8LINE1 
                      copy_u8Location   --> choose cursor position from 1 to 40 
             return : Error state
        description : This Function change Cursor position between line1 and line2 
                      and 40 characters position 
    */
    u8 local_error = STD_Sucesses; 

    if(copy_u8Location <= 40){
        switch (copy_u8LineNumber)
        {
        case LCD_u8LINE1: HLCD_vsendCommand(0x80+(copy_u8Location-1));break;
        case LCD_u8LINE2: HLCD_vsendCommand(0xc0+(copy_u8Location-1));break;
        default: local_error = STD_Error;
        }
    }
    else{
        local_error = STD_Error;
    }
    return local_error ; 
}




