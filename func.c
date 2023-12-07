#include "main.h"

/**
 * func - function specifiers.
 * @spec: Conversion specifiers.
 * @my_list: arguments.
 * Return: char count.
 */

int func(char spec_con, va_list my_list)
{
	int i = 0;
	int num_chara_print = 0;

	specifiers_t spec[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_%},
		{'d', print_d},
		{'i', print_digit},
		{'r', print_rev_string},
		{0, NULL}
	};

	while (spec[i].specifiers)
	{
		if (spec_con == spec[i].specifiers)
			num_chara_print += spec[i].f(my_list);
		i++;
	}

	if (num_chara_print == 0)
	{
		num_chara_print += _putchar('%');
		num_chara_print += _putchar(spec_con);
	}

	return (num_chara_print);
}
