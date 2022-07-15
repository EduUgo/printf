#include "main.h"
/**
 * print_bnr - function to print decimal in binary
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index of the buffer pointer
 * Return: number of chars printed
 */
int print_bnr(va_list arguments, char *buf, unsigned int ibuf)
{
        int int_input, count, i, first_input, isNegative;
        char *binary;

        int_input = va_arg(arguments, int);
        isNegative = 0;
        if (int_input == 0)
        {
                ibuf = handl_buf(buf, '0', ibuf);
                return (1);
        }
        if (int_input < 0)
        {
                int_input = (int_input * -1) - 1;
                isNegative = 1;
        }
        binary = malloc(sizeof(char) * (32 + 1));
        binary = fill_binary_array(binary, int_input, isNegative, 32);
        first_input = 0;
        for (count = i = 0; binary[i]; i++)
        {
                if (first_input == 0 && binary[i] == '1')
                        first_input = 1;
                if (first_input == 1)
                {
                        ibuf = handl_buf(buf, binary[i], ibuf);
                        count++;
                }
        }
        free(binary);
        return (count);
}