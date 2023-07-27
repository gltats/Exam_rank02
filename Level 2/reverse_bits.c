// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0010  0110
// 	 ||
// 	 \/
//  0110  0100
#include <stdio.h>
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
   int i = 8;
   unsigned char res = 0;

   while(i > 0)
   {
       res = res * 2 + (octet % 2);
       octet = octet / 2;
       i--;
   }
   return(res);
}

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int main() 
{
    unsigned char num = 64;
	print_bits(num);
    printf("\n");

    unsigned char reversed_num = reverse_bits(num);
	print_bits(reversed_num);
	printf("\n");

    return 0;
}