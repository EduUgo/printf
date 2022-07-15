#include "main.h"
/**
 * handl_buff - function to concatenate buffer characters
 * @buf: buffer pointer
 * @c: the character argument to concatenate
 * @ibuf: index of the buffer pointer
 * Return: the index of the buffer pointer
 */
unsigned int handl_buf(char *buf, char c, unsigned int ibuf)
{
        if (ibuf == 1024)
        {
                print_buf(buf, ibuf);
                ibuf = 0;
        }
        buf[ibuf] = c;
        ibuf++;
        return (ibuf);
}