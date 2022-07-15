#include "main.h"

/**
 * prinnoct - print a number in octal beggining with zero
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of char(s) printed
 */
int prinnoct(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isNegative, count, first_digit;
	char *octal, *binary;

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
	ibuf = handl_buf(buf, '0', ibuf);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isNegative, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_array(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, octal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count + 1);
}