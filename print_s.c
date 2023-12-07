#include "main.h"

/**
 * print_s - print string.
 * @my_list: argument.
 * Return: character count.
 */

int print_s(va_list my_list)
{
	int num_chara_print = 0;
	int str_len = 0;
	
	char *str = va_arg(my_list, char*);

	while (str[str_len] != '\0')
		str_len++;

	write(i, str, str_len);
	num_chara_print += str_len;

	return (num_chara_print);
}
