#include "morse.h"

typedef struct letter_template_t
{
  uint32_t letter_code;
  uint8_t  letter_size;
}morse_letter;

morse_letter morse_alphabet[] = 
  {
    {0x17,5},       //A
    {0x1D5,9},      //B
    {0x75D,11},     //C
    {0x75,7},       //D
    {0x01,1},       //E
    {0x15D,9},      //F
    {0x1DD,9},      //G
    {},
    {},
    {},
    {},
    {},
  };