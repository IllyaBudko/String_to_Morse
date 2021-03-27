#include "morse.h"

static void ASCII_string_to_morse_string(uint8_t *ascii_string, uint8_t ascii_string_size, uint32_t *output_buffer, uint8_t output_buffer_size);

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

static void ASCII_string_to_morse_string(uint8_t *ascii_string, uint8_t ascii_string_size, uint32_t *output_buffer, uint8_t output_buffer_size)
{
  uint8_t bit_counter = 32;
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
        uint8_t remainder = 7 - bit_counter;
        bit_counter = 32;
        bit_counter -= remainder;
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
        *output_buffer |= (work_letter.letter_code << bit_counter);
      }
      else
      {
        uint8_t remainder = 0;
        uint32_t partial_letter = 0;
        uint32_t remainder_letter = 0;
        
        //test code from here
        remainder = (work_letter.letter_size - bit_counter);
        partial_letter = (work_letter.letter_code >> remainder);
        *output_buffer |= (partial_letter << 0);
        output_buffer++;
        
        remainder_letter = ((work_letter.letter_code - partial_letter) >> remainder);
        bit_counter = 32;
        bit_counter -= remainder;
        *output_buffer |= (remainder_letter << work_letter.letter_size);
        //to here
      }
      if(bit_counter == 0)
      {
        bit_counter = 32;
      }
      else
      {
        bit_counter--;
      }
    }
    else
    {
      //null terminator detected
      break;
    }
    ascii_string++;
    ascii_string_size--;
  }
}

void TEST_ASCII_string_to_morse_string(uint8_t *ascii_string, uint8_t ascii_string_size, uint32_t *output_buffer, uint8_t output_buffer_size)
{
  ASCII_string_to_morse_string(ascii_string, ascii_string_size, output_buffer, output_buffer_size);
}















