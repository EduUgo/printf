#include "main.h"
/**
 * print_int - function to print integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_int(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_temp, i, div, isNegative;

	int_input = va_arg(arguments, int);
	isNegative = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		isNegative = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}

	return (i + isNegative);
}