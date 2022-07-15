#include "main.h"
#include <stdio.h>
/**
 * print_chr - writes charcater c to stdout
 * @arguments: input character
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: on Success (1)
 */
int print_chr(va_list arguments, char *buf, unsigned int ibuf)
{
        char c;

        c = va_arg(arguments, int);
        handl_buf(buf, c, ibuf);

        return (1);
}