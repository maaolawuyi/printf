#include "main.h"

/**
 * print_char - print char
 * @args: argument.
 * Return: count of chars.
 */

int print_c(va_list my_list)
{
	int num_chara_print = 0;
	char c = va_arg(my_list, int);

	write(1, &c, 1);

	num_chara_print++;

	return (num_chara_print);
}
