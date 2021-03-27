#include "main.h"



int main(void)
{
  uint8_t SOS[] = {"BBBC"};
  uint32_t morse_output_buffer[255] = {0};
  TEST_ASCII_string_to_morse_string(SOS,sizeof(SOS),morse_output_buffer,(sizeof(morse_output_buffer) / sizeof(uint32_t)));
  
  while(1);
  
  
}

