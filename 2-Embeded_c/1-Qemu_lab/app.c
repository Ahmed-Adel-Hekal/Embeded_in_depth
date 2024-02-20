#include "uart.h"
unsigned char string_buffer1[100]="learn-in-depth<Ahmed Adel>";
unsigned char const string_buffer2[100]="learn-in-depth<Ahmed Adel>";
void main(void)
{
uart_send_string(string_buffer1);
}