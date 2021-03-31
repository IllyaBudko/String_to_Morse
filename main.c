#include "main.h"



int main(void)
{
  uint8_t SOS[] = {"HELLO W O R L D"};
  uint32_t morse_output_buffer[255] = {0};
  TEST_ASCII_string_to_morse_string(SOS,sizeof(SOS),morse_output_buffer,(sizeof(morse_output_buffer) / sizeof(uint32_t)));
  
  uint8_t bit_cnt = 0;
  uint32_t var = 0x1557;
  uint8_t bit_idx = 31;

  while(bit_cnt <= 32)
  {
    if(var & (1 << bit_idx)) //(1 << 31)
    {
      break;
    }
    else
    {
      bit_idx--;
      bit_cnt++;
    }
  }

  while(1);
  
  
}

