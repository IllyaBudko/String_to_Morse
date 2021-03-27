#include "morse.h"

static void ASCII_string_to_morse_string(uint8_t *ascii_string, volatile uint8_t ascii_string_size, uint32_t *output_buffer, uint8_t output_buffer_size);

typedef struct letter_template_t
{
  uint32_t letter_code;
  uint8_t  letter_size;
}morse_letter;

static const morse_letter morse_alphabet[] = 
  {
    {0x00  ,7 },    //SPACE
    {0x17  ,5 },    //A
    {0x1D5 ,9 },    //B
    {0x75D ,11},    //C
    {0x75  ,7 },    //D
    {0x01  ,1 },    //E
    {0x15D ,9 },    //F
    {0x1DD ,9 },    //G
    {0x55  ,7 },    //H
    {0x5   ,3 },    //I
    {0x1777,13},    //J
    {0x1D7 ,9 },    //K
    {0x175 ,9 },    //L
    {0x77  ,7 },    //M
    {0x1D  ,5 },    //N
    {0x777 ,11},    //O
    {0x5DD ,11},    //P
    {0x1DD7,13},    //Q
    {0x5D  ,7 },    //R
    {0x15  ,5 },    //S
    {0x7   ,3 },    //T
    {0x57  ,7 },    //U
    {0x157 ,9 },    //V
    {0x177 ,9 },    //W
    {0x757 ,11},    //X
    {0x1D77,13},    //Y
    {0x775 ,11},    //Z
  };
  
uint32_t morse_output_buffer[256] =  {0};
static void ASCII_string_to_morse_string(uint8_t *ascii_string, volatile uint8_t ascii_string_size, uint32_t *output_buffer, uint8_t output_buffer_size)
{
  uint8_t bit_counter = 31;
  morse_letter work_letter;
  while(sizeof(ascii_string_size) != 0)
  {
    /*statement checks if character is a space*/
    if(*ascii_string == 0x20)
    {
      if(bit_counter > 7)
      {
        bit_counter -= 7;
      }
      else
      {
        uint8_t tmp = 7 - bit_counter;
        bit_counter = 31;
        bit_counter -= tmp;
      }
    }
    /*statement check if character is within range of ascii A to Z*/
    else if(*ascii_string >= 0x41 && *ascii_string < 0x5B)
    {
      uint8_t idx_morse_alphabet = (*ascii_string - 0x40);
      work_letter = morse_alphabet[idx_morse_alphabet];
      if(bit_counter > work_letter.letter_size)
      {
        bit_counter -= work_letter.letter_size;
        *output_buffer |= (work_letter.letter_code << work_letter.letter_size);
      }
      else
      {
        uint8_t tmp = work_letter.letter_size - bit_counter;
        bit_counter = 31;
        bit_counter -= tmp;
      }
    }
    else
    {
      //temorary stuff
      while(1);
    }
    ascii_string++;
    ascii_string_size--;
  }
}

















